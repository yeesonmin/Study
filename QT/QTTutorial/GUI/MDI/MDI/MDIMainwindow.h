#ifndef QMDIMAINWINDOW_H
#define QMDIMAINWINDOW_H

#include <QMainWindow>
#include <QObject>

class MDIMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MDIMainWindow(QWidget *parent = nullptr);
};

#endif // QMDIMAINWINDOW_H
