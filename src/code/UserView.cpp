#include <QMouseEvent>
#include "UserView.h"
#include "MainWindow.h"

UserView::UserView(MainWindow *mainWindow, const QString &name, const QString &home, int id)
{
    this->mainWindow = mainWindow;
    setCursor(Qt::PointingHandCursor);

    QString uppercaseName = name;
    uppercaseName[0] = uppercaseName[0].toUpper();

    this->nameLabel.setText(uppercaseName);
    this->home = home;
    this->id = id;

    vbox.addWidget(&avatar);
    vbox.addWidget(&nameLabel);
    vbox.setSpacing(16);
    vbox.setAlignment(Qt::AlignCenter);

    textShadowEffect.setBlurRadius(10);
    textShadowEffect.setColor(SHARED()->shadowColor);
    textShadowEffect.setOffset(0, 0);
    nameLabel.setAlignment(Qt::AlignCenter);
    nameLabel.setGraphicsEffect(&textShadowEffect);
    nameLabel.setStyleSheet("color:white; font-size: 16px; font-family: Inter; font-weight: 600; text-align: center");
}

void UserView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPropertyAnimation *animation = new QPropertyAnimation(&mainWindow->usersContainerOpacityEffect, "opacity");
        animation->setDuration(SHARED()->loginFormFadeAnimationDuration);
        animation->setStartValue(0.9999);
        animation->setEndValue(0.0);
        mainWindow->usersContainerOpacityEffect.setOpacity(0.9999);
        mainWindow->usersContainerOpacityEffect.setEnabled(true);
        animation->start(QPropertyAnimation::DeleteWhenStopped);
        connect(animation, &QPropertyAnimation::finished, [this]{
            mainWindow->usersContainer.hide();
        });


        if (SHARED()->usersCount > 1)
        {
            mainWindow->loginForm.goBackButton.show();
            mainWindow->loginForm.inputRightSpace.show();
        }
        else
        {
            mainWindow->loginForm.goBackButton.hide();
            mainWindow->loginForm.inputRightSpace.hide();
        }
        mainWindow->loginForm.nameLabel.setText(nameLabel.text());
        mainWindow->loginForm.move(
            mainWindow->width()/2 - mainWindow->loginForm.width()/2,
            mainWindow->height()/2 - mainWindow->loginForm.height()/2);

        animation = new QPropertyAnimation(&mainWindow->loginForm.opacityEffect, "opacity");
        animation->setDuration(SHARED()->loginFormFadeAnimationDuration);
        animation->setStartValue(0.0);
        animation->setEndValue(0.9999);
        mainWindow->loginForm.opacityEffect.setOpacity(0.0);
        mainWindow->loginForm.opacityEffect.setEnabled(true);
        mainWindow->loginForm.show();
        mainWindow->loginForm.updateGeometry();
        mainWindow->loginForm.vbox.update();
        animation->start(QPropertyAnimation::DeleteWhenStopped);
    }
}
