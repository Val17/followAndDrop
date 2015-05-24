#include "gamewidget.h"
#include "ui_gamewidget.h"

GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);
    pointRef = cv::Point((ui->webcamWidget->getFrameWidth()-ui->webcamWidget->getTemplateWidth())/2,(ui->webcamWidget->getFrameHeight()-ui->webcamWidget->getTemplateHeight())/2);
    connect(ui->webcamWidget,SIGNAL(emitPoint(cv::Point)),this,SLOT(moveSphere(cv::Point)));
}

GameWidget::~GameWidget()
{
    delete ui;
}

void GameWidget::moveSphere(cv::Point handPoint)
{



     if(handPoint.x > pointRef.x)
             {
                 if (ui->myGame->mySphere.isMovable(1,0,ui->myGame->myArena.getSize())==true)
                           {
                              ui->myGame->mySphere.xSphere-=1;
                              ui->myGame->update();
                          }
                 else
                 {
                     ui->myGame->mySphere.xSphere+=1;
                 }
             }

             if(handPoint.x < pointRef.x)
             {

                 if (ui->myGame->mySphere.isMovable(1,0,ui->myGame->myArena.getSize())==true)
                           {
                              ui->myGame->mySphere.xSphere+=1;
                              ui->myGame->update();
                          }
                 else
                 {
                     ui->myGame->mySphere.xSphere-=1;
                 }
             }

             if(handPoint.y > pointRef.y)
                     {
                         if (ui->myGame->mySphere.isMovable(1,0,ui->myGame->myArena.getSize())==true)
                                   {
                                      ui->myGame->mySphere.ySphere-=1;
                                      ui->myGame->update();
                                  }
                         else
                         {
                             ui->myGame->mySphere.ySphere+=1;
                         }
                     }

             if(handPoint.y < pointRef.y)
                     {
                         if (ui->myGame->mySphere.isMovable(1,0,ui->myGame->myArena.getSize())==true)
                                   {
                                      ui->myGame->mySphere.ySphere+=1;
                                      ui->myGame->update();
                                  }
                         else
                         {
                             ui->myGame->mySphere.ySphere-=1;
                         }
                     }

     pointRef= handPoint;

     qDebug() << "Point après la comp : " << pointRef.x << endl;
     qDebug() << "Point après la comp : " << pointRef.y << endl;

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
        ui->myGame->removeSphere(1);
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



