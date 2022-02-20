#ifndef SIZEGRIPUI_H
#define SIZEGRIPUI_H

#include <QSizeGrip>
#include <QBoxLayout>
#include <QTextEdit>
#include <QSplitter>

// SubWindow 클래스 위젯
class SubWindow : public QWidget
{
    Q_OBJECT
public:
    SubWindow(QWidget* parent = nullptr) : QWidget(parent, Qt::SubWindow)
    {
        QSizeGrip* sizegrip = new QSizeGrip(this);
        sizegrip->setFixedSize(sizegrip->sizeHint());

        this->setLayout(new QVBoxLayout);
        //this->layout()->setMargin(0); setMargin 사라짐.
        this->layout();

        layout()->addWidget(new QTextEdit);

        sizegrip->setWindowFlags(Qt::WindowStaysOnTopHint);
        sizegrip->raise();
    }

    QSize sizeHint() const
    {
        return QSize(200, 100);
    }
};

// Widget 클래스 위젯, SubWindow의 부모 클래스 위젯
class SizeGripUI : public QWidget
{
    Q_OBJECT

public:
    SizeGripUI(QWidget* parent = nullptr);
    ~SizeGripUI();
};
#endif // SIZEGRIPUI_H

