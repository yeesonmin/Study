#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <QComboBox>

class ComboBox : public QWidget
{
	Q_OBJECT
public:
	ComboBox(QWidget* parent = nullptr);
	~ComboBox();

private:
	QComboBox* combo;

private slots:
	void valueChanged();
};

#endif // COMBOBOX_H