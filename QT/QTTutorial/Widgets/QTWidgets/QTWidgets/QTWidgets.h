#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QTWidgets.h"

class QTWidgets : public QMainWindow
{
    Q_OBJECT

public:
    QTWidgets(QWidget *parent = Q_NULLPTR);

private:
    Ui::QTWidgetsClass ui;
};
