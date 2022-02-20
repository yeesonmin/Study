#include "WidgetUI.h"
WidgetUI::WidgetUI(QWidget* parent)
    : QWidget(parent)
{
    edit = new QLineEdit("", this);
    edit->setGeometry(120, 20, 100, 30);
}

void WidgetUI::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QString img_full_name;

    QPainter painter(this);

    img_full_name = QString(":resources/resources//browser.png");

    QImage image(img_full_name);
    painter.drawPixmap(0, 0,
        QPixmap::fromImage(image.scaled(100, 100,
            Qt::IgnoreAspectRatio,
            Qt::SmoothTransformation)));

    painter.end();
}

void WidgetUI::resizeEvent(QResizeEvent* event)
{
    Q_UNUSED(event);

    qDebug("[Resize Event call]");
    qDebug("width : %d, height : %d", this->width(), this->height());
}

void WidgetUI::mousePressEvent(QMouseEvent* event)
{
    Q_UNUSED(event);

    qDebug("[Mouse Press] x, y : %d , %d ", event->x(), event->y());
}

void WidgetUI::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    qDebug("[Mouse Release] x, y : %d , %d ", event->x(), event->y());
}

void WidgetUI::mouseDoubleClickEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    qDebug("[Mouse Double Click] x, y : %d , %d ", event->x(), event->y());
}

void WidgetUI::mouseMoveEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    qDebug("[Mouse Move] x, y : %d , %d ", event->x(), event->y());
}

void WidgetUI::keyPressEvent(QKeyEvent* event)
{
    Q_UNUSED(event);
    qDebug("Key Press Event.");

    switch (event->key())
    {
    case Qt::Key_A:

        if (event->modifiers())
            qDebug("A");
        else
            qDebug("a");

        qDebug("%x", event->key());

        break;

    default:
        break;
    }
}

void WidgetUI::keyReleaseEvent(QKeyEvent* event)
{
    Q_UNUSED(event);
    qDebug("Key Release Event.");
}

void WidgetUI::focusInEvent(QFocusEvent* event)
{
    Q_UNUSED(event);
    qDebug("focusInEvent Event.");
}

void WidgetUI::focusOutEvent(QFocusEvent* event)
{
    Q_UNUSED(event);
    qDebug("focusOutEvent Event.");
}

WidgetUI::~WidgetUI()
{

}






