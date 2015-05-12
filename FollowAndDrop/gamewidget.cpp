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


    else if (e->key() == Qt::Key_P)
    {
        ui->myGame->myArticulateArm.alpha+=1;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_M)
    {
        ui->myGame->myArticulateArm.alpha-=1;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_O)
    {
        ui->myGame->myArticulateArm.beta+=1;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_L)
    {
        ui->myGame->myArticulateArm.beta-=1;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_I)
    {
        ui->myGame->myArticulateArm.gamma+=1;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_K)
    {
        ui->myGame->myArticulateArm.gamma-=1;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_U)
    {
        ui->myGame->mySphere.xSphere+=1;
        ui->buttonXSphere->setText(QString::number(ui->myGame->mySphere.xSphere));
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_J)
    {
        ui->myGame->mySphere.xSphere-=1;
        ui->buttonXSphere->setText(QString::number(ui->myGame->mySphere.xSphere));
        ui->myGame->update();
    }



    else if (e->key() == Qt::Key_Y)
    {
        ui->myGame->mySphere.ySphere+=1;
        ui->buttonYSphere->setText(QString::number(ui->myGame->mySphere.ySphere));
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_H)
    {
        ui->myGame->mySphere.ySphere-=1;
        ui->buttonYSphere->setText(QString::number(ui->myGame->mySphere.ySphere));
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

void GameWidget::on_catchButton_clicked()
{
    ui->myGame->startChrono();
}

void GameWidget::on_buttonA_clicked()
{
    ui->buttonA->setText(QString::number(ui->myGame->myArticulateArm.alpha));
}

void GameWidget::on_buttonB_clicked()
{
    ui->buttonB->setText(QString::number(ui->myGame->myArticulateArm.beta));
}

void GameWidget::on_buttonG_clicked()
{
    ui->buttonG->setText(QString::number(ui->myGame->myArticulateArm.gamma));
}

void GameWidget::on_buttonS_clicked()
{
    ui->buttonS->setText(QString::number(ui->myGame->mySphere.theta));
}



void GameWidget::on_buttonYSphere_clicked()
{
    ui->buttonYSphere->setText(QString::number(ui->myGame->mySphere.ySphere));
}

void GameWidget::on_buttonXSphere_clicked()
{
    ui->buttonYSphere->setText(QString::number(ui->myGame->mySphere.ySphere));
}
