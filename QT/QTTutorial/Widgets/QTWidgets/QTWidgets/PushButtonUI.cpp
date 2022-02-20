#include "PushButtonUI.h"

PushButtonUI::PushButtonUI(QWidget* parent)
    : QWidget(parent)
{
    setWindowTitle("QPushButton");

    QPushButton* btn[3];

    int ypos = 30;
    for (int i = 0; i < 3; i++)
    {
        btn[i] = new QPushButton(QString("Frame's button %1").arg(i), this);
        btn[i]->setGeometry(10, ypos, 300, 40);
        ypos += 50;
    }

    connect(btn[0], &QPushButton::clicked, this, &PushButtonUI::btn_click);
    connect(btn[0], &QPushButton::pressed, this, &PushButtonUI::btn_pressed);
    connect(btn[0], &QPushButton::released, this, &PushButtonUI::btn_released);

    QFocusFrame* btn_frame = new QFocusFrame(this);
    btn_frame->setWidget(btn[0]);
    btn_frame->setAutoFillBackground(true);

}

void PushButtonUI::btn_click()
{
    qDebug("Button Click");
}

void PushButtonUI::btn_pressed()
{
    qDebug("Button Pressed");
}

void PushButtonUI::btn_released()
{
    qDebug("Button Relased");
}

PushButtonUI::~PushButtonUI()
{
}
