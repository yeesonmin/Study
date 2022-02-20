#ifndef DIALUI_H
#define DIALUI_H

#include <QtWidgets/QDial>

class DialUI : public QWidget
{
    Q_OBJECT

public:
    DialUI(QWidget* parent = 0);
    ~DialUI();

private:
    QDial* dial[3];

private slots:
    void changedData();

};


#endif // DIALUI_H
