#include "mainwindow.h"
#include <webcamwindow.h>
#include <QApplication>
#include <QDesktopWidget>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    //window.resize(window.sizeHint());
    /*int desktopArea = QApplication::desktop()->width() * QApplication::desktop()->height();
    int widgetArea = window.width() * window.height();*/

    window.setWindowTitle("Follow And Drop - Menu");

    /*if (((float)widgetArea / (float)desktopArea) < 0.75f)

    else
        window.showMaximized();*/

    window.show();

    return app.exec();
}
