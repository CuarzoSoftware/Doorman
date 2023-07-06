#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

#include "LoginForm.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QWidget background = QWidget(this);
    QVBoxLayout vbox = QVBoxLayout(&background);
    LoginForm loginForm = LoginForm(this);

    QGraphicsOpacityEffect usersContainerOpacityEffect = QGraphicsOpacityEffect(this);
    QWidget usersContainer;
    QHBoxLayout usersLayout = QHBoxLayout(&usersContainer);
};
#endif // MAINWINDOW_H
