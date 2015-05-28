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
    boolTarget = true;
    boolSphereArena = false;
    boolHole = false;
    boolSphereArm = false;

    intGluPerspective = 80;

    timerToCatch = new QTimer(this);
    timerMoveArm = new QTimer(this);
    timerToDrop = new QTimer(this);

    srand (static_cast <unsigned> (time(0))); // pour les coordonnees aleatoires
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

    // Dessin du bras
    glPushMatrix();
        myArm.drawArm();
    glPopMatrix();

    // Dessin de la sphere dans certaines conditions

    if (mySphere.getX()==0 && mySphere.getY()==0) // a l'initialisation du jeu
    {
        appearSphere();
    }

    if (boolSphereArena == true)
    {
        glPushMatrix();
            glTranslatef(mySphere.getX(), mySphere.getY(),mySphere.getZ());
            mySphere.drawSphere();
            b+=1;
            qDebug()<<"Victoire: "<<detectVictory()<<" nb dessin: "<<b;
        glPopMatrix();
    }

    // Dessin de l'arene
    glPushMatrix();
        myArena.drawArena();
    glPopMatrix();

    // Dessin du trou
    glPushMatrix();
        glColor3f(0,0,0);
        glTranslatef(myHole.getX(),myHole.getY(),.1);
        myHole.drawHole(mySphere.getRadius());
    glPopMatrix();

    if (myTarget.getX()==0 && myTarget.getY()==0) // a l'initialisation du jeu
    {
        appearTarget(myTarget.getRadius()+.5);
    }

    if (boolTarget == true)
    {
        glPushMatrix();
            glTranslatef(myTarget.getX(), myTarget.getY(),0.1);
            myTarget.drawTarget();
        glPopMatrix();
    }


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

    double sideA1 = myArm.sA_+2; // cote 1 du triangle
    double sideB1 = myArm.sFa_+2; // cote 2 du triangle
    double sideC1 = mySphere.getDistance(); // cote 3 du triangle

    //Cosinus

    double cosA1 = (sideA1*sideA1+sideC1*sideC1-sideB1*sideB1)/(2*sideA1*sideC1); // angle beta a atteindre
    double cosB1 = (sideA1*sideA1+sideB1*sideB1-sideC1*sideC1)/(2*sideA1*sideB1); // angle gamma a atteindre

    //Angles en degres

    double angleA1 = acos(cosA1) * 180 / PI; // angle1 en radian
    double angleB1 = acos(cosB1) * 180/ PI; // angle2 en radian

    //Limites
    double a1 = mySphere.getTheta();
    double b1 = 90 - angleA1;
    double g1 = 180 - angleB1;


    if (a1-myArm.alpha_>10)
    {
        myArm.alpha_+=10;
        //update();
    }

    else if (myArm.alpha_-a1>10)
    {
        myArm.alpha_-=10;
        //update();
    }

     // Orientation bonne

    else if (b1-myArm.beta_>10)
    {
        myArm.beta_+=10;
        //update();
    }

    else if (myArm.beta_-b1>10)
    {
        myArm.beta_-=10;
        //update();
    }

    // Angle beta bon

    else if (g1-myArm.gamma_>10)
    {
        myArm.gamma_+=10;
        //update();
    }

    else if (myArm.gamma_-g1>10)
    {
        myArm.gamma_-=10;
        //update();
    }

    // Angle gamma bon

    else if (myArm.delta_<60)
    {
        myArm.delta_+=10;
    }


    //Pince sert la sphere

    else if (boolSphereArena==true)
    {
        boolSphereArena=false; // on fait disparaitre la sphere
        myArm.boolSphereArm_=true; // on fait aparaitre celle dans le bras
        //updateGL();
    }

    else
    {
        timerToCatch->stop();
        timerToCatch->disconnect(timerToCatch, SIGNAL(timeout()), this, SLOT(catchSphere()));
        boolSphereArm = true;
        removeSphere(2);
    }

    updateGL();

}


void Game :: removeSphere(int step)
{
    if (step==1)
    {
        connect(timerToCatch, SIGNAL(timeout()), this, SLOT(catchSphere()));
        timerToCatch->start(10);
    }

    else if (step==2)
    {
        connect(timerMoveArm, SIGNAL(timeout()), this, SLOT(moveArm()));
        timerMoveArm->start(10);
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

void Game::moveArm()
{
    // La sphere est attrapee; on ramene le bras a sa position initiale

    if (myArm.alpha_>5)
    {
        myArm.alpha_-=5;
        update();
    }

    else if (myArm.alpha_<-5)
    {
        myArm.alpha_+=5;
        update();
    }

    if (myArm.beta_>5)
    {
        myArm.beta_-=5;
        update();
    }

    else if (myArm.beta_<-5)
    {
        myArm.beta_+=5;
        update();
    }

    if (myArm.gamma_>5)
    {
        myArm.gamma_-=5;
        update();
    }

    else if (myArm.gamma_<-5)
    {
        myArm.gamma_+=5;
        update();
    }

    // Le bras est en position quasi initiale et a la sphere
    else
    {
        timerMoveArm->stop();
        timerMoveArm->disconnect(timerMoveArm, SIGNAL(timeout()), this, SLOT(moveArm()));
        removeSphere(3);
    }

}

void Game::reinitializeArm()
{
    if (myArm.alpha_>0)
    {
        myArm.alpha_-=1;
        update();
    }

    else if (myArm.alpha_<0)
    {
        myArm.alpha_+=1;
        update();
    }

    else if (myArm.beta_>0)
    {
        myArm.beta_-=1;
        update();
    }

    else if (myArm.beta_<0)
    {
        myArm.beta_+=1;
        update();
    }

    else if (myArm.gamma_>0)
    {
        myArm.gamma_-=1;
        update();
    }

    else if (myArm.gamma_<0)
    {
        myArm.gamma_+=1;
        update();
    }

    else if (boolSphereArena==false)
        {
            qDebug()<<"Angles du bras: "<<myArm.alpha_<<" -- "<<myArm.beta_<<" -- "<<myArm.gamma_;
            setNextLevel(); // on passe au niveau suivant
            timerMoveArm->stop(); // la sphere est tombee dans le trou
            timerMoveArm->disconnect(timerMoveArm, SIGNAL(timeout()), this, SLOT(putSphereOut()));
            timerMoveArm->disconnect(timerMoveArm, SIGNAL(timeout()), this, SLOT(reinitializeArm()));
        }
}

/**
 * @brief Game::setSphereOut
 * Methode appelee lorsque la sphere est au bord du trou et doit tomber
 */

void Game::putSphereOut()
{
    if (mySphere.getZ()>-1 && boolSphereArena==true) // la sphere est en train de tomber
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

    double sideA2 = myArm.sA_+2; // cote 1 du triangle
    double sideB2 = myArm.sFa_+2; // cote 2 du triangle
    double sideC2 = myHole.getDistance(); // cote 3 du triangle

    //Cosinus

    double cosA2 = (sideA2*sideA2+sideC2*sideC2-sideB2*sideB2)/(2*sideA2*sideC2); // angle beta a atteindre
    double cosB2 = (sideA2*sideA2+sideB2*sideB2-sideC2*sideC2)/(2*sideA2*sideB2); // angle gamma a atteindre

    //Angles en degres

    double angleA2 = acos(cosA2) * 180 / PI; // angleA2 en radian
    double angleB2 = acos(cosB2) * 180/ PI; // angleB2 en radian

    //Limites
    float a2 = myHole.getTheta();
    float b2 = 90 - angleA2;
    float g2 = 180 - angleB2;
    // La sphere est prete a aller dans le trou

    /*qDebug()<<"Angles a atteindre: "<<a2<<" % "<<b2<<"  % "<<g2;
    qDebug()<<"Angles du bras: "<<myArm.alpha_<<" % "<<myArm.beta_<<"  % "<<myArm.gamma_;
    qDebug()<<"Cotes a avoir: "<<sideA2<<" % "<<sideB2<<" % "<<sideC2;
    qDebug()<<"Cotes du bras: ";*/

    if (a2-myArm.alpha_>5)
    {
        myArm.alpha_+=5;
        update();
    }

    else if (myArm.alpha_-a2>5)
    {
        myArm.alpha_-=5;
        update();
    }

     // Orientation bonne

    else if (b2-myArm.beta_>5)
    {
        myArm.beta_+=5;
        update();
    }

    else if (myArm.beta_-b2>5)
    {
        myArm.beta_-=5;
        update();
    }

    // Angle beta bon

    else if (g2-myArm.gamma_>5)
    {
        myArm.gamma_+=5;
        update();
    }

    else if (myArm.gamma_-g2>5)
    {
        myArm.gamma_-=5;
        update();
    }

    // Angle gamma bon

    else if (myArm.delta_>=30)
    {
        myArm.delta_-=10;
        update();
    }


        else
        {
            timerToDrop->stop();
            timerToDrop->disconnect(timerToDrop, SIGNAL(timeout()), this, SLOT(dropSphere()));
            boolSphereArm=false; // le bras ne tient plus la sphere

            mySphere.setX(myHole.getX());
            mySphere.setY(myHole.getY());

            boolSphereArena=true; // la sphere est sur l'arene

            myArm.boolSphereArm_=false;
            removeSphere(4);
        }
}

void Game :: appearSphere()
{

    boolSphereArena = true; // il y a une sphere sur le jeu

    float xLimitLow = myHole.getX() - myHole.getRadius()-1;
    float yLimitLow = myHole.getY() - myHole.getRadius()+1;
    float xLimitHigh = myHole.getX() + myHole.getRadius()+1;
    float yLimitHigh = myHole.getY() + myHole.getRadius()+1;

    QPointF p = getRandomCoordinates(mySphere.getRadius());
    mySphere.setX(p.x());
    mySphere.setY(p.y());

    // on s'assure de ne pas placer la cible sur le trou

    while (mySphere.getX()<xLimitHigh && mySphere.getX()>xLimitLow && mySphere.getY()<yLimitHigh && mySphere.getY()>yLimitLow )
    {
        qDebug()<<"Boucle Sphere";
        p = getRandomCoordinates(mySphere.getRadius());
        mySphere.setX(p.x());
        mySphere.setY(p.y());

    }

    update();

}


void Game::appearTarget(int r)
{
    myTarget.setRadius(r-0.5); // on reduit le rayon de la cible
    boolTarget = true; // il y a un trou sur le jeu

    float xLimitLow = myHole.getX() - myHole.getRadius()-1;
    float yLimitLow = myHole.getY() - myHole.getRadius()+1;
    float xLimitHigh = myHole.getX() + myHole.getRadius()+1;
    float yLimitHigh = myHole.getY() + myHole.getRadius()+1;

    QPointF p = getRandomCoordinates(myTarget.getRadius());
    myTarget.setX(p.x());
    myTarget.setY(p.y());

    // on s'assure de ne pas placer la cible sur le trou

    while (myTarget.getX() + myTarget.getRadius()<xLimitHigh && myTarget.getX()+myTarget.getRadius()>xLimitLow && myTarget.getY()+myTarget.getRadius()<yLimitHigh && myTarget.getY()+myTarget.getRadius()>yLimitLow )
    {
        qDebug()<<"Boucle target";
        p = getRandomCoordinates(myTarget.getRadius());
        myTarget.setX(p.x());
        myTarget.setY(p.y());

    }

    update();
}

QPointF Game :: getRandomCoordinates (double d)
{
    float high = myArena.getSize() - 2;
    float low = - myArena.getSize() - 2;

    QPointF point; // point ou l'on va mettre l'element
    point.setX(0);
    point.setY(0);

    double distance = 0;

    while (distance<1+d || distance>18-d) // on ne doit pas avoir un element trop proche du bras ni en dehors de l'arene
    {

        float range = high-low;

        float randomY = ((float) rand()) / (float) RAND_MAX; // on calcule a nouveau un relatif pour y
        point.setY(randomY*range+low);
        float randomX = ((float) rand()) / (float) RAND_MAX; // on calcule un relatif pour x
        point.setX(randomX*range+low);
        distance = sqrtf (point.x()*point.x()+point.y()*point.y());

    }
    return point;
}


void Game::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

bool Game::detectVictory()
{

    qDebug()<<"Sphere: "<<mySphere.getX()<<"  --  "<<mySphere.getY();
    qDebug()<<"Target: "<<myTarget.getX()<<"  --  "<<myTarget.getY();
    qDebug()<<"condition 1: "<<mySphere.getRadius() +mySphere.getX() - myTarget.getX()+myTarget.getRadius()<<" --- "<<mySphere.getRadius() +mySphere.getY() - myTarget.getY()+myTarget.getRadius();

    qDebug()<<"condition 2: "<<myTarget.getX()+myTarget.getRadius() - mySphere.getRadius() +mySphere.getX()<<" --- "<<myTarget.getY()+myTarget.getRadius()-mySphere.getRadius() +mySphere.getY();
    if (mySphere.getRadius() +mySphere.getX() - myTarget.getX()+myTarget.getRadius() <1)
    {
        if (mySphere.getRadius() +mySphere.getY() - myTarget.getY()+myTarget.getRadius() <1)
        {
            return true;
        }

    }

    else if (myTarget.getX()+myTarget.getRadius() - mySphere.getRadius() +mySphere.getX() <1)
    {
        if (myTarget.getY()+myTarget.getRadius()-mySphere.getRadius() +mySphere.getY() <1)
        {
            return true;
        }
    }

    else
    {
        return false;
    }
}

void Game::setNextLevel()
{
    appearTarget(myTarget.getRadius());
    appearSphere();
}
