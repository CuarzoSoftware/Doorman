#ifndef USERVIEW_H
#define USERVIEW_H

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>
#include <QGraphicsDropShadowEffect>

#include "Shared.h"
#include "Avatar.h"

class MainWindow;

class UserView : public QWidget
{
public:
    UserView(MainWindow *mainWindow, const QString &name, const QString &home, int id);

    Avatar avatar = Avatar(SHARED()->avatarSize,
                           SHARED()->avatarBorderSize,
                           SHARED()->defaultAvatar,
                           this);

    QVBoxLayout vbox = QVBoxLayout(this);
    QLabel nameLabel = QLabel(this);
    QString home;
    int id;

    MainWindow *mainWindow;

    QGraphicsDropShadowEffect textShadowEffect = QGraphicsDropShadowEffect();

protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // USERVIEW_H
