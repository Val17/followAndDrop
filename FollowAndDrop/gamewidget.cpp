#include "gamewidget.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);
    ui->xCoord->setText(QString::number(ui->myGame->lastPos.x()));
    ui->yCoord->setText(QString::number(ui->myGame->lastPos.y()));
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::on_dropButton_clicked()
{
    qDebug()<<"GameWidget: dropButton clicked";
    ui->myGame->dropSphere();
}

void GameWidget::on_targetButton_clicked()
{
    qDebug()<<"GameWidget: targetButton clicked";
    ui->myGame->appearTarget();
}

void GameWidget::on_coordonateButton_clicked()
{
    ui->xCoord->setText(QString::number(ui->myGame->lastPos.x()));
    ui->yCoord->setText(QString::number(ui->myGame->lastPos.y()));
}

void GameWidget::on_menuButton_clicked()
{
    close();
}

void GameWidget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();

    else if (e->key() == Qt::Key_S)
    {
        ui->myGame->boolArm=false;
        ui->myGame->update();
    }

    else

    {
        QWidget::keyPressEvent(e);
    }

}

