#include "Shared.h"
#include <QDebug>
#include <QApplication>
#include <QScreen>
#include <QGraphicsBlurEffect>

static Shared *shared;

Shared::Shared()
{
    usersCount = 0;
    pixelRatio = QApplication::primaryScreen()->devicePixelRatio();

    avatarBorderSize = 2;
    avatarSize = 96;
    QPixmap avatarPixmap = QPixmap("/System/Resources/Icons/Avatar-Default.jpg");
    defaultAvatar = avatarPixmap
                        .scaled(
                            avatarSize * pixelRatio,
                            avatarSize * pixelRatio,
                            Qt::IgnoreAspectRatio,
                            Qt::SmoothTransformation);
    defaultAvatar.setDevicePixelRatio(pixelRatio);

    loginFormAvatarBorderSize = 4;
    loginFormAvatarSize = 128;
    loginFormDefaultAvatar = avatarPixmap
                        .scaled(
                            loginFormAvatarSize * pixelRatio,
                            loginFormAvatarSize * pixelRatio,
                            Qt::IgnoreAspectRatio,
                            Qt::SmoothTransformation);
    loginFormDefaultAvatar.setDevicePixelRatio(pixelRatio);
    loginFormFadeAnimationDuration = 200;

    shadowColor = QColor(0, 0, 0, 140);
}

Shared *SHARED()
{
    return shared;
}

void loadAssets()
{
    shared = new Shared();
}
