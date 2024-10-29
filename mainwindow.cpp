#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QContextMenuEvent>
#include <QTreeView>
#include <QStandardItemModel>
#include <QHeaderView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniUI();

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

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_pushButton_3_clicked()
{

}


void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if (item->text(0) == "权重体系设计") {
        ui->stackedWidget_2->setCurrentIndex(1);
    }
}


void MainWindow::on_zhuan_pushButton_clicked()
{
    ui->weight_stack->setCurrentIndex(0);
}


void MainWindow::on_cen_pushButton_clicked()
{
    ui->weight_stack->setCurrentIndex(1);
}

