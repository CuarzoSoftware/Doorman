#include "MainWindow.h"
#include "UserView.h"
#include <stdio.h>
#include <pwd.h>
#include <QDebug>
#include <QPushButton>
#include <QWindow>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    setCentralWidget(&background);
    vbox.addWidget(&usersContainer);

    setAttribute(Qt::WA_TranslucentBackground);
    background.setObjectName("centralWidget");
    background.setStyleSheet("#centralWidget {background-color: transparent;}");

    struct passwd *user;
    setpwent();

    usersLayout.setAlignment(Qt::AlignCenter);
    usersLayout.setSpacing(20);
    usersLayout.addStretch(1);
    while ((user = getpwent()) != NULL)
    {
        if (user->pw_uid >= 1000)
        {
            UserView *userView = new UserView(this, user->pw_name, user->pw_dir, user->pw_uid);
            usersLayout.addWidget(userView);
            SHARED()->usersCount++;
        }
    }
    usersLayout.addStretch(1);
    usersContainer.setGraphicsEffect(&usersContainerOpacityEffect);

    usersContainerOpacityEffect.setEnabled(false);
    endpwent();

    showFullScreen();

    /*
    QWidget *c = new QWidget();

    c->setFixedSize(200,200);

    c->show();

    c->windowHandle()->setParent(this->windowHandle());
    //c->windowHandle()->setTransientParent(this->windowHandle());
    c->windowHandle()->setPosition(200, 200);
    c->move(100,100);*/
}

MainWindow::~MainWindow()
{
}
