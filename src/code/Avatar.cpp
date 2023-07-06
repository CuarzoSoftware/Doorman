#include "Avatar.h"
#include "Shared.h"
#include "qpainter.h"

Avatar::Avatar(uint size,
               uint borderSize,
               const QPixmap &pixmap,
               QWidget *parent) : QWidget{parent}
{
    this->size = size;
    this->borderSize = borderSize;
    this->pixmap = pixmap;
    shadowEffect.setBlurRadius(18);
    shadowEffect.setColor(SHARED()->shadowColor);
    shadowEffect.setOffset(0, 0);
    setGraphicsEffect(&shadowEffect);
    setFixedSize(size, size);
}

void Avatar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setRenderHint(QPainter::RenderHint::SmoothPixmapTransform);

    QPen pen(Qt::white);
    pen.setWidth(borderSize);
    p.setPen(pen);

    p.setBrush(pixmap);

    p.drawEllipse(rect().x() + borderSize,
                  rect().y() + borderSize,
                  rect().width() - (borderSize << 1),
                  rect().height() - (borderSize << 1));
}
