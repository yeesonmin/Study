#include "Test2.h"
#include "QT_SignalAndSlot.h"
Test2::Test2(QWidget* parent) : QWidget(parent)
{
    ld = new QLineEdit("", this);
    ld->setGeometry(10, 10, 250, 40);

    pb = new QPushButton("PushButton", this);
    pb->setGeometry(10, 60, 250, 40);


	connect(pb, SIGNAL(pressed()), this, SLOT(slotPbtButtonClick()));

    cnt1 = new Counter("counter 1");
    cnt2 = new Counter("counter 2");

    //    connect(cnt1, SIGNAL(valueChagned(int)),
    //            cnt2, SLOT(setValue(int)));6

	connect(cnt1, SIGNAL(valueChagned(int)), cnt2, SIGNAL(valueChagned(int)));//cnt1 시그널 => cnt2 시그널

	connect(cnt2, SIGNAL(valueChagned(int)), cnt2, SLOT(setValue(int)));//cnt2 슬롯 동작

}

void Test2::slotPbtButtonClick()
{
    qint32 num = ld->text().toInt();

    emit cnt1->valueChagned(num);
}

Test2::~Test2()
{
   
}
Counter::Counter(QString mStr)
{
    mString = mStr;
    mValue = 0;
}

void Counter::setValue(int mValue)
{
    mValue = mValue;

    qDebug() << mString << ", mValue : " << mValue;
    //qDebug() << "mValue : " << mValue;
}