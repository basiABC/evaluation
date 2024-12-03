#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QProgressBar>
#include <QFontComboBox>
#include <QSpinBox>
#include <QTreeWidget>
#include <QStackedWidget>
#include <QTreeWidgetItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>
#include <QPainter>
#include <QStyleOptionButton>
#include <QStylePainter>
#include <QMessageBox>
#include <QMouseEvent>
#include "node.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;

}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    class VerticalButton : public QPushButton {
    public:
        VerticalButton(const QString &text,QWidget *parent = nullptr, QStackedWidget *s_widget=nullptr,QWidget *page = nullptr)
            : QPushButton(text, parent) {
            this->v_b_name = text;
            this->page = page;
            this->s_widget = s_widget;
        }

    protected:
        void paintEvent(QPaintEvent *event) override {
            QStylePainter painter(this);
            QStyleOptionButton option;
            initStyleOption(&option);

            // 设置按钮的样式状态
            option.rect = QRect(0, 0, height(), width()); // 调整绘制区域
            option.state |= QStyle::State_HasFocus;      // 添加聚焦样式（可以让按钮更明显）

            painter.save();
            painter.translate(width() / 2, height() / 2);
            painter.rotate(90);
            painter.translate(-height() / 2, -width() / 2);

            // 绘制按钮
            painter.drawControl(QStyle::CE_PushButton, option);

            painter.restore();
        }

        QSize sizeHint() const override {
            QSize size = QPushButton::sizeHint();
            return QSize(size.height(), size.width());
        }

        //点击后显示对应的权重在weight_display窗口
        void mousePressEvent(QMouseEvent *event) override {
            // 点击后展示对应的权重信息在窗口中
            if (event->button() == Qt::LeftButton) {
                //展示权重在窗口
                s_widget->setCurrentWidget(this->page);
                QMessageBox::information(this, "Clicked", "专家"+QString(this->v_b_name)+"权重数据展示");
            }

            QPushButton::mousePressEvent(event);
        }
    private:
        QString v_b_name;
        QWidget *page;
        QStackedWidget *s_widget;

    };



private slots:

    void onTreeWidgetItemClicked(QTreeWidgetItem *item, int column);

    void setupNodeView();

    void on_zhuan_pushButton_clicked();

    void on_cen_pushButton_clicked();

    void on_pushButton_clicked();

    void on_z_load_pushButton_clicked();

    void on_generate_weight_pushButton_clicked();

private:
    QGraphicsScene *scene;
    Node *root;
    QGraphicsView *view;
    Ui::MainWindow *ui;
    QLabel *fLabCurFile;
    QProgressBar *progressBar1;
    QFontComboBox *comboFont;
    QSpinBox   *spinFontSize;
    QTreeWidget *treeWidget;
    QStackedWidget *stackedWidget;

    void iniUI();
    void clearSceneExceptRoot(Node* root);
    void createLayeredStructure(int layers, int nodesPerLayer, Node* parent = nullptr, int currentLayer = 1);
    void clearAllLines();
    void connectLinesRecursively(Node* parentNode);
    void connectAllLines();

};
#endif // MAINWINDOW_H

