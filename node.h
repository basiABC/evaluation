#ifndef NODE_H
#define NODE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QString>
#include <QMenu>
#include <QAction>
#include <QGraphicsSceneContextMenuEvent>
inline int node_x = 100;
inline int node_y = 30;
inline int x_gap = 75;
inline int y_gap = 40;

class Node : public QGraphicsItem {
public:
    int x;
    int y;
    double score;
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
            y = parent->y + y_gap*(parent->returnChildnum());
            isRootNode=false;
            setFlag(QGraphicsItem::ItemIsSelectable, true);
            setFlag(QGraphicsItem::ItemIsFocusable, true);
            setFlag(QGraphicsItem::ItemIsMovable, false);
            Node* root = findRootNode();  // 找到根节点
            root->shiftNodesDown(y,this);  // 从根节点开始调整位置
        } else {
            x = 0;  // 设置根节点的初始位置
            y = 0;
            isRootNode=true;
            setFlag(QGraphicsItem::ItemIsSelectable, true);
            setFlag(QGraphicsItem::ItemIsFocusable, true);
            setFlag(QGraphicsItem::ItemIsMovable, false);
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

    int returnChildnum(){
        return children.size();
    }
    Node* findRootNode() {
        Node* current = this;
        while (current->parent != nullptr) {
            current = current->parent;
        }
        return current;  // 返回根节点
    }
    void shiftNodesDown(int y_threshold, Node* newNode) {
        // 如果当前节点是新创建的节点，则跳过
        if (this == newNode) {
            return;
        }

        // 如果当前节点的 y 值大于阈值，则将它的 y 值往下移动 y_gap
        if (this->y >= y_threshold) {
            this->y += y_gap;
            setPos(this->x, this->y);  // 更新 QGraphicsItem 的位置
        }

        // 递归遍历所有子节点
        for (auto& child : this->children) {
            child->shiftNodesDown(y_threshold, newNode);  // 对子节点递归调用
        }
    }





protected:
    // 重写 contextMenuEvent 以在右键单击时显示上下文菜单
    void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override {
        QMenu menu;

        // 添加菜单项
        QAction* addAction = menu.addAction("新建子节点");
        QAction* deleteAction = menu.addAction("删除(D)");
        QAction* renameAction = menu.addAction("重命名(R)");
        QAction* selectAction = menu.addAction("选中节点(S)");
        QAction* copyAction = menu.addAction("复制(C)");
        QAction* cutAction = menu.addAction("剪切(T)");
        QAction* pasteAction = menu.addAction("粘贴(P)");

        // 执行菜单，并获取被点击的动作
        QAction* selectedAction = menu.exec(event->screenPos());

        // 判断用户选择了哪个操作，并执行相应操作
        if (selectedAction == addAction) {
            // 执行新建子节点操作
            createChildNode();
        } else if (selectedAction == deleteAction) {
            // 执行删除操作
            deleteNode();
        } else if (selectedAction == renameAction) {
            // 执行重命名操作
            renameNode();
        } else if (selectedAction == selectAction) {
            // 执行选中节点操作
            selectNode();
        } else if (selectedAction == copyAction) {
            // 执行复制操作
            copyNode();
        } else if (selectedAction == cutAction) {
            // 执行剪切操作
            cutNode();
        } else if (selectedAction == pasteAction) {
            // 执行粘贴操作
            pasteNode();
        }
    }

    // 定义各项菜单操作的函数
    void createChildNode() {
        // 添加子节点的实现
    }

    void deleteNode() {
        // 删除节点的实现
    }

    void renameNode() {
        // 重命名节点的实现
    }

    void selectNode() {
        // 选中节点的实现
    }

    void copyNode() {
        // 复制节点的实现
    }

    void cutNode() {
        // 剪切节点的实现
    }

    void pasteNode() {
        // 粘贴节点的实现
    }

};


#endif // NODE_H
