#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd("../FollowAndDrop/Images/background_1.png");
            bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
            QPalette palette;
            palette.setBrush(QPalette::Background, bkgnd);
            this->setPalette(palette);

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

void MainWindow::on_gameButton_pressed()
{
    myGameWidget.show();
}

void MainWindow::on_quitButton_clicked()
{
    close();
}

void MainWindow::on_newGameAction_clicked()
{
    myGameWidget.show();
}

void MainWindow::on_quitAction_clicked()
{
    close();
}
