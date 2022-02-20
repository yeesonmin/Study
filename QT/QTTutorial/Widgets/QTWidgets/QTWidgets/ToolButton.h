
#ifndef TOOLBUTTON_H
#define TOOLBUTTON_H

#include <QWidget>
#include <QToolButton>
#include <QToolBar>
#include <QVBoxLayout>
#include <QIcon>

class ToolButton : public QWidget
{
    Q_OBJECT

public:
    ToolButton(QWidget* parent = 0);
    ~ToolButton();
};

#endif // TOOLBUTTON_H