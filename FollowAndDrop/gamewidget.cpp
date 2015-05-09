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

void GameWidget::on_sphereButton_clicked()
{
    qDebug()<<"GameWidget: targetButton clicked";
    ui->myGame->boolSphere=true;
    ui->myGame->update();
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

    else if (e->key() == Qt::Key_E)
    {
        qDebug()<<"zRot baisse";
        ui->myGame->boolSphere=true;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_D)
    {
        if (ui->myGame->mySphere.isMovable(1,0,ui->myGame->myArena.getSize())==true)
        {
           ui->myGame->mySphere.xSphere+=1;
           ui->myGame->update();
        }


    }

    else if (e->key() == Qt::Key_Q)
    {
        if (ui->myGame->mySphere.isMovable(-1,0,ui->myGame->myArena.getSize())==true)
        {
            ui->myGame->mySphere.xSphere-=1;
            ui->myGame->update();
        }

    }

    else if (e->key() == Qt::Key_Z)
    {
        if (ui->myGame->mySphere.isMovable(0,1,ui->myGame->myArena.getSize())==true)
        {
            ui->myGame->mySphere.ySphere+=1;
            ui->myGame->update();
        }

    }

    else if (e->key() == Qt::Key_S)
    {
        if (ui->myGame->mySphere.isMovable(0,-1,ui->myGame->myArena.getSize())==true)
        {
            ui->myGame->mySphere.ySphere-=1;
            ui->myGame->update();
        }

    }

    else if (e->key() == Qt::Key_A)
    {
        ui->myGame->myArticulateArm.alpha+=1;
        qDebug()<<"Alpha: "<<ui->myGame->myArticulateArm.alpha;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_B)
    {
        ui->myGame->myArticulateArm.beta+=1;
        qDebug()<<"Beta: "<<ui->myGame->myArticulateArm.beta;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_G)
    {
        ui->myGame->myArticulateArm.gamma+=1;
        qDebug()<<"Gamma: "<<ui->myGame->myArticulateArm.gamma;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_T)
    {
        ui->myGame->myArticulateArm.delta+=1;
        qDebug()<<"Delta: "<<ui->myGame->myArticulateArm.delta;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_M)
    {
        ui->myGame->intGluPerspective+=1;
        ui->myGame->update();
    }

    else if (e->key() == Qt::Key_L)
    {
        ui->myGame->intGluPerspective-=1;
        ui->myGame->update();
    }

    else

    {
        QWidget::keyPressEvent(e);
    }

}


