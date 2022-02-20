#include "ToolBarUI.h"


ToolBarUI::ToolBarUI(QWidget* parent) : QWidget(parent)
{
    QToolBar* toolbar = new QToolBar(this);

    QAction* act[5];

    act[0] = new QAction(QIcon(":resources/resources/browser.png"), "Browser", this);
    act[1] = new QAction(QIcon(":resources/resources/calendar.png"), "calendar", this);
    act[2] = new QAction(QIcon(":resources/resources/chat.png"), "chat", this);
    act[3] = new QAction(QIcon(":resources/resources/editor.png"), "editor", this);
    act[4] = new QAction(QIcon(":resources/resources/mail.png"), "mail", this);

    act[0]->setShortcut(Qt::Key_Control | Qt::Key_E);
    act[0]->setToolTip("This is a ToolTip.");

    toolbar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    for (int i = 0; i < 5; i++)
    {
        toolbar->addAction(act[i]);
    }

    connect(act[0], SIGNAL(triggered()), this, SLOT(trigger1()));
    connect(act[1], SIGNAL(triggered()), this, SLOT(trigger2()));
    connect(act[2], SIGNAL(triggered()), this, SLOT(trigger3()));
    connect(act[3], SIGNAL(triggered()), this, SLOT(trigger4()));
    connect(act[4], SIGNAL(triggered()), this, SLOT(trigger5()));
}

void ToolBarUI::trigger1()
{
    qDebug("Tool Button 1 click.");
}

void ToolBarUI::trigger2()
{
    qDebug("Tool Button 2 click.");
}

void ToolBarUI::trigger3()
{
    qDebug("Tool Button 3 click.");
}

void ToolBarUI::trigger4()
{
    qDebug("Tool Button 4 click.");
}

void ToolBarUI::trigger5()
{
    qDebug("Tool Button 5 click.");
}


ToolBarUI::~ToolBarUI()
{

}