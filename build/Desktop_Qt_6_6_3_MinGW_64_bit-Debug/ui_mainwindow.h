/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actCut;
    QAction *actCopy;
    QAction *actPaste;
    QAction *actFontBold;
    QAction *actFontItalic;
    QAction *actFontUnder;
    QAction *actFont;
    QWidget *centralwidget;
    QWidget *widget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout;
    QFrame *frame;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QTreeWidget *treeWidget;
    QStackedWidget *stackedWidget_3;
    QWidget *page_3;
    QPushButton *pushButton_7;
    QWidget *stackedWidget_3Page1;
    QVBoxLayout *verticalLayout_2;
    QWidget *header1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QWidget *header2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QCheckBox *checkBox;
    QPushButton *pushButton_6;
    QSpacerItem *horizontalSpacer;
    QWidget *widget_2;
    QWidget *page_2;
    QWidget *page_4;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1036, 633);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actCut = new QAction(MainWindow);
        actCut->setObjectName("actCut");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::EditCut")));
        actCut->setIcon(icon);
        actCut->setMenuRole(QAction::MenuRole::NoRole);
        actCopy = new QAction(MainWindow);
        actCopy->setObjectName("actCopy");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::EditCopy")));
        actCopy->setIcon(icon1);
        actCopy->setMenuRole(QAction::MenuRole::NoRole);
        actPaste = new QAction(MainWindow);
        actPaste->setObjectName("actPaste");
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::EditPaste")));
        actPaste->setIcon(icon2);
        actPaste->setMenuRole(QAction::MenuRole::NoRole);
        actFontBold = new QAction(MainWindow);
        actFontBold->setObjectName("actFontBold");
        actFontBold->setCheckable(true);
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::FormatTextBold")));
        actFontBold->setIcon(icon3);
        actFontBold->setMenuRole(QAction::MenuRole::NoRole);
        actFontItalic = new QAction(MainWindow);
        actFontItalic->setObjectName("actFontItalic");
        actFontItalic->setCheckable(true);
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::FormatTextItalic")));
        actFontItalic->setIcon(icon4);
        actFontItalic->setMenuRole(QAction::MenuRole::NoRole);
        actFontUnder = new QAction(MainWindow);
        actFontUnder->setObjectName("actFontUnder");
        actFontUnder->setCheckable(true);
        QIcon icon5(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::FormatTextUnderline")));
        actFontUnder->setIcon(icon5);
        actFontUnder->setMenuRole(QAction::MenuRole::NoRole);
        actFont = new QAction(MainWindow);
        actFont->setObjectName("actFont");
        QIcon icon6(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::MailMessageNew")));
        actFont->setIcon(icon6);
        actFont->setMenuRole(QAction::MenuRole::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 1041, 651));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(0);
        formLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        frame = new QFrame(widget);
        frame->setObjectName("frame");
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setMinimumSize(QSize(200, 40));
        frame->setMaximumSize(QSize(200, 40));
        frame->setStyleSheet(QString::fromUtf8("#frame{\n"
"\n"
"background:rgb(187, 210, 243);\n"
"\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(4, 4, 4, 4);
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName("textEdit");
        textEdit->setStyleSheet(QString::fromUtf8("#textEdit{\n"
"	font-size: 10px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}"));
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        verticalLayout->addWidget(frame);

        treeWidget = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        treeWidget->setObjectName("treeWidget");
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setMaximumSize(QSize(200, 16777215));
        treeWidget->setStyleSheet(QString::fromUtf8("QTreeView {\n"
"    background-color: rgb(4, 29, 70); /* \350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    border: none; /* \345\216\273\351\231\244\350\276\271\346\241\206 */\n"
"    font-size: 14px; /* \350\256\276\347\275\256\345\255\227\344\275\223\345\244\247\345\260\217 */\n"
"}\n"
"\n"
"QTreeView::item {\n"
"    padding: 5px; /* \345\206\205\350\276\271\350\267\235\357\274\214\347\241\256\344\277\235\346\226\207\345\255\227\345\222\214\345\233\276\346\240\207\344\270\215\347\264\247\350\264\264\350\276\271\347\274\230 */\n"
"    border-bottom: 1px solid white; /* \346\257\217\344\270\200\351\241\271\347\232\204\345\272\225\351\203\250\345\210\206\345\211\262\347\272\277 */\n"
"	border-top: 1px solid white;\n"
"    margin-left: 0px; /* \347\247\273\351\231\244\345\267\246\344\276\247\347\274\251\350\277\233 */\n"
"    padding-left: 0px; /* \344\275\277\346\226\207\345\255\227\350\264\264\345\210\260\346\234\200\345\267"
                        "\246 */\n"
"}\n"
"\n"
"QTreeView::item:selected {\n"
"    background-color: rgb(5, 40, 150); /* \351\200\211\344\270\255\351\241\271\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \351\200\211\344\270\255\351\241\271\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QTreeView::item:hover {\n"
"    background-color: rgb(4, 35, 120); /* \346\202\254\345\201\234\346\227\266\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"}\n"
"\n"
"QTreeView::item:has-children {\n"
"    background-color: rgb(67, 115, 152); /* \347\210\266\350\212\202\347\202\271\347\232\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    color: white; /* \347\210\266\350\212\202\347\202\271\347\232\204\346\226\207\345\255\227\351\242\234\350\211\262 */\n"
"    padding: 5px;\n"
"    border-bottom: 1px solid white;\n"
"}\n"
"\n"
"QTreeView::branch:has-children {\n"
"    background-color: rgb(67, 115, 152); /* \347\210\266\350\212\202\347\202\271\347\232"
                        "\204\350\203\214\346\231\257\351\242\234\350\211\262 */\n"
"    border-bottom: 1px solid white;\n"
"    border-top: 1px solid white;\n"
"}\n"
"\n"
"/* \345\255\220\350\212\202\347\202\271\347\232\204 branch \351\203\250\345\210\206\357\274\214\347\241\256\344\277\235\350\203\214\346\231\257\351\242\234\350\211\262\344\270\216\345\255\220\350\212\202\347\202\271\345\217\263\344\276\247\344\270\200\350\207\264 */\n"
"QTreeView::branch:!has-children {\n"
"    background-color: rgb(4, 29, 70); /* \345\255\220\350\212\202\347\202\271\345\267\246\344\276\247\347\256\255\345\244\264\345\214\272\345\237\237\350\203\214\346\231\257 */\n"
"    border-bottom: 1px solid white;\n"
"    border-top: 1px solid white;\n"
"}"));
        treeWidget->setColumnCount(1);
        treeWidget->header()->setVisible(false);

        verticalLayout->addWidget(treeWidget);


        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout);

        stackedWidget_3 = new QStackedWidget(widget);
        stackedWidget_3->setObjectName("stackedWidget_3");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(stackedWidget_3->sizePolicy().hasHeightForWidth());
        stackedWidget_3->setSizePolicy(sizePolicy2);
        stackedWidget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(231, 231, 231);"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        pushButton_7 = new QPushButton(page_3);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(10, 10, 141, 31));
        stackedWidget_3->addWidget(page_3);
        stackedWidget_3Page1 = new QWidget();
        stackedWidget_3Page1->setObjectName("stackedWidget_3Page1");
        verticalLayout_2 = new QVBoxLayout(stackedWidget_3Page1);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        header1 = new QWidget(stackedWidget_3Page1);
        header1->setObjectName("header1");
        horizontalLayout_2 = new QHBoxLayout(header1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton = new QPushButton(header1);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton:pressed {\n"
"    background-color: #3e8e41;  /* \346\233\264\346\267\261\347\232\204\347\273\277\350\211\262\350\203\214\346\231\257 */\n"
"    border: 2px solid #3e8e41;  /* \346\233\264\346\267\261\347\232\204\347\273\277\350\211\262\350\276\271\346\241\206 */\n"
"    padding-left: 12px;         /* \346\250\241\346\213\237\346\214\211\344\270\213\347\232\204\346\225\210\346\236\234 */\n"
"    padding-top: 12px;          /* \346\250\241\346\213\237\346\214\211\344\270\213\347\232\204\346\225\210\346\236\234 */\n"
"}\n"
"\n"
"QPushButton:focus {\n"
"    outline: none;              /* \347\247\273\351\231\244\351\273\230\350\256\244\347\232\204\347\204\246\347\202\271\346\241\206 */\n"
"    border: 2px solid #FF5722;  /* \346\251\231\350\211\262\350\276\271\346\241\206\357\274\214\350\241\250\347\244\272\350\216\267\345\276\227\347\204\246\347\202\271 */\n"
"}"));
        QIcon icon7(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::UserAvailable")));
        pushButton->setIcon(icon7);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(header1);
        pushButton_2->setObjectName("pushButton_2");
        QIcon icon8(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::FormatJustifyCenter")));
        pushButton_2->setIcon(icon8);

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout_2->addWidget(header1);

        stackedWidget = new QStackedWidget(stackedWidget_3Page1);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        header2 = new QWidget(page);
        header2->setObjectName("header2");
        sizePolicy2.setHeightForWidth(header2->sizePolicy().hasHeightForWidth());
        header2->setSizePolicy(sizePolicy2);
        header2->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_3 = new QHBoxLayout(header2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButton_3 = new QPushButton(header2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 200, 255);"));
        QIcon icon9(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::DocumentPageSetup")));
        pushButton_3->setIcon(icon9);

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(header2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 200, 255);"));
        QIcon icon10(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::HelpAbout")));
        pushButton_4->setIcon(icon10);

        horizontalLayout_3->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(header2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 200, 255);"));
        QIcon icon11(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::AddressBookNew")));
        pushButton_5->setIcon(icon11);

        horizontalLayout_3->addWidget(pushButton_5);

        checkBox = new QCheckBox(header2);
        checkBox->setObjectName("checkBox");
        QFont font;
        font.setBold(true);
        checkBox->setFont(font);

        horizontalLayout_3->addWidget(checkBox);

        pushButton_6 = new QPushButton(header2);
        pushButton_6->setObjectName("pushButton_6");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy3);
        pushButton_6->setMinimumSize(QSize(80, 0));
        pushButton_6->setMaximumSize(QSize(80, 16777215));
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 200, 255);"));
        QIcon icon12(QIcon::fromTheme(QString::fromUtf8("QIcon::ThemeIcon::DocumentSave")));
        pushButton_6->setIcon(icon12);

        horizontalLayout_3->addWidget(pushButton_6);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_3->addWidget(header2);

        widget_2 = new QWidget(page);
        widget_2->setObjectName("widget_2");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy4);

        verticalLayout_3->addWidget(widget_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout_2->addWidget(stackedWidget);

        stackedWidget_3->addWidget(stackedWidget_3Page1);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        stackedWidget_3->addWidget(page_4);

        formLayout->setWidget(0, QFormLayout::FieldRole, stackedWidget_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1036, 22));
        menubar->setStyleSheet(QString::fromUtf8("#menubar{\n"
"	background-color: rgb(187, 210, 243);\n"
"    spacing: 3px; \n"
"    border-top: 1px solid gray; \n"
"    border-bottom: 1px solid gray; \n"
"}\n"
"\n"
"QMenuBar::item {\n"
"    padding: 1px 4px;\n"
"    background: transparent;\n"
"    border-radius: 4px;\n"
"    border-right: 1px solid gray;\n"
"}\n"
""));
        menu = new QMenu(menubar);
        menu->setObjectName("menu");
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName("menu_2");
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName("menu_3");
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName("menu_4");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy5);
        toolBar->setStyleSheet(QString::fromUtf8("#toolBar{\n"
"\n"
"background-color: rgb(187, 210, 243);\n"
"border: 1px solid gray;\n"
"\n"
"}"));
        toolBar->setIconSize(QSize(15, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonStyle::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_3->menuAction());
        menubar->addAction(menu_4->menuAction());
        menu->addAction(actPaste);
        menu->addAction(actCopy);
        menu->addAction(actCut);
        menu_2->addAction(actFontItalic);
        menu_2->addAction(actFontBold);
        menu_2->addAction(actFontUnder);
        menu_3->addSeparator();
        menu_3->addAction(actFont);
        menu_4->addSeparator();
        menu_4->addSeparator();
        menu_4->addSeparator();
        toolBar->addAction(actCut);
        toolBar->addAction(actCopy);
        toolBar->addAction(actPaste);
        toolBar->addSeparator();
        toolBar->addAction(actFontBold);
        toolBar->addAction(actFontUnder);
        toolBar->addAction(actFontItalic);
        toolBar->addSeparator();
        toolBar->addAction(actFont);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actCut->setText(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#if QT_CONFIG(tooltip)
        actCut->setToolTip(QCoreApplication::translate("MainWindow", "\345\211\252\345\210\207", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actCut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actCopy->setText(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#if QT_CONFIG(tooltip)
        actCopy->setToolTip(QCoreApplication::translate("MainWindow", "\345\244\215\345\210\266", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actCopy->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actPaste->setText(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#if QT_CONFIG(tooltip)
        actPaste->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\230\350\264\264", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actFontBold->setText(QCoreApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
#if QT_CONFIG(tooltip)
        actFontBold->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        actFontItalic->setText(QCoreApplication::translate("MainWindow", "\346\226\234\344\275\223", nullptr));
#if QT_CONFIG(tooltip)
        actFontItalic->setToolTip(QCoreApplication::translate("MainWindow", "\347\262\227\344\275\223", nullptr));
#endif // QT_CONFIG(tooltip)
        actFontUnder->setText(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#if QT_CONFIG(tooltip)
        actFontUnder->setToolTip(QCoreApplication::translate("MainWindow", "\344\270\213\345\210\222\347\272\277", nullptr));
#endif // QT_CONFIG(tooltip)
        actFont->setText(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        actFont->setToolTip(QCoreApplication::translate("MainWindow", "\345\255\227\344\275\223\350\256\276\347\275\256", nullptr));
#endif // QT_CONFIG(tooltip)
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:10px; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:9pt; font-weight:600;\">\347\201\255\347\201\253\344\273\273\345\212\241\346\225\210\350\203\275\346\214\207\346\240\207\344\275\223\347\263\273 </span></p></body></html>", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "1", nullptr));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "\346\214\207\346\240\207\344\275\223\347\263\273\347\256\241\347\220\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "\346\214\207\346\240\207\344\275\223\347\263\273\350\256\276\350\256\241", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "\346\235\203\351\207\215\344\275\223\347\263\273\350\256\276\350\256\241", nullptr));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QCoreApplication::translate("MainWindow", "\347\256\227\346\263\225\344\275\223\347\263\273\350\256\276\350\256\241", nullptr));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem5->setText(0, QCoreApplication::translate("MainWindow", "\344\273\277\347\234\237\345\273\272\346\250\241", nullptr));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem5->child(0);
        ___qtreewidgetitem6->setText(0, QCoreApplication::translate("MainWindow", "\344\273\277\347\234\237\347\250\213\345\272\217\351\205\215\347\275\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem5->child(1);
        ___qtreewidgetitem7->setText(0, QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\346\225\260\346\215\256\351\205\215\347\275\256", nullptr));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem5->child(2);
        ___qtreewidgetitem8->setText(0, QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\351\242\204\345\244\204\347\220\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem9 = ___qtreewidgetitem5->child(3);
        ___qtreewidgetitem9->setText(0, QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\347\272\246\346\235\237\345\273\272\346\250\241", nullptr));
        QTreeWidgetItem *___qtreewidgetitem10 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem10->setText(0, QCoreApplication::translate("MainWindow", "\350\257\204\344\274\260\345\210\206\346\236\220", nullptr));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem10->child(0);
        ___qtreewidgetitem11->setText(0, QCoreApplication::translate("MainWindow", "\346\225\210\350\203\275\350\257\204\344\274\260\350\256\241\347\256\227", nullptr));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem10->child(1);
        ___qtreewidgetitem12->setText(0, QCoreApplication::translate("MainWindow", "\345\217\202\346\225\260\346\225\217\346\204\237\346\200\247\345\210\206\346\236\220", nullptr));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem10->child(2);
        ___qtreewidgetitem13->setText(0, QCoreApplication::translate("MainWindow", "\345\244\232\347\233\256\346\240\207\344\274\230\345\214\226", nullptr));
        QTreeWidgetItem *___qtreewidgetitem14 = ___qtreewidgetitem10->child(3);
        ___qtreewidgetitem14->setText(0, QCoreApplication::translate("MainWindow", "\350\222\231\347\211\271\345\215\241\346\264\233\346\250\241\346\213\237", nullptr));
        QTreeWidgetItem *___qtreewidgetitem15 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem15->setText(0, QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\347\256\241\347\220\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem16 = ___qtreewidgetitem15->child(0);
        ___qtreewidgetitem16->setText(0, QCoreApplication::translate("MainWindow", "\347\256\227\346\263\225\345\272\223\347\256\241\347\220\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem17 = ___qtreewidgetitem15->child(1);
        ___qtreewidgetitem17->setText(0, QCoreApplication::translate("MainWindow", "\346\250\241\346\213\237\345\272\223\347\256\241\347\220\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem18 = ___qtreewidgetitem15->child(2);
        ___qtreewidgetitem18->setText(0, QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\345\272\223\347\256\241\347\220\206", nullptr));
        QTreeWidgetItem *___qtreewidgetitem19 = ___qtreewidgetitem15->child(3);
        ___qtreewidgetitem19->setText(0, QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\351\205\215\347\275\256", nullptr));
        treeWidget->setSortingEnabled(__sortingEnabled);

        pushButton_7->setText(QCoreApplication::translate("MainWindow", "\346\225\210\350\203\275\346\214\207\346\240\207\344\275\223\347\263\273\350\256\276\350\256\241", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\344\270\223\345\256\266\345\210\206\346\236\220\346\263\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\345\261\202\346\254\241\345\210\206\346\236\220\346\263\225", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\345\212\240\350\275\275\344\270\223\345\256\266\346\235\203\351\207\215\350\241\250", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\345\275\222\344\270\200\345\214\226\345\244\204\347\220\206", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\347\224\237\346\210\220\347\273\274\345\220\210\346\235\203\351\207\215\350\241\250", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\350\256\276\344\270\272\351\273\230\350\256\244\346\235\203\351\207\215\344\275\223\347\263\273", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "       \346\214\207\346\240\207\344\275\223\347\263\273\347\256\241\347\220\206       ", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "     \344\273\277\347\234\237\345\273\272\346\250\241     ", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "     \350\257\204\344\274\260\345\210\206\346\236\220     ", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "     \347\263\273\347\273\237\347\256\241\347\220\206     ", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
