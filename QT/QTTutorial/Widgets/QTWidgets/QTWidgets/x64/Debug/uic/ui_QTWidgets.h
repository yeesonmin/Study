/********************************************************************************
** Form generated from reading UI file 'QTWidgets.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETS_H
#define UI_QTWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTWidgetsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTWidgetsClass)
    {
        if (QTWidgetsClass->objectName().isEmpty())
            QTWidgetsClass->setObjectName(QString::fromUtf8("QTWidgetsClass"));
        QTWidgetsClass->resize(600, 400);
        menuBar = new QMenuBar(QTWidgetsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QTWidgetsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTWidgetsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QTWidgetsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QTWidgetsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QTWidgetsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QTWidgetsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QTWidgetsClass->setStatusBar(statusBar);

        retranslateUi(QTWidgetsClass);

        QMetaObject::connectSlotsByName(QTWidgetsClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTWidgetsClass)
    {
        QTWidgetsClass->setWindowTitle(QCoreApplication::translate("QTWidgetsClass", "QTWidgets", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QTWidgetsClass: public Ui_QTWidgetsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETS_H
