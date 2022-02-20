#ifndef LINEEDITUI_H
#define LINEEDITUI_H


#include <QLineEdit>
#include <QLabel>

class LineEditUI : public QWidget
{
    Q_OBJECT

public:
    LineEditUI(QWidget* parent = nullptr);
    ~LineEditUI();

private:
    QLineEdit* edit[5];
    QLabel* lbl;

private slots:
    void textChanged(QString str);

};
#endif // LINEEDITUI_H

