#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include "IconButton.h"
#include "Shared.h"
#include "Avatar.h"

class LoginForm : public QWidget
{
    Q_OBJECT
public:
    explicit LoginForm(QWidget *parent = nullptr);

    QVBoxLayout vbox = QVBoxLayout(this);
    Avatar avatar = Avatar(SHARED()->loginFormAvatarSize,
                           SHARED()->loginFormAvatarBorderSize,
                           SHARED()->loginFormDefaultAvatar,
                           this);
    QLabel nameLabel;

    QWidget inputFieldContainer;
    QWidget inputRightSpace;
    QHBoxLayout inputFieldLayout = QHBoxLayout(&inputFieldContainer);
    IconButton goBackButton = IconButton("/System/Resources/Icons/chevron-back-circle-outline.svg");
    QLineEdit passwordInput = QLineEdit(this);
    QGraphicsOpacityEffect opacityEffect;
    QGraphicsDropShadowEffect textShadowEffect = QGraphicsDropShadowEffect();
};

#endif // LOGINFORM_H
