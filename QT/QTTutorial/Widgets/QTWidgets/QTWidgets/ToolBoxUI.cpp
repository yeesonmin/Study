#include "ToolBoxUI.h"

ToolBoxUI::ToolBoxUI(QWidget* parent)
    : QWidget(parent)
{
    box = new QToolBox(this);
    lay = new QHBoxLayout(this);

    but1 = new QPushButton("DataBase - 1", this);
    but2 = new QPushButton("Network - 2", this);
    but3 = new QPushButton("Graphics - 3", this);

    box->addItem(but1, "DataBase");
    box->addItem(but2, "Network");
    box->addItem(but3, "Graphics");

    lay->addWidget(box);
    setLayout(lay);

    connect(box, SIGNAL(currentChanged(int)),
        this, SLOT(changedTab(int)));
}

void ToolBoxUI::changedTab(int index)
{
    qDebug("current index : %d", index);
}

ToolBoxUI::~ToolBoxUI()
{

}