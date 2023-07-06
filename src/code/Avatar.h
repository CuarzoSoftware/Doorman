#ifndef AVATAR_H
#define AVATAR_H

#include <QGraphicsDropShadowEffect>
#include <QWidget>

class Avatar : public QWidget
{
    Q_OBJECT
public:
    explicit Avatar(uint size,
                    uint borderSize,
                    const QPixmap &pixmap,
                    QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;
    QGraphicsDropShadowEffect shadowEffect = QGraphicsDropShadowEffect();

    uint size;
    uint borderSize;
    QPixmap pixmap;
signals:

};

#endif // AVATAR_H
