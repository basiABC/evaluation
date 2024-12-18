#ifndef NODE_H
#define NODE_H

#include <QAction>
#include <QGraphicsObject>
#include <QGraphicsScene>
#include <QGraphicsSceneContextMenuEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QPainter>
#include <QPushButton>
#include <QSpinBox>
#include <QStackedWidget>
#include <QString>
#include <QTableWidget>
#include <QWidget>
#include <QWidgetAction>
#include "xlsxdocument.h"
#include "xlsxformat.h"

inline int node_x = 100;
inline int node_y = 30;
inline int x_gap = 75;
inline int y_gap = 40;

class Node : public QGraphicsObject
{
    Q_OBJECT // 必须添加，以支持信号槽机制

public:
    int x;
    int y;
    double score = 0;
    QString name;
    QList<Node *> children;
    Node *parent = nullptr;
    QGraphicsScene *scene;
    QWidget *mainWindow;
    bool isRootNode = false;
    QGraphicsLineItem *verticalLine = nullptr;   // 用于存储垂直段的线
    QGraphicsLineItem *horizontalLine = nullptr; // 用于存储水平段的线
    double weight = 0;
    //对应指标项，层次分析表表头的位置
    int row;
    int col;
    int cen_xlsx_x;
    int cen_xlsx_y;
    QMap<QWidget*, QVector<QVector<double>>> cen_weight;
    //导入权重按钮点击后直接导入
    QVector<QVector<double>> cen_quanzhong;

    Node(QGraphicsScene *scene, Node *parent = nullptr, QWidget *mainWindow = nullptr)
        : QGraphicsObject(nullptr)
        , scene(scene)
        , parent(parent)
        , mainWindow(mainWindow)
    {
        name = generateDefaultName();
        initializeNode();
    }

    Node(const QString &name,
         QGraphicsScene *scene,
         Node *parent = nullptr,
        QWidget *mainWindow = nullptr)
        : QGraphicsObject(nullptr)
        , name(name)
        , scene(scene)
        , parent(parent)
        , mainWindow(mainWindow)
    {
        initializeNode();
    }

    QRectF boundingRect() const override
    {
        return QRectF(0, 0, 100, 30); // 设置节点的范围
    }

    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr) override
    {
        painter->drawRect(0, 0, 100, 30);                         // 绘制矩形
        painter->drawText(boundingRect(), Qt::AlignCenter, name); // 显示节点名称
    }

    QString generateDefaultName()
    {
        if (parent == nullptr) {
            return "****任务效能";
        }
        int childIndex = parent->children.size() + 1;
        if (parent->isRootNode) {
            return QString("指标%1").arg(childIndex);
        } else {
            return QString("%1-%2").arg(parent->name).arg(childIndex);
        }
    }

    void initializeNode()
    {
        if (parent) {
            parent->addChild(this);
            x = parent->x + x_gap;
            int totalDescendants = parent->calculateTotalDescendants();
            y = parent->y + y_gap * totalDescendants;
            isRootNode = false;
            Node *root = findRootNode();
            root->shiftNodesDown(y, this);
        } else {
            x = 0;
            y = 0;
            isRootNode = true;
        }
        setFlag(QGraphicsItem::ItemIsSelectable, true);
        setFlag(QGraphicsItem::ItemIsFocusable, true);
        setFlag(QGraphicsItem::ItemIsMovable, false);
        setPos(x, y);
        addConnectionLine();
        if (scene) {
            scene->addItem(this);
        }
    }

    void addConnectionLine()
    {
        if (parent && scene) {
            QPen dashedPen(Qt::DashLine);
            dashedPen.setColor(Qt::black);
            dashedPen.setWidth(1);

            QPointF parentPos = parent->scenePos()
                                + QPointF(parent->boundingRect().width() / 2,
                                          parent->boundingRect().height());
            QPointF childPos = this->scenePos() + QPointF(0, this->boundingRect().height() / 2);
            QPointF intermediatePoint(parentPos.x(), childPos.y());

            verticalLine = new QGraphicsLineItem(QLineF(parentPos, intermediatePoint));
            verticalLine->setPen(dashedPen);
            scene->addItem(verticalLine);

            horizontalLine = new QGraphicsLineItem(QLineF(intermediatePoint, childPos));
            horizontalLine->setPen(dashedPen);
            scene->addItem(horizontalLine);
        }
    }

    void updateConnectionLine()
    {
        if (verticalLine && horizontalLine && parent) {
            QPointF parentPos = parent->scenePos()
                                + QPointF(parent->boundingRect().width() / 2,
                                          parent->boundingRect().height());
            QPointF childPos = this->scenePos() + QPointF(0, this->boundingRect().height() / 2);
            QPointF intermediatePoint(parentPos.x(), childPos.y());

            verticalLine->setLine(QLineF(parentPos, intermediatePoint));
            horizontalLine->setLine(QLineF(intermediatePoint, childPos));
        }
    }

    // void mousePressEvent(QGraphicsSceneMouseEvent* event) override {
    //     QGraphicsObject::mousePressEvent(event); // 调用基类事件处理
    //     QString detailsText;
    //     for (Node* child : children) {
    //         detailsText += QString("%1 : %2\n").arg(child->name).arg(child->score);
    //     }
    //     if (mainWindow) {
    //         QLabel* detailsLabel = mainWindow->findChild<QLabel*>("details");
    //         if (detailsLabel) {
    //             detailsLabel->setAlignment( Qt::AlignTop);
    //             detailsLabel->setText(detailsText);
    //         }
    //     }
    // }

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

    int calculateTotalDescendants() const
    {
        int count = children.size();
        for (const Node *child : children) {
            count += child->calculateTotalDescendants();
        }
        return count;
    }

    Node *findRootNode()
    {
        Node *current = this;
        while (current->parent != nullptr) {
            current = current->parent;
        }
        return current; // 返回根节点
    }

    void shiftNodesDown(int y_threshold, Node *newNode, bool isDown = true)
    {
        int y_move = isDown ? y_gap : -y_gap;
        if (this == newNode) {
            return;
        }
        if (this->y >= y_threshold) {
            this->y += y_move;
            setPos(this->x, this->y);
            updateConnectionLine();
        }
        for (Node *child : children) {
            child->shiftNodesDown(y_threshold, newNode, isDown);
        }
    }

protected:
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event) override
    {
        QMenu menu;

        // 创建包含 QLabel、QSpinBox 和 QPushButton 的 QWidget
        QWidget *widgetContainer = new QWidget();
        QHBoxLayout *layout = new QHBoxLayout(widgetContainer);
        layout->setContentsMargins(28, 0, 0, 0);

        QLabel *label = new QLabel("新建子节点", widgetContainer);
        QSpinBox *spinBox = new QSpinBox(widgetContainer);
        spinBox->setRange(1, 10); // 设置子节点数量范围
        spinBox->setValue(1);     // 默认值为 1
        QPushButton *applyButton = new QPushButton("应用", widgetContainer);

        layout->addWidget(label);
        layout->addWidget(spinBox);
        layout->addWidget(applyButton);

        QWidgetAction *widgetAction = new QWidgetAction(&menu);
        widgetAction->setDefaultWidget(widgetContainer);
        menu.addAction(widgetAction); // 添加到菜单

        // 右键菜单的常规选项
        QAction *deleteAction = menu.addAction("删除节点");
        QAction *renameAction = menu.addAction("重命名");
        QAction *selectAction = menu.addAction("选中节点");
        QAction *copyAction = menu.addAction("复制");
        QAction *cutAction = menu.addAction("剪切");
        QAction *pasteAction = menu.addAction("粘贴");

        // 绑定 QPushButton 的点击信号和槽
        QObject::connect(applyButton, &QPushButton::clicked, [&]() {
            int count = spinBox->value(); // 获取 QSpinBox 的值
            for (int i = 0; i < count; ++i) {
                Node *childNode = new Node(scene, this, mainWindow); // 创建子节点
            }
            menu.close(); // 关闭菜单
        });

        // 执行菜单并获取被点击的选项
        QAction *selectedAction = menu.exec(event->screenPos());

        // 判断用户选择的动作
        if (selectedAction == deleteAction) {
            deleteNode();
        } else if (selectedAction == renameAction) {
            renameNode();
        } else if (selectedAction == selectAction) {
            selectNode();
        } else if (selectedAction == copyAction) {
            copyNode();
        } else if (selectedAction == cutAction) {
            cutNode();
        } else if (selectedAction == pasteAction) {
            pasteNode();
        }
    }

    void deleteNode()
    {
        // 如果当前节点有父节点，从父节点的子节点列表中移除自身

        // 递归删除所有子节点
        for (Node *child : children) {
            if (scene) {
                scene->removeItem(child); // 从场景中移除子节点
            }
            child->deleteNode(); // 递归调用删除子节点
        }

        bool isdown = false;
        Node *root = findRootNode();
        root->shiftNodesDown(y, this, isdown);

        if (parent) {
            parent->children.removeOne(this); // 从父节点的子节点列表中移除
        }

        // 清空子节点列表
        children.clear();

        // 删除当前节点的连线
        if (scene) {
            if (verticalLine) {
                scene->removeItem(verticalLine);
                delete verticalLine;
                verticalLine = nullptr;
            }
            if (horizontalLine) {
                scene->removeItem(horizontalLine);
                delete horizontalLine;
                horizontalLine = nullptr;
            }
        }

        // 从场景中移除当前节点
        if (scene) {
            scene->removeItem(this);
        }

        // 最后删除当前节点
        delete this;
    }

    void renameNode() {}

    void selectNode() {}

    void copyNode() {}

    void cutNode() {}

    void pasteNode() {}

    void addChild(Node *child) { children.append(child); }
};

#endif // NODE_H
