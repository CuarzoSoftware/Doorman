#include "MainWindow.h"
#include "Shared.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loadAssets();
    MainWindow w;
    w.showFullScreen();
    return a.exec();
}
