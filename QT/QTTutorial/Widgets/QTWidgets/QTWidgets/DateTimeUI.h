#ifndef DATETIMEUI_H
#define DATETIMEUI_H

#include <QDate>
#include <QDateTime>
#include <QtWidgets/QDateTimeEdit>

//date와 시간을 함께 다룰수 있다.
class DateTimeUI : public QWidget
{
    Q_OBJECT

public:
    DateTimeUI(QWidget* parent = 0);
    ~DateTimeUI();

private:


};
#endif // DATETIMEUI_H

