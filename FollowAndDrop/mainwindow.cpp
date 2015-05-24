///fichier mainwindow.cpp
/// Createur: Valentin DAVY
/// Binome: DAVY/DENIZET

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();

    else

    {
        QWidget::keyPressEvent(e);
    }

}

void MainWindow::on_gameButton_clicked()
{
    myGameWidget.show();

}

