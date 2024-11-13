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


void MainWindow::on_zhuan_pushButton_clicked()
{
    ui->weight_stack->setCurrentIndex(0);
}


void MainWindow::on_cen_pushButton_clicked()
{
    ui->weight_stack->setCurrentIndex(1);
}

