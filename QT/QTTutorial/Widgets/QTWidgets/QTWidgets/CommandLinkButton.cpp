#include"CommandLinkButton.h"


CommandLinkButton::CommandLinkButton(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("QCommandLinkButton");
    setFixedSize(QSize(300, 100));

    cmmBtn = new QCommandLinkButton("Vision", "Vision Project", this);
    cmmBtn->setFlat(true);

    connect(cmmBtn, SIGNAL(clicked()), this, SLOT(clickFunc()));
}

void CommandLinkButton::clickFunc()
{
    qDebug("QCommandLinkButton Click.");
}
CommandLinkButton::~CommandLinkButton()
{
}
