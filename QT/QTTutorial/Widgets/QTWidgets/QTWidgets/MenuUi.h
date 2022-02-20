#ifndef MENUUI_H
#define MENUUI_H

#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QLabel>

class MenuUi : public QWidget
{
    Q_OBJECT

public:
    MenuUi(QWidget* parent = nullptr);
    ~MenuUi();

private:
    QMenu* menu[3];
    QMenuBar* menuBar;
    QLabel* lbl;
    QAction* act[2];

private slots:
    void trigerMenu(QAction* act);

};
#endif // MENUUI_H