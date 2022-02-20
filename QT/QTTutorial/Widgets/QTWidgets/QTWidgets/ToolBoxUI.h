
#ifndef TOOLBOXUI_H
#define TOOLBOXUI_H

#include <QWidget>
#include <QToolBox>
#include<QHBoxLayout>
#include<QPushButton>

class ToolBoxUI : public QWidget
{
    Q_OBJECT

public:
    ToolBoxUI(QWidget* parent = nullptr);
    ~ToolBoxUI();

private:
    QToolBox* box;
    QHBoxLayout* lay;
    QPushButton* but1;
    QPushButton* but2;
    QPushButton* but3;

private slots:
    void changedTab(int index);
};

#endif // TOOLBOXUI_H


