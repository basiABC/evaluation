#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QContextMenuEvent>
#include <QTreeView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QPainter>
#include <QStyleOptionButton>
#include <QStylePainter>

class VerticalButton : public QPushButton {
public:
    VerticalButton(const QString &text, QWidget *parent = nullptr)
        : QPushButton(text, parent) {}

protected:
    void paintEvent(QPaintEvent *event) override {
        QStylePainter painter(this);
        QStyleOptionButton option;
        initStyleOption(&option);

        painter.rotate(90);

        QRect rect = option.rect;
        rect.setRect(-rect.height(), rect.x(), rect.width(), rect.height());

        option.rect = rect;
        painter.drawControl(QStyle::CE_PushButton, option);
    }

    QSize sizeHint() const override {
        QSize size = QPushButton::sizeHint();
        return QSize(size.height(), size.width());
    }
};

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
    //progressBar1->setValue(ui->txtEdit->font().pointSize());
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
    QVBoxLayout *layout = new QVBoxLayout(ui->side_z_c);

    for (int i = 0; i < 5; ++i) {
        VerticalButton *button = new VerticalButton(QString("Button %1").arg(i + 1), ui->side_z_c);
        layout->addWidget(button);
    }

    ui->side_z_c->setLayout(layout);
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

void MainWindow::on_pushButton_3_clicked()
{

}
void MainWindow::setupNodeView() {
    // 创建场景
    scene = new QGraphicsScene(this);

    // 初始化 view 并将其设置为 widget_2 的子控件
    view = new QGraphicsView(scene, ui->widget_2);
    view->setRenderHint(QPainter::Antialiasing);
    view->setContextMenuPolicy(Qt::DefaultContextMenu);

    view->setDragMode(QGraphicsView::NoDrag);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    // 设置 view 的初始几何位置
    view->setGeometry(5, 5, ui->widget_2->width()-10, ui->widget_2->height()-10);
    root = new Node("****任务效能", scene);
    Node* child1= new Node(scene,root);
    Node* child2= new Node(scene,root);
    Node* child3= new Node(scene,child1);
    Node* child4= new Node(scene,child2);
    Node* child5= new Node(scene,root);




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

void MainWindow::clearAllLines() {
    // 遍历场景中的所有项
    for (auto item : scene->items()) {
        // 如果项是 QGraphicsLineItem，则将其删除
        if (auto lineItem = dynamic_cast<QGraphicsLineItem*>(item)) {
            scene->removeItem(lineItem);
            delete lineItem;
        }
    }
}

void MainWindow::connectAllLines() {
    // 找到根节点（假设场景中只有一个根节点）

    if (root) {
        // 从根节点开始递归连接
        connectLinesRecursively(root);
    }
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

void MainWindow::connectLinesRecursively(Node* parentNode) {
    QPen dashedPen(Qt::black);
    dashedPen.setStyle(Qt::DashLine);
    dashedPen.setWidth(1);

    // 遍历父节点的所有子节点
    for (auto childNode : parentNode->children) {
        // 获取父节点的下半边中间位置
        QPointF parentPos = parentNode->scenePos() + QPointF(parentNode->boundingRect().width() / 2, parentNode->boundingRect().height());

        // 获取子节点的左边中间位置
        QPointF childPos = childNode->scenePos() + QPointF(0, childNode->boundingRect().height() / 2);

        // 计算折线的拐点
        QPointF intermediatePoint(parentPos.x(), childPos.y());

        // 绘制从父节点下边中间到拐点的垂直线
        scene->addLine(QLineF(parentPos, intermediatePoint), dashedPen);

        // 绘制从拐点到子节点左边中间的水平线
        scene->addLine(QLineF(intermediatePoint, childPos), dashedPen);

        // 递归连接子节点
        connectLinesRecursively(childNode);
    }
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
        Node* childNode = new Node(scene, parent);


        // 递归调用，为每个子节点生成下一层的子节点
        createLayeredStructure(layers, nodesPerLayer, childNode, currentLayer + 1);
    }
}
