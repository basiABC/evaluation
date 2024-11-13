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
    void createLayeredStructure(int layers, int nodesPerLayer);
    void clearAllLines();
    void connectLinesRecursively(Node* parentNode);
    void connectAllLines();

};
#endif // MAINWINDOW_H

