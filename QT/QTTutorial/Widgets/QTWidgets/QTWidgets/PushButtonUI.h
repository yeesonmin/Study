#ifndef PUSHBUTTONUI_H
#define PUSHBUTTONUI_H

#include <QtWidgets/QPushButton>
#include <QtWidgets/QFocusFrame>


class PushButtonUI : public QWidget
{
    Q_OBJECT

public:
    PushButtonUI(QWidget* parent = 0);
    ~PushButtonUI();

private slots:
    void btn_click();
    void btn_pressed();
    void btn_released();

};
#endif // PUSHBUTTONUI_H