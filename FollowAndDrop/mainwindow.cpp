#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *button = ui->animationButton;


    QPropertyAnimation animation(button,"geometry");
    animation.setKeyValueAt(0, QRect(0, 0, 100, 30));
    animation.setKeyValueAt(0.8, QRect(250, 250, 100, 30));
    animation.setKeyValueAt(1, QRect(0, 0, 100, 30));

    //animation.start();

    animation.start();


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
