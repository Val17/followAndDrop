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


void MainWindow::on_namePlayer_textEdited(const QString &arg1)
{
    ui->buttonGame->setEnabled(true);
}

void MainWindow::on_buttonGame_clicked()
{
    myGameWidget.setNamePlayer(ui->namePlayer->text());
    qDebug()<<"dans mainwindow: "<<myGameWidget.getNamePlayer();
    myGameWidget.show();
}
