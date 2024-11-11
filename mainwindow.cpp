#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QContextMenuEvent>
#include <QTreeView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "node.h"
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

    //setCentralWidget(ui->txtEdit);
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
    QGraphicsScene* scene = new QGraphicsScene(this);

    // 初始化 view 并将其设置为 widget_2 的子控件
    view = new QGraphicsView(scene, ui->widget_2);
    view->setRenderHint(QPainter::Antialiasing);

    // 设置 view 的初始几何位置
    view->setGeometry(5, 5, ui->widget_2->width()-10, ui->widget_2->height()-10);
    Node* root = new Node("****任务效能", scene);
    // 调整视图显示区域以包含所有节点
    scene->setSceneRect(5, 5, ui->widget_2->width()-10, ui->widget_2->height()-10);

}


void MainWindow::on_zhuan_pushButton_clicked()
{
    ui->weight_stack->setCurrentIndex(0);
}


void MainWindow::on_cen_pushButton_clicked()
{
    ui->weight_stack->setCurrentIndex(1);
}


