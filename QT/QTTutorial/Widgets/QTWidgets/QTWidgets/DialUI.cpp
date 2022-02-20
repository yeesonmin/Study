#include "DialUI.h"

DialUI::DialUI(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("QDial");
    int xpos = 30;

    for (int i = 0; i < 3; i++, xpos += 110)
    {
        dial[i] = new QDial(this);
        dial[i]->setRange(0, 100);
        dial[i]->setGeometry(xpos, 30, 100, 100);
    }

    dial[0]->setNotchesVisible(true);
    connect(dial[0], &QDial::valueChanged, this, &DialUI::changedData);
}

void DialUI::changedData()
{
    qDebug("QDial 1 value : %d", dial[0]->value());
}

DialUI::~DialUI()
{

}