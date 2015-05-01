#include "gamewidget.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);
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
