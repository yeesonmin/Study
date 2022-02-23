#ifndef TEST2_H
#define TEST2_H
#include <QObject>
#include <QWidget>
#include <QDebug>
#include <QLineEdit>
#include <QpushButton>

class Counter : public QObject
{
    Q_OBJECT

public:
    Counter(QString mStr);

private:
    QString mString;
    int mValue;

signals:
    void valueChagned(int mValue);

public slots:
    void setValue(int mValue);
};



class Test2 : public QWidget
{
    Q_OBJECT

public:
    explicit Test2(QWidget* parent = 0);
    ~Test2();

private:
    Counter* cnt1;
    Counter* cnt2;
    QLineEdit* ld;
    QPushButton* pb;

private slots:
    void slotPbtButtonClick();

};



#endif // TEST2_H
