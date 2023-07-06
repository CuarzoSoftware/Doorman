#ifndef SHARED_H
#define SHARED_H

#include <QObject>
#include <QPixmap>

class Shared : public QObject
{
public:
    Shared();
    uint usersCount;
    qreal pixelRatio;

    uint avatarSize;
    uint avatarBorderSize;
    QPixmap defaultAvatar;

    uint loginFormAvatarSize;
    uint loginFormAvatarBorderSize;
    QPixmap  loginFormDefaultAvatar;

    uint loginFormFadeAnimationDuration;

    QColor shadowColor;
};

Shared *SHARED();
void loadAssets();

#endif // SHARED_H
