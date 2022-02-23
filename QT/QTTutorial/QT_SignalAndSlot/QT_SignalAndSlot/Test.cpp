#include "Test.h"

Test::Test(QWidget* parent)
    : QWidget(parent)
{
    lbl = new QLabel("", this);
    lbl->setGeometry(10, 10, 250, 40);

    SignalSlot myObject;


    // New Style
    //오프젝트, 시그널, 슬롯함수가 있는 곳,슬롯
    //인자는 하나만 가능
    connect(&myObject, &SignalSlot::valueChanged, this, &Test::setValue);

    //Old Style
    /*여러개 인자 가능
    connect(&myObject, SIGNAL(valueChanged(int)),
            this,      SLOT(setValue(int)));
    */

    myObject.setValue(50);
}


void Test::setValue(int val)
{
    QString labelText;
    labelText.append(QString::fromLocal8Bit("시그널 발생, Value : %1").arg(val));
    lbl->setText(labelText.toUtf8());
}

Test::~Test()
{
}