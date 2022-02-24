/********************************************************************************
** Form generated from reading UI file 'Memo.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMO_H
#define UI_MEMO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MemoClass
{
public:
    QAction *actionNew;
    QAction *actionNew_Window;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionAs_Save;
    QAction *actionPrint;
    QAction *actionFont;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MemoClass)
    {
        if (MemoClass->objectName().isEmpty())
            MemoClass->setObjectName(QString::fromUtf8("MemoClass"));
        MemoClass->resize(677, 539);
        actionNew = new QAction(MemoClass);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionNew_Window = new QAction(MemoClass);
        actionNew_Window->setObjectName(QString::fromUtf8("actionNew_Window"));
        actionOpen = new QAction(MemoClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave = new QAction(MemoClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        actionAs_Save = new QAction(MemoClass);
        actionAs_Save->setObjectName(QString::fromUtf8("actionAs_Save"));
        actionPrint = new QAction(MemoClass);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        actionFont = new QAction(MemoClass);
        actionFont->setObjectName(QString::fromUtf8("actionFont"));
        centralWidget = new QWidget(MemoClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        MemoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MemoClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 677, 22));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        MemoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MemoClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MemoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MemoClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MemoClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(actionNew);
        menu->addAction(actionNew_Window);
        menu->addAction(actionOpen);
        menu->addAction(actionSave);
        menu->addAction(actionAs_Save);
        menu->addAction(actionPrint);
        menu_2->addAction(actionFont);

        retranslateUi(MemoClass);

        QMetaObject::connectSlotsByName(MemoClass);
    } // setupUi

    void retranslateUi(QMainWindow *MemoClass)
    {
        MemoClass->setWindowTitle(QCoreApplication::translate("MemoClass", "Memo", nullptr));
        actionNew->setText(QCoreApplication::translate("MemoClass", "\354\203\210\353\241\234 \353\247\214\353\223\244\352\270\260", nullptr));
        actionNew_Window->setText(QCoreApplication::translate("MemoClass", "\354\203\210\353\241\234 \354\227\264\352\270\260", nullptr));
        actionOpen->setText(QCoreApplication::translate("MemoClass", "\354\227\264\352\270\260", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MemoClass", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MemoClass", "\354\240\200\354\236\245", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MemoClass", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAs_Save->setText(QCoreApplication::translate("MemoClass", "\353\213\244\353\245\270\354\235\264\353\246\204\354\234\274\353\241\234 \354\240\200\354\236\245", nullptr));
#if QT_CONFIG(shortcut)
        actionAs_Save->setShortcut(QCoreApplication::translate("MemoClass", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPrint->setText(QCoreApplication::translate("MemoClass", "\355\224\204\353\246\260\355\212\270", nullptr));
#if QT_CONFIG(shortcut)
        actionPrint->setShortcut(QCoreApplication::translate("MemoClass", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFont->setText(QCoreApplication::translate("MemoClass", "\355\217\260\355\212\270", nullptr));
        menu->setTitle(QCoreApplication::translate("MemoClass", "\355\214\214\354\235\274", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MemoClass", "\355\216\270\354\247\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MemoClass: public Ui_MemoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMO_H
