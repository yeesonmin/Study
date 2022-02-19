#ifndef CHECKBOX_H
#define CHECKBOX_H

#include <QtWidgets/QCheckBox>
#include <QtWidgets/QButtonGroup>

class CheckBox : public QWidget
{
	Q_OBJECT//�̰� �־�� signal,slot ���� �۵�
public:
	CheckBox(QWidget* parent = 0);
	~CheckBox();

private:
	QButtonGroup* chk_group[2];

	QCheckBox* exclusive[3];
	QCheckBox* non_exclusive[3];

private slots:
	void chkChanged();
};

#endif // CHECKBOX_H