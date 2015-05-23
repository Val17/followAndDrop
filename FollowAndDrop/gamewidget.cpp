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



void GameWidget::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Escape)
    {
        close();
    }

    else if (e->key() == Qt::Key_T)

    {
        ui->myGame->appearTarget();

    }

    else if (e->key() == Qt::Key_D)
    {
        ui->myGame->catchSphere();
    }

    else if (e->key() == Qt::Key_S)
    {
        ui->myGame->appearSphere();
    }

    else if (e->key() == Qt::Key_H)
    {
        ui->myGame->appearHole();
    }

    else if (e->key()==Qt::Key_P)
    {
        ui->myGame->myArm.alpha+=1;
        qDebug()<<ui->myGame->myArm.alpha;
        ui->myGame->update();
    }

    else if (e->key()==Qt::Key_M)
    {
        ui->myGame->myArm.alpha-=1;
        qDebug()<<ui->myGame->myArm.alpha;
        ui->myGame->update();
    }

    else if (e->key()==Qt::Key_R)
    {
        ui->myGame->myArm.alpha=0;
        ui->myGame->myArm.gamma=0;
        ui->myGame->myArm.gamma=0;
        ui->myGame->update();
    }

    else

    {
        QWidget::keyPressEvent(e);
    }


}



