#ifndef SPINBOX_H
#define SPINBOX_H

#include <QtWidgets/QSpinBox>
#include <QtWidgets/QDoubleSpinBox>

class SpinBoxUI : public QWidget
{
    Q_OBJECT

public:
    SpinBoxUI(QWidget* parent = 0);
    ~SpinBoxUI();

private:
    QSpinBox* spin[3];
    QDoubleSpinBox* doublespin[3];

private slots:
    void valueChange();
    void double_valueChange();

};

#endif // SPINBOX_H

