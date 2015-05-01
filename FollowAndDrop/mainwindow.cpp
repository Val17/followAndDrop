#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*ui->xValue->setText(QString::number(myGame->xRot));
    ui->yValue->setText(QString::number(myGame->yRot));
    ui->zValue->setText(QString::number(myGame->zRot));*/


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();

    else if (e->key() == Qt::Key_S)
    {
        setWindowTitle("Lalala");
    }

    else

    {
        QWidget::keyPressEvent(e);
    }

}

void MainWindow::on_gameButton_clicked()
{
    myGameWidget.show();

}
