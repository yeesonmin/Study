#include "SpinBoxUI.h"


SpinBoxUI::SpinBoxUI(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("QSpinBox");
    int ypos = 30;
    int val[3] = { 50, 100, 200 };
    double double_val[3] = { 50.5, 127.32, 171.342 };

    for (int i = 0; i < 3; i++)
    {
        spin[i] = new QSpinBox(this);
        spin[i]->setMinimum(10);
        spin[i]->setMaximum(300);
        spin[i]->setValue(val[i]);
        spin[i]->setGeometry(10, ypos, 100, 30);

        doublespin[i] = new QDoubleSpinBox(this);//double °ª ÀÌ¿ë
        doublespin[i]->setMinimum(10.0);
        doublespin[i]->setMaximum(300.0);
        doublespin[i]->setValue(double_val[i]);
        doublespin[i]->setGeometry(120, ypos, 100, 30);

        spin[i]->setPrefix("$ ");
        doublespin[i]->setSuffix(" mm");

        ypos += 40;
    }

    connect(spin[0], SIGNAL(valueChanged(int)),
        this, SLOT(valueChange()));

    connect(doublespin[0], SIGNAL(valueChanged(double)),
        this, SLOT(double_valueChange()));

}

void SpinBoxUI::valueChange()
{
    qDebug("Change value : %d", spin[0]->value());
}

void SpinBoxUI::double_valueChange()
{
    qDebug("Change double value : %3.2f", doublespin[0]->value());
}

SpinBoxUI::~SpinBoxUI()
{

}