#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Memo.h"

class Memo : public QMainWindow
{
    Q_OBJECT

public:
    Memo(QWidget *parent = Q_NULLPTR);

private:
    Ui::MemoClass ui;
};
