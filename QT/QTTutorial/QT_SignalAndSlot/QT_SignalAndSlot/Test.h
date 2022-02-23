#ifndef TEST_H
#define TEST_H

#include <QLabel>
class Test : public QWidget
{
    Q_OBJECT

public:
    Test(QWidget* parent = nullptr);
    ~Test();

private:
    QLabel* lbl;

public slots:
    void setValue(int val);
};

class SignalSlot : public QObject
{
    Q_OBJECT

public:
    void setValue(int val) {
        emit valueChanged(val);
    }

signals:
    void valueChanged(int newValue);

private:
    int m_value;
};
#endif // WIDGET_H

