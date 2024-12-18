#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QContextMenuEvent>
#include <QTreeView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QPainter>
#include <QStyleOptionButton>
#include <QStylePainter>
#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QBrush>
#include <QColor>
#include <iostream>
#include <QMap>
#include "xlsxdocument.h"
#include "xlsxformat.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    iniUI();
    setupNodeView();
    connect(ui->treeWidget, &QTreeWidget::itemClicked, this, &MainWindow::onTreeWidgetItemClicked);
}


void MainWindow::iniUI(){
    fLabCurFile = new QLabel;
    fLabCurFile->setMinimumWidth(150);
    fLabCurFile->setText("当前文件：");
    ui->statusbar->addWidget(fLabCurFile);

    progressBar1=new QProgressBar;
    progressBar1->setMaximumWidth(200);
    progressBar1->setMaximum(50);
    progressBar1->setMinimum(5);
    ui->statusbar->addWidget(progressBar1);

    spinFontSize=new QSpinBox;
    spinFontSize->setMaximum(50);
    spinFontSize->setMinimum(5);
    //spinFontSize->setValue(ui->txtEdit->font().pointSize());
    spinFontSize->setMinimumWidth(50);

    ui->toolBar->addWidget(new QLabel("字体大小"));
    ui->toolBar->addWidget(spinFontSize);

    ui->toolBar->addSeparator();
    ui->toolBar->addWidget(new QLabel("字体"));
    comboFont= new QFontComboBox;
    comboFont->setMinimumWidth(150);
    ui->toolBar->addWidget(comboFont);

}

void MainWindow::onTreeWidgetItemClicked(QTreeWidgetItem *item, int column)
{
    QString itemText = item->text(column);

    // 根据点击的 treeWidget 项切换 stackedWidget 页面
    if (itemText == "指标体系设计") {
        ui->stackedWidget->setCurrentWidget(ui->index_page);
    } else if (itemText == "权重体系设计") {
        ui->stackedWidget->setCurrentWidget(ui->weight_page);
    } else if (itemText == "算法体系设计") {
        ui->stackedWidget->setCurrentWidget(ui->algorithm_page);
    }
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::setupNodeView() {
    // 创建场景
    scene = new QGraphicsScene(this);

    // 初始化 view 并将其设置为 widget_2 的子控件
    view = new QGraphicsView(scene, ui->widget_2);
    QGraphicsView *zhuan_view,*cen_view;
    zhuan_view = new QGraphicsView(scene,ui->zhuan_tree_display);
    cen_view = new QGraphicsView(scene,ui->cen_tree_display);
    QVBoxLayout *zhuan_layout = new QVBoxLayout(ui->zhuan_tree_display);
    zhuan_layout->addWidget(zhuan_view);
    QVBoxLayout *cen_layout = new QVBoxLayout(ui->cen_tree_display);
    cen_layout->addWidget(cen_view);
    view->setRenderHint(QPainter::Antialiasing);
    view->setContextMenuPolicy(Qt::DefaultContextMenu);

    view->setDragMode(QGraphicsView::NoDrag);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // 设置 view 的初始几何位置
    view->setGeometry(5, 5, ui->widget_2->width()-10, ui->widget_2->height()-10);
    root = new Node("****任务效能", scene, nullptr,this);
    Node* child1= new Node(scene,root,this);
    Node* child2= new Node(scene,root,this);
    Node* child3= new Node(scene,child1,this);
    Node* child4= new Node(scene,child2,this);
    Node* child5= new Node(scene,root,this);




}


void MainWindow::on_zhuan_pushButton_clicked()
{
    ui->weight_stack->setCurrentIndex(0);
}


void MainWindow::on_cen_pushButton_clicked()
{
    ui->weight_stack->setCurrentIndex(1);
}

void MainWindow::clearSceneExceptRoot(Node* root) {
    if (!scene) return;  // 检查 scene 是否为空

    // 遍历场景中的所有项
    for (QGraphicsItem* item : scene->items()) {
        // 如果 item 不是 root，就将其从场景中移除
        if (item != root) {
            scene->removeItem(item);
            delete item;  // 删除 item 以释放内存
        }
    }
    root->children.clear();
}



void MainWindow::on_pushButton_clicked()
{
    int layers = ui->spinBox->value();
    int nodesPerLayer = ui->spinBox_2->value();

    // 清空场景中除 root 以外的所有节点
    clearSceneExceptRoot(root);
    // 调用函数在现有场景中添加新的节点层级结构
    createLayeredStructure( layers, nodesPerLayer);
}



void MainWindow::createLayeredStructure(int layers, int nodesPerLayer, Node* parent , int currentLayer ) {
    // 如果到达了最大层数，则停止
    if (currentLayer > layers) return;

    // 如果是初始调用，没有传入父节点，则使用根节点
    if (parent == nullptr) {
        parent = root;
    }

    // 为当前层的每个节点生成 nodesPerLayer 个子节点
    for (int i = 0; i < nodesPerLayer; ++i) {
        // 创建新的节点，父节点为传入的 parent
        Node* childNode = new Node(scene, parent,this);


        // 递归调用，为每个子节点生成下一层的子节点
        createLayeredStructure(layers, nodesPerLayer, childNode, currentLayer + 1);
    }
}

//读入对应的excel并展示在stackwidget中
void readExcel(QXlsx::Document &xlsx, Node* node){
    int row,col;
    if(node->children.isEmpty()){
        return;
    }
    for(Node* child:node->children){
        row = child->y/y_gap+1;
        col = child->x/x_gap+2;
        child->weight= xlsx.read(row,col).toDouble();
        qInfo() << child->weight;
        readExcel(xlsx,child);
    }
    return;
}

void weightNormalization(Node* node){
    int total=0;
    if(!node->children.isEmpty()){
        for(Node* child:node->children){
            total+=child->weight;
        }
        for(Node* child:node->children){
            child->weight/=total;
            child->weight*=100;
            qInfo() <<child->weight;
            weightNormalization(child);
        }
    }
    return;
}

void setupTreeWidget(QTreeWidgetItem* treeItem,Node* node) {
    if(!node->children.isEmpty()){
        for(Node* child:node->children){
                QTreeWidgetItem *item = new QTreeWidgetItem(treeItem);
                item->setText(0, child->name);
                item->setText(1, QString::number(child->weight)+"%");
                setupTreeWidget(item,child);
            }

    }

    return;
}

// 设置条形背景长度
void setBarStyle(QTreeWidgetItem *item, int level) {
    // 根据层次调整颜色深度
    QColor color = QColor(100 + level * 20, 150, 255 - level * 30);
    item->setBackground(0, QBrush(color));
}

// 应用到节点
void applyBarStyle(QTreeWidgetItem *item, int level) {
    setBarStyle(item, level);
    for (int i = 0; i < item->childCount(); ++i) {
        applyBarStyle(item->child(i), level + 1);
    }
}

void setWeightDisplay(QWidget* page,QString filePath,Node* root){
    QXlsx::Document xlsx(filePath);
    if (!xlsx.load()) {
        qDebug() << "Failed to load Excel file.";
        return;
    }
    readExcel(xlsx,root);
    weightNormalization(root);
    QTreeWidget *treeWidget = new QTreeWidget(page);
    QVBoxLayout *layout = new QVBoxLayout(page);
    layout->addWidget(treeWidget);
    page->setLayout(layout);
    treeWidget->setColumnCount(2);
    treeWidget->setHeaderLabels(QStringList() << "指标项" << "权重");
    for(Node* child:root->children){
        QTreeWidgetItem *item = new QTreeWidgetItem(treeWidget);
        item->setText(0, child->name);
        item->setText(1, QString::number(child->weight)+"%");
        setupTreeWidget(item,child);
    }
    for (int i = 0; i < treeWidget->topLevelItemCount(); ++i) {
        applyBarStyle(treeWidget->topLevelItem(i), 0);
    }
    std::cout<<"success";
    treeWidget->expandAll();
    return;
}

//导入专家权重
void MainWindow::on_z_load_pushButton_clicked()
{
    bool ok;
    int expertCount = QInputDialog::getInt(this, "输入专家数量", "请输入需要几位专家：", 1, 1, 10, 1, &ok);
    if (!ok) return;

    QStringList expertNames;
    QStringList filePaths;
    //QVector<VerticalButton *> vb;
    QVBoxLayout *layout = new QVBoxLayout(ui->side_z_c_3);

    for (int i = 0; i < expertCount; ++i) {
        QString expertName = QInputDialog::getText(this, tr("输入专家姓名"), tr("专家 %1 姓名：").arg(i + 1), QLineEdit::Normal, "", &ok);
        if (!ok || expertName.isEmpty()) {
            QMessageBox::warning(this, "警告", "专家姓名不能为空。");
            return;
        }
        expertNames << expertName;

        QString defaultPath = "D:\\MyCode\\Qt\\evaluation_sys\\evaluation";
        QString filePath = QFileDialog::getOpenFileName(this, tr("导入专家评分文件"), defaultPath, tr("所有文件 (*.*);;文本文件 (*.txt);;Excel 文件 (*.xlsx)"));
        if (filePath.isEmpty()) {
            QMessageBox::warning(this, "警告", "未选择文件。");
            return;
        }
        filePaths << filePath;
        //为每一个设置以一个page
        QWidget *page = new QWidget(ui->zhuan_weight_display_st);
        ui->zhuan_weight_display_st->addWidget(page);
        VerticalButton *zhuan_b = new VerticalButton(expertName,ui->side_z_c_3,ui->zhuan_weight_display_st,page);
        layout->addWidget(zhuan_b);
        setWeightDisplay(page,filePath,root);
    }
    ui->side_z_c_3->setLayout(layout);

    QMessageBox::information(this, "导入成功", tr("已成功导入 %1 位专家的评分文件。").arg(expertCount));

}


void writeNodeToExcel(QXlsx::Document &xlsx, const Node *node,QXlsx::Format format) {
    int col = node->x/x_gap+1;
    int row = node->y/y_gap+1;
    xlsx.write(row,col,node->name,format);
    for(const Node* child:node->children){
        writeNodeToExcel(xlsx,child,format);
    }
    return;
}

//计算前面有多少张表
int calBrotherChildNum(const Node* node){
    Node* parent = node->parent;
    int child_num =0;
    if(!parent->parent)
    {
        for(const Node* brother:parent->children){
            if(brother == node) break;
            else{
                child_num++;
                child_num+=brother->children.size();
                child_num++;
            }
        }
    }
    else{
        for(const Node* parent:parent->parent->children){
            for(const Node* brother:parent->children)
            {
                if(brother == node) return child_num;
                else{
                    child_num++;
                    child_num+=brother->children.size();
                    child_num++;
                }
            }
        }
    }
    return child_num;
}

//计算上一层节点，最大子节点数目
int calMaxChildNum(const Node* node){
    int max = 0;
    if(node->parent){
        for(const Node* child:node->parent->children){
            if(child->children.size()>=max){
                max = child->children.size();
            }
        }
        return max;
    }
    else{
        return node->children.size();
    }

}

//生成层次分析法模板函数
void generateAnaliticTable(QXlsx::Document &xlsx,Node* node,int row,int col,QXlsx::Format title_format){
    if(node->children.empty()) return;
    int c_row = row;
    int c_col = col;
    xlsx.write(row,col,node->name,title_format);
    node->cen_xlsx_x = row;
    node->cen_xlsx_y = col;   //记录在层次分析模板中的位置
    node->row=row;
    node->col=col;
    c_row++;
    c_col++;
    int max_child_num = calMaxChildNum(node);
    qInfo()<<node->name;
    qInfo()<<row<<col;
    for(Node* child:node->children){
        xlsx.write(row,c_col++,child->name,title_format);
        xlsx.write(c_row++,col,child->name,title_format);
        int width = calBrotherChildNum(child);
        generateAnaliticTable(xlsx,child,row+max_child_num+2,width+1,title_format);
    }
    return;
}

void MainWindow::on_generate_weight_pushButton_clicked()
{
    QXlsx::Document zhuan_xlsx;
    QXlsx::Document cen_xlsx;

    // 设置标题格式
    QXlsx::Format titleFormat;
    titleFormat.setFontBold(true);
    titleFormat.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    titleFormat.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    titleFormat.setBorderStyle(QXlsx::Format::BorderThin);

    // 设置普通单元格格式
    QXlsx::Format cellFormat;
    cellFormat.setHorizontalAlignment(QXlsx::Format::AlignHCenter);
    cellFormat.setVerticalAlignment(QXlsx::Format::AlignVCenter);
    cellFormat.setBorderStyle(QXlsx::Format::BorderThin);

    // 创建树并写入数据
    writeNodeToExcel(zhuan_xlsx, root,titleFormat);
    generateAnaliticTable(cen_xlsx,root,1,1,titleFormat);

    zhuan_xlsx.setColumnWidth(1, 20);
    zhuan_xlsx.setColumnWidth(2, 20);
    zhuan_xlsx.setColumnWidth(3, 20);
    zhuan_xlsx.setColumnWidth(4, 10);

    zhuan_xlsx.saveAs("D:\\MyCode\\Qt\\evaluation_sys\\evaluation\\zhuan_weight.xlsx");
    cen_xlsx.saveAs("D:\\MyCode\\Qt\\evaluation_sys\\evaluation\\cen_weight.xlsx");
    QMessageBox::information(this,tr("提示"),tr("模板生成成功！"));
}

void readAnaliticData(QXlsx::Document *xlsx,Node* node,QWidget* page){
    if(node->children.empty()) return;
    //读入对应节点的层次分析数据
    int x;
    int y;
    x= node->cen_xlsx_x+1;
    y=node->cen_xlsx_y+1;
    //想像数组一样使用它，就需要初始化，不然可以用push_back
    QVector<QVector<double>> matrix(100,QVector<double> (100,0.0));
    for(int i=0;i<node->children.count();i++){
        y=node->cen_xlsx_y+1;
        for(int j=0;j<node->children.count();j++){
            matrix[i][j]=xlsx->read(x,y).toDouble();
            qInfo() <<node->name<<matrix[i][j];
            y++;
        }
        qInfo()<<Qt::endl;
        x++;
    }
    node->cen_weight.insert(page,matrix);
    for(Node* child:node->children){
        readAnaliticData(xlsx,child,page);
    }
}

void MainWindow::on_c_load_pushButton_clicked()
{
    bool ok;
    int expertCount = QInputDialog::getInt(this, "输入专家数量", "请输入需要几位专家：", 1, 1, 10, 1, &ok);
    if (!ok) return;

    QVector<VerticalButton *> vb;
    QVBoxLayout *layout = new QVBoxLayout(ui->side_z_c);

    for (int i = 0; i < expertCount; ++i) {
        QString expertName = QInputDialog::getText(this, tr("输入专家姓名"), tr("专家 %1 姓名：").arg(i + 1), QLineEdit::Normal, "", &ok);
        if (!ok || expertName.isEmpty()) {
            QMessageBox::warning(this, "警告", "专家姓名不能为空。");
            return;
        }

        QString defaultPath = "D:\\MyCode\\Qt\\evaluation_sys\\evaluation";
        QString filePath = QFileDialog::getOpenFileName(this, tr("导入专家评分文件"), defaultPath, tr("所有文件 (*.*);;文本文件 (*.txt);;Excel 文件 (*.xlsx)"));
        if (filePath.isEmpty()) {
            QMessageBox::warning(this, "警告", "未选择文件。");
            return;
        }

        //为每一个设置以一个page
        QWidget *page = new QWidget(ui->cen_weight_display_st);
        ui->cen_weight_display_st->addWidget(page);
        VerticalButton *cen_b = new VerticalButton(expertName,ui->side_z_c,ui->cen_weight_display_st,page);
        layout->addWidget(cen_b);
        //读入层次分析数据
        //将每个专家的表格存入对应数据结构
        QXlsx::Document* xlsx= new QXlsx::Document(filePath);
        readAnaliticData(xlsx,root,page);
    }
    //为什么没有显示按钮
    ui->side_z_c->setLayout(layout);
    ui->side_z_c->show();
    QMessageBox::information(this, "导入成功", tr("已成功导入 %1 位专家的评分文件。").arg(expertCount));
}


