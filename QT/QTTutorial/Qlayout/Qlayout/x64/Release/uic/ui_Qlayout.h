/********************************************************************************
** Form generated from reading UI file 'Qlayout.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLAYOUT_H
#define UI_QLAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QlayoutClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QlayoutClass)
    {
        if (QlayoutClass->objectName().isEmpty())
            QlayoutClass->setObjectName(QString::fromUtf8("QlayoutClass"));
        QlayoutClass->resize(600, 400);
        menuBar = new QMenuBar(QlayoutClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QlayoutClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QlayoutClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QlayoutClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QlayoutClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QlayoutClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QlayoutClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QlayoutClass->setStatusBar(statusBar);

        retranslateUi(QlayoutClass);

        QMetaObject::connectSlotsByName(QlayoutClass);
    } // setupUi

    void retranslateUi(QMainWindow *QlayoutClass)
    {
        QlayoutClass->setWindowTitle(QCoreApplication::translate("QlayoutClass", "Qlayout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QlayoutClass: public Ui_QlayoutClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLAYOUT_H
