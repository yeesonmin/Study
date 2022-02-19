#ifndef DATE_H
#define DATE_H

#include <QDate>
#include <QDateEdit>
#include <QLabel>

class Date : public QWidget
{
	Q_OBJECT
public:
	Date(QWidget* parent = nullptr);
	~Date();

private:
	QDateEdit* dateEdit[4];
	QLabel* lbl[6];
};

#endif // DATE_H