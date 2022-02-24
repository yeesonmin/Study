#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MDI.h"
#include "MDIMainwindow.h"

class MDI : public QMainWindow
{
    Q_OBJECT

public:
    MDI(QWidget *parent = Q_NULLPTR);
    ~MDI();
private:

private slots:
    void newFile();
    void open();
};
