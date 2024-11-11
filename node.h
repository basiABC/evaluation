#ifndef NODE_H
#define NODE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>

int node_x = 100;
int node_y = 30;
int x_gap = 75;
int y_gap = 40;

class Node : public QGraphicsItem {
public:
    int x;
    int y;
    QString name;
    QList<Node*> children;
    Node* parent = nullptr;
    QGraphicsScene* scene;
    bool isRootNode;
    // 构造函数，接受 QString, QGraphicsScene* 和可选的 Node* 父节点
    Node(const QString& name, QGraphicsScene* scene, Node* parent = nullptr)
        : name(name), scene(scene), parent(parent) {

        // 初始化节点的位置
        if (parent) {
            parent->addChild(this);
            x = parent->x + x_gap;
            y = parent->y + y_gap;
            isRootNode=false;
        } else {
            x = 0;  // 设置根节点的初始位置
            y = 0;
            isRootNode=true;
        }
        setPos(x, y);  // 设置 QGraphicsItem 的位置

        // 将节点添加到场景中
        if (scene) {
            scene->addItem(this);
        }
    }

    void addChild(Node* child) {
        children.append(child);
    }

    QRectF boundingRect() const override {
        // 定义节点的范围
        return QRectF(0, 0, 100, 30);
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        painter->drawRect(0, 0, 100, 30);  // 仅绘制矩形边框
        painter->drawText(boundingRect(), Qt::AlignCenter, name);  // 在矩形中居中显示节点名称
    }
};


#endif // NODE_H
