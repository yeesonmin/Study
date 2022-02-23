#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QT_SignalAndSlot.h"

class QT_SignalAndSlot : public QMainWindow
{
    Q_OBJECT

public:
    QT_SignalAndSlot(QWidget *parent = Q_NULLPTR);

private:
    Ui::QT_SignalAndSlotClass ui;
};
