#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*ui->xValue->setText(QString::number(myGame->xRot));
    ui->yValue->setText(QString::number(myGame->yRot));
    ui->zValue->setText(QString::number(myGame->zRot));*/


}

Window::~Window()
{
    delete ui;
}

void Window::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();

    else

    {
        QWidget::keyPressEvent(e);
    }

}
