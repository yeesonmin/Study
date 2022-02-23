/********************************************************************************
** Form generated from reading UI file 'QT_SignalAndSlot.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QT_SIGNALANDSLOT_H
#define UI_QT_SIGNALANDSLOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QT_SignalAndSlotClass
{
public:
    QWidget *centralWidget;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QT_SignalAndSlotClass)
    {
        if (QT_SignalAndSlotClass->objectName().isEmpty())
            QT_SignalAndSlotClass->setObjectName(QString::fromUtf8("QT_SignalAndSlotClass"));
        QT_SignalAndSlotClass->resize(600, 400);
        centralWidget = new QWidget(QT_SignalAndSlotClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(10, 10, 341, 22));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(360, 10, 75, 24));
        QT_SignalAndSlotClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QT_SignalAndSlotClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        QT_SignalAndSlotClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QT_SignalAndSlotClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QT_SignalAndSlotClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QT_SignalAndSlotClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QT_SignalAndSlotClass->setStatusBar(statusBar);

        retranslateUi(QT_SignalAndSlotClass);

        QMetaObject::connectSlotsByName(QT_SignalAndSlotClass);
    } // setupUi

    void retranslateUi(QMainWindow *QT_SignalAndSlotClass)
    {
        QT_SignalAndSlotClass->setWindowTitle(QCoreApplication::translate("QT_SignalAndSlotClass", "QT_SignalAndSlot", nullptr));
        pushButton->setText(QCoreApplication::translate("QT_SignalAndSlotClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QT_SignalAndSlotClass: public Ui_QT_SignalAndSlotClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QT_SIGNALANDSLOT_H
