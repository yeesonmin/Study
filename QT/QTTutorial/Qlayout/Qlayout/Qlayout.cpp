#include "Qlayout.h"

Qlayout::Qlayout(QWidget *parent)
    : QWidget(parent)
{
    //ui.setupUi(this);

    //가로 방향 레이아웃
    QHBoxLayout* hboxLayout = new QHBoxLayout();
    QPushButton* btn[6];

    QString btnStr[6] = { "One", "Two", "Three", "Four", "Six", "Seven" };
    for (int i = 0; i < 6; i++)
    {
        btn[i] = new QPushButton(btnStr[i]);
        hboxLayout->addWidget(btn[i]);
    }

    //세로방향 레이아웃
    QVBoxLayout* vboxLayout = new QVBoxLayout();
    QPushButton* vbtn[6];

    QString vbtnStr[3] = { "Movie", "Drama", "Animation" };

    for (int i = 0; i < 3; i++)
    {
        vbtn[i] = new QPushButton(vbtnStr[i]);
        vboxLayout->addWidget(vbtn[i]);
    }

    //그리드
    QGridLayout* gridLayout = new QGridLayout();
    QPushButton* gbtn[5];

    for (int i = 0; i < 5; i++)
    {
        gbtn[i] = new QPushButton(btnStr[i]);
    }

    gridLayout->addWidget(gbtn[0], 0, 0);
    gridLayout->addWidget(gbtn[1], 0, 1);
    gridLayout->addWidget(gbtn[2], 1, 0, 1, 2);
    gridLayout->addWidget(gbtn[3], 2, 0);
    gridLayout->addWidget(gbtn[4], 2, 1);


    
    QVBoxLayout* defaultLayout = new QVBoxLayout();

    defaultLayout->addLayout(hboxLayout);
    defaultLayout->addLayout(vboxLayout);
    defaultLayout->addLayout(gridLayout);

    setLayout(defaultLayout);
}
