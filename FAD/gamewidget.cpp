///fichier gamewidget.cpp
/// Createurs: Valentin DAVY et Arnaud DENIZET
/// Binome: DAVY/DENIZET

#include "gamewidget.h"
#include "ui_gamewidget.h"


GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWidget)
{
    ui->setupUi(this);
    pointRef = cv::Point((ui->webcamWidget->getFrameWidth()-ui->webcamWidget->getTemplateWidth())/2,(ui->webcamWidget->getFrameHeight()-ui->webcamWidget->getTemplateHeight())/2);
    connect(ui->webcamWidget,SIGNAL(emitPoint(cv::Point)),this,SLOT(moveSphere(cv::Point)));

    timerChrono_ = new QTimer(this);
    level_=1;
    ui->level->setText("<font color='red'>" + QString::number(level_) + "</font>");

}

GameWidget::~GameWidget()
{
    delete ui;
    delete timerChrono_;
}

void GameWidget::moveSphere(cv::Point handPoint)
{

     if(handPoint.x > pointRef.x)
             {
                 if (ui->myGame->mySphere.isMovable(1,0,ui->myGame->myArena.getSize())==true)
                           {
                              ui->myGame->mySphere.setX(ui->myGame->mySphere.getX()-1);
                              ui->myGame->update();
                          }
                 else
                 {
                     ui->myGame->mySphere.setX(ui->myGame->mySphere.getX()+1);
                 }
             }

             if(handPoint.x < pointRef.x)
             {

                 if (ui->myGame->mySphere.isMovable(1,0,ui->myGame->myArena.getSize())==true)
                           {
                              ui->myGame->mySphere.setX(ui->myGame->mySphere.getX()+1);
                              ui->myGame->update();
                          }
                 else
                 {
                     ui->myGame->mySphere.setX(ui->myGame->mySphere.getX()-1);
                 }
             }

             if(handPoint.y > pointRef.y)
                     {
                         if (ui->myGame->mySphere.isMovable(1,0,ui->myGame->myArena.getSize())==true)
                                   {
                                      ui->myGame->mySphere.setY(ui->myGame->mySphere.getY()-1);
                                      ui->myGame->update();
                                  }
                         else
                         {
                             ui->myGame->mySphere.setY(ui->myGame->mySphere.getY()+1);
                         }
                     }

             if(handPoint.y < pointRef.y)
                     {
                         if (ui->myGame->mySphere.isMovable(1,0,ui->myGame->myArena.getSize())==true)
                                   {
                                      ui->myGame->mySphere.setY(ui->myGame->mySphere.getY()+1);
                                      ui->myGame->update();
                                  }
                         else
                         {
                             ui->myGame->mySphere.setY(ui->myGame->mySphere.getY()-1);
                         }
                     }

     pointRef= handPoint;

     //qDebug() << "Point après la comp : " << pointRef.x << endl;
     //qDebug() << "Point après la comp : " << pointRef.y << endl;

     if (ui->myGame->detectVictory()==true)
     {
         ui->myGame->removeSphere(1);
     }

     else if (ui->myGame->detectVictory()==false)
     {
         qDebug()<<"Pas de touche...";
     }

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
        level_+=1; // on incremente le niveau de jeu
        ui->level->setText(QString::number(level_));

    }

    else if (e->key() == Qt::Key_S)
    {
        ui->myGame->appearSphere();
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

    else if (e->key()==Qt::Key_C)
    {
        startChrono();
    }

    else if (e->key() == Qt::Key_6)
    {
        ui->myGame->mySphere.setX(ui->myGame->mySphere.getX()+1);
        ui->myGame->update();
        qDebug()<<"x: "<<ui->myGame->mySphere.getX() <<" -- "<<ui->myGame->myTarget.getX();
        qDebug()<<"y: "<<ui->myGame->mySphere.getY() <<" -- "<< ui->myGame->myTarget.getY();
    }

    else if (e->key() == Qt::Key_8)
    {
        ui->myGame->mySphere.setY(ui->myGame->mySphere.getY()+1);
        ui->myGame->update();
        qDebug()<<"x: "<<ui->myGame->mySphere.getX() <<" -- "<<ui->myGame->myTarget.getX();
        qDebug()<<"y: "<<ui->myGame->mySphere.getY() <<" -- "<< ui->myGame->myTarget.getY();

    }

    else if (e->key() == Qt::Key_4)
    {
        ui->myGame->mySphere.setX(ui->myGame->mySphere.getX()-1);
        ui->myGame->update();
        qDebug()<<"x: "<<ui->myGame->mySphere.getX() <<" -- "<<ui->myGame->myTarget.getX();
        qDebug()<<"y: "<<ui->myGame->mySphere.getY() <<" -- "<< ui->myGame->myTarget.getY();
    }

    else if (e->key() == Qt::Key_2)
    {
        ui->myGame->mySphere.setY(ui->myGame->mySphere.getY()-1);
        ui->myGame->update();
        qDebug()<<"x: "<<ui->myGame->mySphere.getX() <<" -- "<<ui->myGame->myTarget.getX();
        qDebug()<<"y: "<<ui->myGame->mySphere.getY() <<" -- "<< ui->myGame->myTarget.getY();
    }

    else

    {
        QWidget::keyPressEvent(e);
    }

}

void GameWidget::startChrono()
{
    time_.start();
    incrementChrono();
    connect(timerChrono_, SIGNAL(timeout()), this, SLOT(incrementChrono()));
    timerChrono_->start(500); // twice per second

}

void GameWidget::incrementChrono()
{
    int secs = time_.elapsed() / 1000;
    int mins = (secs / 60) % 60;
    secs = secs % 60;
    ui->time->setText(QString("%1:%2").arg(mins, 2, 10, QLatin1Char('0')).arg(secs, 2, 10, QLatin1Char('0')));

}

void GameWidget::on_buttonStart_clicked()
{
    startChrono();
}

/**
 * @brief GameWidget::show
 * Permet d'avoir le nom du joueur lorsque l'on lance le jeu
 * @param n
 */
void GameWidget::show(QString n)
{
    setNamePlayer(n);
    ui->label->setText("<font color='blue'>" + getNamePlayer() + "</font>");
    QWidget::show();
}
