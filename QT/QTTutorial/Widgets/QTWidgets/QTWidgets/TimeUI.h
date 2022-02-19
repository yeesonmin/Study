#ifndef TIMEUI_H
#define TIMEUI_H

#include <QTime>
#include <QTimeEdit>
#include <QLabel>
#include <QElapsedTimer>

class TimeUI : public QWidget
{
    Q_OBJECT

public:
    TimeUI(QWidget* parent = nullptr);
    ~TimeUI();
};

#endif // TIMEUI_H