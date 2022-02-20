
#ifndef TABWIDGETUI_H
#define TABWIDGETUI_H

#include <QTabWidget>
#include <QPushButton>

class TabwidgetUI : public QWidget
{
    Q_OBJECT

public:
    TabwidgetUI(QWidget* parent = 0);
    ~TabwidgetUI();

private slots:
    void currentTab(int index);

};

#endif // TABWIDGETUI_H
