/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox1;
    QSlider *Slider1;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBox2;
    QSlider *Slider2;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spinBox3;
    QSlider *Slider3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        spinBox1 = new QSpinBox(centralwidget);
        spinBox1->setObjectName(QString::fromUtf8("spinBox1"));
        spinBox1->setMaximum(100);

        horizontalLayout->addWidget(spinBox1);

        Slider1 = new QSlider(centralwidget);
        Slider1->setObjectName(QString::fromUtf8("Slider1"));
        Slider1->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(Slider1);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        spinBox2 = new QSpinBox(centralwidget);
        spinBox2->setObjectName(QString::fromUtf8("spinBox2"));
        spinBox2->setMaximum(100);

        horizontalLayout_2->addWidget(spinBox2);

        Slider2 = new QSlider(centralwidget);
        Slider2->setObjectName(QString::fromUtf8("Slider2"));
        Slider2->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(Slider2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        spinBox3 = new QSpinBox(centralwidget);
        spinBox3->setObjectName(QString::fromUtf8("spinBox3"));
        spinBox3->setMaximum(100);

        horizontalLayout_3->addWidget(spinBox3);

        Slider3 = new QSlider(centralwidget);
        Slider3->setObjectName(QString::fromUtf8("Slider3"));
        Slider3->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(Slider3);


        verticalLayout->addLayout(horizontalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
