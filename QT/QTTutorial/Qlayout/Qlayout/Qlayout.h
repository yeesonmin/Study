#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Qlayout.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLayout>
#include <QPushButton>

class Qlayout : public QWidget
{
    Q_OBJECT

public:
    Qlayout(QWidget *parent = Q_NULLPTR);

private:
    Ui::QlayoutClass ui;
};
