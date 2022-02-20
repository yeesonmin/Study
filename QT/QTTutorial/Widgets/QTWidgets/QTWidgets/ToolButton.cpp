#include "ToolButton.h"


ToolButton::ToolButton(QWidget* parent)
    : QWidget(parent)
{
    QToolBar* tool = new QToolBar(this);
    QVBoxLayout* layout = new QVBoxLayout;

    QToolButton* button = new QToolButton;
    button->setIcon(QIcon(":resources/resources/browser.png"));

    QToolButton* button1 = new QToolButton;
    button1->setIcon(QIcon(":resources/resources/calendar.png"));

    QToolButton* button2 = new QToolButton;
    button2->setIcon(QIcon(":resources/resources/chat.png"));

    tool->addWidget(button);
    tool->addWidget(button1);
    tool->addSeparator();
    tool->addWidget(button2);
    layout->addWidget(tool);

    this->setLayout(layout);
}

ToolButton::~ToolButton()
{
}
