#ifndef ICONBUTTON_H
#define ICONBUTTON_H

#include <QWidget>
#include <QGraphicsDropShadowEffect>

class IconButton : public QWidget
{
public:
    IconButton(const QString &iconPath, const QSize &size = QSize(28, 28), QColor color = Qt::white, QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *) override;
    QGraphicsDropShadowEffect shadowEffect;
    QPixmap icon;
};

#endif // ICONBUTTON_H
