#ifndef SLIDERUI_H
#define SLIDERUI_H

#include <QSlider>
#include <QLabel>

class SliderUI : public QWidget
{
    Q_OBJECT

public:
    SliderUI(QWidget* parent = 0);
    ~SliderUI();

private:
    QSlider* slider[6];
    QLabel* lbl[3];

private slots:
    void valueChanged1(int value);
    void valueChanged2(int value);
    void valueChanged3(int value);

};

#endif // SLIDERUI_H
