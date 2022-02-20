#include "RadioButtonUI.h"

RadioButtonUI::RadioButtonUI(QWidget* parent)
    : QWidget(parent)
{
    setWindowTitle("QRadioButton");
    QRadioButton* radio1[3];
    QRadioButton* radio2[3];

    QString str1[3] = { "Computer", "Notebook", "Tablet" };

    int ypos = 30;
    for (int i = 0; i < 3; i++)
    {
        radio1[i] = new QRadioButton(str1[i], this);
        radio1[i]->setGeometry(10, ypos, 150, 30);

        ypos += 40;
    }

    QString str2[3] = { "In-Vehicle", "Smart TV", "Mobile" };

    ypos = 30;
    for (int i = 0; i < 3; i++)
    {
        radio2[i] = new QRadioButton(str2[i], this);
        if (i == 2)
            radio2[i]->setChecked(true);

        radio2[i]->setGeometry(180, ypos, 150, 30);

        ypos += 40;
    }

    QButtonGroup* group1 = new QButtonGroup(this);
    QButtonGroup* group2 = new QButtonGroup(this);

    group1->addButton(radio1[0]);
    group1->addButton(radio1[1]);
    group1->addButton(radio1[2]);

    group2->addButton(radio2[0]);
    group2->addButton(radio2[1]);
    group2->addButton(radio2[2]);


}

RadioButtonUI::~RadioButtonUI()
{

}