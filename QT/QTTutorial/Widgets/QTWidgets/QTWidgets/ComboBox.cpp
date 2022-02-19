#include "ComboBox.h"

ComboBox::ComboBox(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("QComboBox");

    combo = new QComboBox(this);
    combo->setGeometry(50, 50, 200, 30);

    combo->addItem(QIcon(":resources/resources/browser.png"), "Application");
    combo->addItem(QIcon(":resources/resources/browser.png"), "Graphics");
    combo->addItem("Database");
    combo->addItem("Network");

    connect(combo, SIGNAL(currentIndexChanged(int)), this, SLOT(valueChanged()));

    QString str;
    str = combo->currentText();

    qDebug("Total Items : %d", combo->count());
}

void ComboBox::valueChanged()
{
    int current_index = combo->currentIndex();
    qDebug("Current ComboBox index : %d", current_index);
}

ComboBox::~ComboBox()
{
}
