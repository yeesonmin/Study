

#ifndef TOOLBARUI_H
#define TOOLBARUI_H

#include <QToolBar>
#include <QAction>

class ToolBarUI : public QWidget
{
    Q_OBJECT

public:
    ToolBarUI(QWidget* parent = 0);
    ~ToolBarUI();

private slots:
    void trigger1();
    void trigger2();
    void trigger3();
    void trigger4();
    void trigger5();
};

#endif // TOOLBARUI_H
