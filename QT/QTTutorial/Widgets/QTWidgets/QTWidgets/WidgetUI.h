

#ifndef WIDGETUI_H
#define WIDGETUI_H

#include <QPainter>
#include <QtEvents>
#include <QLineEdit>

class WidgetUI : public QWidget
{
    Q_OBJECT

public:
    WidgetUI(QWidget* parent = nullptr);
    ~WidgetUI();

private:
    QLineEdit* edit;

protected:
    virtual void paintEvent(QPaintEvent* event);
    virtual void resizeEvent(QResizeEvent* event);

    virtual void mousePressEvent(QMouseEvent* event);
    virtual void mouseReleaseEvent(QMouseEvent* event);
    virtual void mouseDoubleClickEvent(QMouseEvent* event);
    virtual void mouseMoveEvent(QMouseEvent* event);

    virtual void keyPressEvent(QKeyEvent* event);
    virtual void keyReleaseEvent(QKeyEvent* event);
    virtual void focusInEvent(QFocusEvent* event);
    virtual void focusOutEvent(QFocusEvent* event);

};

#endif // WIDGETUI_H


