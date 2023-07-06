#include "IconButton.h"
#include "Shared.h"
#include <QSvgRenderer>
#include <QPainter>

IconButton::IconButton(const QString &iconPath, const QSize &size, QColor color, QWidget *parent) : QWidget(parent)
{
    QSvgRenderer svgRenderer(iconPath, this);
    icon = QPixmap(size*SHARED()->pixelRatio);
    icon.fill(Qt::transparent);
    QPainter painter(&icon);
    svgRenderer.render(&painter);
    painter.setPen(Qt::NoPen);
    painter.setBrush(color);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.drawRect(icon.rect());
    painter.end();
    icon.setDevicePixelRatio(SHARED()->pixelRatio);
    setCursor(Qt::PointingHandCursor);
    setFixedSize(size);

    shadowEffect.setBlurRadius(6);
    shadowEffect.setColor(QColor(0,0,0,100));
    shadowEffect.setOffset(0, 0);
    setGraphicsEffect(&shadowEffect);
}

void IconButton::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.setRenderHint(QPainter::SmoothPixmapTransform, true);
    p.setPen(Qt::NoPen);
    p.setBrush(Qt::NoBrush);
    p.drawPixmap(rect(), icon);
}
