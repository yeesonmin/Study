#include "CheckBox.h"

CheckBox::CheckBox(QWidget* parent) : QWidget(parent)
{
    setWindowTitle("QCheckBox");
    QString str1[3] = { "Game", "Office", "Develop" };
    QString str2[3] = { "P&rogramming", "Q&t", "O&S" };

    int xpos = 30;
    int ypos = 30;

    chk_group[0] = new QButtonGroup(this);
    chk_group[1] = new QButtonGroup(this);

    for (int i = 0; i < 3; i++)
    {
        exclusive[i] = new QCheckBox(str1[i], this);
        exclusive[i]->setGeometry(xpos, ypos, 100, 30);
        chk_group[0]->addButton(exclusive[i]);

        non_exclusive[i] = new QCheckBox(str2[i], this);
        non_exclusive[i]->setGeometry(xpos + 120, ypos, 100, 30);
        chk_group[1]->addButton(non_exclusive[i]);

        connect(exclusive[i], SIGNAL(clicked()), this, SLOT(chkChanged()));

        ypos += 40;
    }

    chk_group[0]->setExclusive(false);//그룹에서 중복선택 허용
    chk_group[1]->setExclusive(true);// 그룹에서 단일항목만 허용

    exclusive[0]->setIcon(QIcon(":resources/resources/browser.png"));
    exclusive[1]->setIcon(QIcon(":resources/resources/calendar.png"));
    exclusive[2]->setIcon(QIcon(":resources/resources/chat.png"));

    non_exclusive[0]->setIcon(QIcon(":resources/resources/editor.png"));
    non_exclusive[1]->setIcon(QIcon(":resources/resources/mail.png"));
    non_exclusive[2]->setIcon(QIcon(":resources/resources/users.png"));

}

void CheckBox::chkChanged() {
    for (int i = 0; i < 3; i++)
    {
        if (exclusive[i]->checkState())
        {
            qDebug("checkbox %d selected ", i + 1);
        }
    }
}
CheckBox::~CheckBox()
{
}
