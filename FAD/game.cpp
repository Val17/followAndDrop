///fichier game.cpp
/// Createur: Valentin DAVY
/// Binome: DAVY/DENIZET

#include "game.h"
#define PI 3.14159265

using namespace std;

/**
 * Constructeur de la classe Game
 * @brief Game::Game
 * @param parent
 */
Game::Game(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    chrono = 0;

    /*
     * Au depart, il n'y aucun element graphique
     * */

    boolArena = false;
    boolArm = true;
    boolTarget = false;
    boolSphereArena = false;
    boolHole = false;
    boolSphereArm = false;

    intGluPerspective = 80;

    timerToCatch = new QTimer(this);
    timerMoveArm = new QTimer(this);
    timerToDrop = new QTimer(this);
}

Game::~Game()
{
    delete timerToCatch;
    delete timerMoveArm;
    delete timerToDrop;
}

QSize Game::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize Game::sizeHint() const
{
    return QSize(200, 200);
}

static void qNormalizeAngle(int &angle)
{
    while (angle < 0)
        angle += 360 * 20;
        angle +=360;
    while (angle > 360)
        angle -= 360 * 20;
        angle -= 360;
}

void Game::setXRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void Game::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void Game::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}


void Game::initializeGL()
{
    //glDisable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glEnable ( GL_NORMALIZE );
    glDepthMask ( GL_TRUE );
    glBlendFunc(GL_ONE_MINUS_SRC_ALPHA, GL_SRC_ALPHA);
    glEnable(GL_COLOR_MATERIAL);
    glDisable( GL_CULL_FACE );
    glDisable( GL_LIGHTING );
    //glEnable( GL_BLEND );
}

void Game::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glLoadIdentity();

    // initalize the coordinate system to correct alignement

    glTranslatef(0.0, 0.0, -30.0);
    //glRotatef(80, -1, 0.0, 0.0);
    glRotatef(-60, 1.0, 0.0, 0.0);

    //glTranslatef(0,0,altitud);

    /*glRotatef (90,1,0,0);
    glRotatef (90,0,0,1);


    // Perform world transformations

    /*glTranslatef(0,0,-35);
    glRotatef(-80,1,0,0);
    glTranslatef(0,0,zRot);*/


    /*glRotatef(-xRot/16, 0.0, 1.0, 0.0); //theta
    //glRotatef(-yRot/16, 0.0, 0.0, 1.0); //phi
    glRotatef(-zRot/16, 1.0, 0.0, 0.0);*/

    draw();
}

void Game::resizeGL(int width, int height)
{
    int side = qMin(width, height);
    glViewport(0,0,width,height); // new version

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(intGluPerspective, ((float)width/(float)height),0.01,1000);
    glMatrixMode(GL_MODELVIEW);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
        //setZRotation(zRot + 8 * dy);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}

void Game::draw()
{

    glClear(GL_COLOR_BUFFER_BIT);

    /// Elements qui ne disparaisse jamais
    glPushMatrix();
        myArm.drawArm();
    glPopMatrix();

    // On fait apparaitre un trou

    // On fait apparaitre une cible

    if (boolTarget == true)
    {
        glPushMatrix();
            glTranslatef(myTarget.getX(), myTarget.getY(),0.1);
            myTarget.drawTarget();
        glPopMatrix();
    }

    // On fait apparaitre une sphere

    if (boolSphereArena == true)
    {
        glPushMatrix();
            glTranslatef(mySphere.getX(), mySphere.getY(),mySphere.getZ());
            mySphere.drawSphere();
        glPopMatrix();
    }

        glPushMatrix();
            myArena.drawArena();
        glPopMatrix();

        if (boolHole == true)
        {
            glPushMatrix();
                glColor3f(0,0,0);
                glTranslatef(myHole.getX(), myHole.getY(),.1);
                myHole.drawHole(mySphere.getRadius());
            glPopMatrix();
        }



    /// Elements qui apparaissent a des endroits differents



}


void Game::catchSphere()
{
    /// On attrape la sphere
    /*
     * Calcul des angles beta et gamma du bras
     * Methode: Theoreme d'Al-Khashi
     * Modelisation: triangle forme par les sommets:
     * - centre de la sphere/epaule du bras
     * - centre de la sphere/coude du bras
     * - centre de la sphere a attraper*/

    //Cotes du triangle

    double sideA1 = myArm.sA+2; // cote 1 du triangle
    double sideB1 = myArm.sFa+2; // cote 2 du triangle
    double sideC1 = mySphere.getDistance(); // cote 3 du triangle

    //Cosinus

    double cosA1 = (sideA1*sideA1+sideC1*sideC1-sideC1*sideC1)/(2*sideA1*sideC1); // angle beta a atteindre
    double cosB1 = (sideA1*sideA1+sideB1*sideB1-sideC1*sideC1)/(2*sideA1*sideB1); // angle gamma a atteindre

    //Angles en degres

    double angleA1 = acos(cosA1) * 180 / PI; // angle1 en radian
    double angleB1 = acos(cosB1) * 180/ PI; // angle2 en radian

    //Limites
    double a1 = mySphere.thetaSphere;
    double b1 = 90 - angleA1;
    double g1 = 180 - angleB1;


    if (a1-myArm.alpha>10)
    {
        myArm.alpha+=10;
        update();
    }

    else if (myArm.alpha-a1>10)
    {
        myArm.alpha-=10;
        update();
    }

     // Orientation bonne

    else if (b1-myArm.beta>10)
    {
        myArm.beta+=10;
        update();
    }

    else if (myArm.beta-b1>10)
    {
        myArm.beta-=10;
        update();
    }

    // Angle beta bon

    else if (g1-myArm.gamma>10)
    {
        myArm.gamma+=10;
        update();
    }

    else if (myArm.gamma-g1>10)
    {
        myArm.gamma-=10;
        update();
    }

    // Angle gamma bon

    else if (myArm.delta<60)
    {
        myArm.delta+=10;
    }

    //Pince sert la sphere

    else if (boolSphereArena==true)
    {
        boolSphereArena=false; // on fait disparaitre la sphere
        myArm.boolSphereArm=true; // on fait aparaitre celle dans le bras
        update();
    }

    else
    {
        timerToCatch->stop();
        boolSphereArm = true;
        removeSphere(2);
    }

}


void Game :: removeSphere(int step)
{
    if (step==1)
    {
        connect(timerToCatch, SIGNAL(timeout()), this, SLOT(catchSphere()));
        timerToCatch->start(1);
    }

    else if (step==2)
    {
        connect(timerMoveArm, SIGNAL(timeout()), this, SLOT(reinitializeArm()));
        timerMoveArm->start(.1);
    }

    else if (step==3)
    {
        connect(timerToDrop, SIGNAL(timeout()),this,SLOT(dropSphere()));
        timerToDrop->start(10);
    }

    else if (step==4)
    {
        connect(timerMoveArm, SIGNAL(timeout()), this, SLOT(reinitializeArm()));
        connect(timerMoveArm, SIGNAL(timeout()), this, SLOT(putSphereOut()));
        timerMoveArm->start(10);

    }

}

void Game::reinitializeArm()
{
    // La sphere est attrapee; on ramene le bras a sa position initiale

    if (myArm.alpha>0)
    {
        myArm.alpha-=1;
        update();
    }

    else if (myArm.alpha<0)
    {
        myArm.alpha+=1;
        update();
    }

    if (myArm.beta>1)
    {
        myArm.beta-=1;
        update();
    }

    else if (myArm.beta<0)
    {
        myArm.beta+=1;
        update();
    }

    if (myArm.gamma>0)
    {
        myArm.gamma-=1;
        update();
    }

    else if (myArm.gamma<0)
    {
        myArm.gamma+=1;
        update();
    }

    // Le bras est en position initiale et a la sphere
    else if (boolSphereArm==true)
    {
        timerMoveArm->stop();
        removeSphere(3);
    }

    else if (mySphere.getZ()==-3)
        {
            timerMoveArm->stop(); // la sphere est tombee dans le trou
        }

}

/**
 * @brief Game::setSphereOut
 * Methode appelee lorsque la sphere est au bord du trou et doit tomber
 */

void Game::putSphereOut()
{
    if (mySphere.getZ()>-3)
    {
        mySphere.setZ(mySphere.getZ()-.5);
        update();
    }

    else
    {

        boolSphereArena=false; // la sphere n'est plus sur l'arene
        mySphere.setZ(2); // la prochaine sphere reviendra au dessus de l'arene

    }

}

void Game::dropSphere()
{
    /// Parametres de deplacement de  la sphere jusque le trou
    /*
     * Calcul des angles beta et gamma du bras
     * Methode: Theoreme d'Al-Khashi
     * Modelisation: triangle forme par les sommets:
     * - centre de la sphere/epaule du bras
     * - centre de la sphere/coude du bras
     * - centre du trou*/

    //Cotes du triangle

    double sideA2 = myArm.sA+2; // cote 1 du triangle
    double sideB2 = myArm.sFa+2; // cote 2 du triangle
    double sideC2 = myHole.getDistance(); // cote 3 du triangle

    //Cosinus

    double cosA2 = (sideA2*sideA2+sideC2*sideC2-sideC2*sideC2)/(2*sideA2*sideC2); // angle beta a atteindre
    double cosB2 = (sideA2*sideA2+sideB2*sideB2-sideC2*sideC2)/(2*sideA2*sideB2); // angle gamma a atteindre

    //Angles en degres

    double angleA2 = acos(cosA2) * 180 / PI; // angleA2 en radian
    double angleB2 = acos(cosB2) * 180/ PI; // angleB2 en radian

    //Limites
    float a2 = myHole.getTheta();
    float b2 = 90 - angleA2;
    float g2 = 180 - angleB2;
    // La sphere est prete a aller dans le trou

        if (a2-myArm.alpha>10)
        {
            myArm.alpha+=10;
            update();
        }

        else if (myArm.alpha-a2>10)
        {
            myArm.alpha-=10;
            update();
        }

         // Orientation bonne

        else if (b2-myArm.beta>10)
        {
            myArm.beta+=10;
            update();
        }

        else if (myArm.beta-b2>10)
        {
            myArm.beta-=10;
            update();
        }

        // Angle beta bon

        else if (g2-myArm.gamma>10)
        {
            myArm.gamma+=10;
            update();
        }

        else if (myArm.gamma-g2>10)
        {
            myArm.gamma-=10;
            update();
        }

        // Angle gamma bon

        else if (myArm.delta>=30)
        {
            myArm.delta-=10;
            update();
        }

        else
        {
            timerToDrop->stop();
            boolSphereArm=false; // le bras ne tient plus la sphere

            mySphere.setX(myHole.getX());
            mySphere.setY(myHole.getY());

            boolSphereArena=true; // la sphere est sur l'arene

            myArm.boolSphereArm=false;
            removeSphere(4);
        }
}

void Game :: appearSphere()
{

    boolSphereArena = true; // il y a une sphere sur le jeu
    mySphere.setX(getRandomCoordinates().x());
    mySphere.setY(getRandomCoordinates().y());

    qDebug()<<"Sphere:"<<mySphere.getX()<<" et "<<mySphere.getY()<<" - angle:"<<mySphere.thetaSphere;

    update();
}

void Game :: appearHole()
{
    boolHole = true; // il y a un trou sur le jeu
    myHole.setX(getRandomCoordinates().x());
    myHole.setY(getRandomCoordinates().y());

    qDebug()<<"Trou:"<<myHole.getX()<<" et "<<myHole.getY()<<" - angle:"<<myHole.getTheta();

    update();
}

void Game::appearTarget()
{
    boolTarget = true; // il y a un trou sur le jeu

    int xLimitLow = myHole.getX() + myHole.getRadius();
    int yLimitLow = myHole.getY() + myHole.getRadius();

    myTarget.setX(getRandomCoordinates().x());
    myTarget.setY(getRandomCoordinates().y());

    myTarget.setRadius(myTarget.getRadius()-.5);

    while (myTarget.getX()>xLimitLow && myTarget.getY()>yLimitLow) // on s'assure de ne pas plaer la cible sur le trou
    {
        qDebug()<<"Boucle target";
        myTarget.setX(getRandomCoordinates().x());
        myTarget.setY(getRandomCoordinates().y());
    }

    qDebug()<<"Target:"<<myTarget.getX()<<" et "<<myTarget.getY()<<" - angle: "<<myTarget.thetaTarget_;
    update();
}

QPoint Game :: getRandomCoordinates ()
{
    int high = myArena.getSize() /(float)2;
    int low = - myArena.getSize() /(float)2;

    QPoint point; // point ou l'on va mettre l'element
    point.setX(0);
    point.setY(0);

    double distance = 0;

    while (distance<2) // on ne doit pas avoir un element trop proche du bras
    {
        point.setX(qrand() % ((high + 1) - low) + low);
        point.setY(qrand() % ((high + 1) - low) + low);
        distance = sqrt (point.x()*point.x()+point.y()*point.y());
    }
    return point;
}


void Game::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

int Game::getRandomRadius()
{
    int high = 5;
    int low = - 1;

    int radius = 0;

    while (radius<1) // on ne doit pas avoir un element trop proche du bras
    {
        radius=(qrand() % ((high + 1) - low) + low);
    }

    return  radius;
}

bool Game::detectVictory()
{
    if (mySphere.getX()==myTarget.getX() && mySphere.getY()==mySphere.getY())
    {
        return true;
    }

    else
    {
        return false;
    }
}
