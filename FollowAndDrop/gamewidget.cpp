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

void GameWidget::on_sphereButton_clicked()
{
    ui->myGame->boolSphere=true;
    ui->myGame->update();
}


void GameWidget::on_menuButton_clicked()
{
    close();
}

void GameWidget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
        close();


    else if (e->key() == Qt::Key_N)
    {
        ui->myGame->myArticulateArm.theta+=1;
        ui->myGame->update();
    }

    else

    {
        QWidget::keyPressEvent(e);
    }

}



void GameWidget::on_reinitializeButton_clicked()
{
    ui->myGame->xRot=0;
    ui->myGame->yRot=0;
    ui->myGame->zRot=0;
    ui->myGame->update();

}
