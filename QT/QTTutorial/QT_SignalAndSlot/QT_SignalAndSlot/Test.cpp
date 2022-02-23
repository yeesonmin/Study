#include "Test.h"

Test::Test(QWidget* parent)
    : QWidget(parent)
{
    lbl = new QLabel("", this);
    lbl->setGeometry(10, 10, 250, 40);

    SignalSlot myObject;


    // New Style
    //������Ʈ, �ñ׳�, �����Լ��� �ִ� ��,����
    //���ڴ� �ϳ��� ����
    connect(&myObject, &SignalSlot::valueChanged, this, &Test::setValue);

    //Old Style
    /*������ ���� ����
    connect(&myObject, SIGNAL(valueChanged(int)),
            this,      SLOT(setValue(int)));
    */

    myObject.setValue(50);
}


void Test::setValue(int val)
{
    QString labelText;
    labelText.append(QString::fromLocal8Bit("�ñ׳� �߻�, Value : %1").arg(val));
    lbl->setText(labelText.toUtf8());
}

Test::~Test()
{
}