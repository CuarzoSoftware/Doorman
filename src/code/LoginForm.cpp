#include "LoginForm.h"

LoginForm::LoginForm(QWidget *parent) : QWidget{parent}
{
    setFixedSize(320, 230);
    passwordInput.setStyleSheet("QLineEdit {"
                            "border-radius: 10px;"
                            "border: 1px solid #eeeeee;"
                            "padding-left: 8px;"
                            "padding-top: 4px;"
                            "padding-right: 8px;"
                            "padding-bottom: 4px;"
                            "font-family: Inter;"
                            "font-weight: Regular;"
                            "font-size: 11px;"
                            "color: #444444;"
                            "}");
    passwordInput.setPlaceholderText("Enter Password");
    passwordInput.setAlignment(Qt::AlignCenter);
    passwordInput.setEchoMode(QLineEdit::Password);
    passwordInput.setFixedWidth(160);
    vbox.setSpacing(10);
    vbox.addWidget(&avatar, 0, Qt::AlignCenter);
    vbox.addWidget(&nameLabel, 0, Qt::AlignCenter);
    vbox.addStretch(1);
    vbox.addWidget(&inputFieldContainer, 0, Qt::AlignCenter);

    inputFieldLayout.addWidget(&goBackButton, 0, Qt::AlignCenter);
    inputFieldLayout.addWidget(&passwordInput, 1, Qt::AlignCenter);
    inputFieldLayout.addWidget(&inputRightSpace, 0, Qt::AlignCenter);
    inputRightSpace.setFixedSize(goBackButton.size());


    hide();
    setGraphicsEffect(&opacityEffect);

    textShadowEffect.setBlurRadius(10);
    textShadowEffect.setColor(SHARED()->shadowColor);
    textShadowEffect.setOffset(0, 0);
    nameLabel.setAlignment(Qt::AlignCenter);
    nameLabel.setGraphicsEffect(&textShadowEffect);
    nameLabel.setStyleSheet("color:white; font-size: 20px; font-family: Inter; font-weight: 600; text-align: center");
}
