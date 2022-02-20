#ifndef PROGRESSBARUI_H
#define PROGRESSBARUI_H

#include <QProgressBar>

class ProgressbarUI : public QWidget
{
    Q_OBJECT

public:
    ProgressbarUI(QWidget* parent = 0);
    ~ProgressbarUI();

private:
    QProgressBar* progress[4];

};

#endif // PROGRESSBARUI_H

