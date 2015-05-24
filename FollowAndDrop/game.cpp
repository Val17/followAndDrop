#include "game.h"
#define PI 3.14159265

using namespace std;

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
    boolSphere = false;
    boolHole = false;
    boolDrop = false;

    intGluPerspective = 80;

    timerCatch = new QTimer(this);
    timerMoveArm = new QTimer(this);
    timerDrop = new QTimer(this);
}

Game::~Game()
{
    delete timerCatch;
    delete timerMoveArm;
    delete timerDrop;
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
    glDisable(GL_CULL_FACE);
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

    glPushMatrix();
        myArena.drawArena();
    glPopMatrix();

    glPushMatrix();
        myArm.drawArm();
    glPopMatrix();


    if (boolSphere == true)
    {
        glPushMatrix();
            glTranslatef(mySphere.getX(), mySphere.getY(),0);
            mySphere.drawSphere(1, 50, 50);
        glPopMatrix();
    }

        // On fait apparaitre un trou

    if (myHole.xHole_ == 0 && myHole.yHole_==0)
    {
        myHole.xHole_=getRandomCoordinates().x();
        myHole.yHole_=getRandomCoordinates().y();
        myHole.setRadius(getRandomRadius());
    }

        glPushMatrix();
            glTranslatef(myHole.xHole_, myHole.yHole_,0);
            myHole.drawHole();
        glPopMatrix();

        // On fait apparaitre un trou

        if (myTarget.getX() == 0 && myTarget.getY()==0)
        {
            myTarget.setX(getRandomCoordinates().x());
            myTarget.setY(getRandomCoordinates().y());
            myTarget.setRadius(getRandomRadius());
            //qDebug()<<myTarget.getX()<<"-"<<myTarget.getY()<<"-"<<myTarget.getDistance();
        }

        if (boolTarget == true)
        {
            glPushMatrix();
                glTranslatef(myTarget.getX(), myTarget.getY(),0);
                //qDebug()<<myTarget.getX()<<"-"<<myTarget.getY()<<"-"<<myTarget.getDistance();
                myTarget.drawTarget();
            glPopMatrix();

        }


}

GLuint Game::loadtgadisplayCDV ( const char* filename )
{
    FILE* fp;
    char magic[12];
    unsigned char header[6];
    int imageSize;
    GLenum type;
    char temp;
    int i;
    int bpp,width,height;

    GLuint textureId;

    int globalWidth = 1;
    int globalHeight = 1;
    char* imageData;
    char* imageTmp;
    if(!(fp = fopen(filename, "rb"))) return 0;
    if(!fread(&magic, 12, 1, fp)) return 0;
    if(!fread(&header, 6, 1, fp)) return 0;
    bpp = header[4];
    width  = header[1] * 256 + header[0];
    height = header[3] * 256 + header[2];
    if(width <= 0 || height <= 0) return 0;
    if(bpp != 24 && bpp != 32) return 0;
    imageSize = width * height * (bpp / 8);
    imageData = (char *)malloc(sizeof(char) * imageSize);
    if(imageData == NULL) return 0;
    if(!fread(imageData, imageSize, 1, fp)) { free(imageData); return 0; }
    for(i = 0; i < imageSize; i += bpp / 8) {
    temp = imageData[i];
    imageData[i] = imageData[i + 2];
    imageData[i + 2] = temp; }
    if(bpp == 32) for(i=0;i<imageSize;i+=4) imageData[i+3]=255-imageData[i+3];
    fclose(fp);
    while (width>globalWidth) globalWidth*=2;
    while (height>globalHeight) globalHeight*=2;
    glEnable( GL_TEXTURE_2D );
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPixelStorei(GL_UNPACK_ROW_LENGTH,globalWidth);
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    if(bpp == 24) type=GL_RGB; else type=GL_RGBA;
    imageTmp = (char *)malloc(sizeof(char)*globalWidth*globalHeight*4);
    if (imageTmp==NULL) return 0;
    glTexImage2D(GL_TEXTURE_2D,0,type,globalWidth,globalHeight,0,
    type,GL_UNSIGNED_BYTE,imageTmp);
    free (imageTmp );
    glPixelStorei(GL_UNPACK_ROW_LENGTH,width);
    glTexSubImage2D(GL_TEXTURE_2D,0, 0,0, width, height,
    type ,GL_UNSIGNED_BYTE, imageData );
    free(imageData);

    return textureId;

}


void Game::catchSphere()
{
    qDebug()<<"catch";
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

   //qDebug()<<"Angles du bras: "<<myArm.alpha<<" et "<<myArm.beta<<" et "<<myArm.gamma<<" et "<<myArm.delta;


   // qDebug()<<"Angles a atteindre: "<<a1<<" et "<<b1<<" et "<<g1;


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

    else if (boolSphere==true)
    {
        boolSphere=false; // on fait disparaitre la sphere
        myArm.boolSphere=true; // on fait aparaitre celle dans le bras
        update();
    }

    else
    {
        timerCatch->stop();
        boolDrop = true;
        removeSphere(2);
    }

}


void Game :: removeSphere(int step)
{
    if (step==1)
    {
        connect(timerCatch, SIGNAL(timeout()), this, SLOT(catchSphere()));
        timerCatch->start(10);
    }

    else if (step==2)
    {
        connect(timerMoveArm, SIGNAL(timeout()), this, SLOT(reinitializeArm()));
        timerMoveArm->start(10);
    }

    else if (step==3)
    {
        connect(timerDrop, SIGNAL(timeout()),this,SLOT(dropSphere()));
        timerDrop->start(10);
    }

    else if (step==4)
    {
        connect(timerMoveArm, SIGNAL(timeout()), this, SLOT(reinitializeArm()));
        timerMoveArm->start(10);
    }

}

void Game::reinitializeArm()
{
    // La sphere est attrapee; on ramene le bras a sa position initiale

    if (myArm.alpha>5)
    {
        myArm.alpha-=5;
        update();
    }

    else if (myArm.alpha<0)
    {
        myArm.alpha+=5;
        update();
    }

    if (myArm.beta>5)
    {
        myArm.beta-=5;
        update();
    }

    else if (myArm.beta<0)
    {
        myArm.beta+=5;
        update();
    }

    if (myArm.gamma>5)
    {
        myArm.gamma-=5;
        update();
    }

    else if (myArm.gamma<0)
    {
        myArm.gamma+=5;
        update();
    }

    // Le bras est en position initiale et a la sphere
    else if (boolDrop==true)
    {
        timerMoveArm->stop();

        removeSphere(3);
    }

    else if (boolDrop==false)
    {
        timerMoveArm->stop();
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
    double a2 = myHole.thetaHole;
    double b2 = 90 - angleA2;
    double g2 = 180 - angleB2;
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
            timerDrop->stop();
            boolDrop=false; // le bras ne tient plus la sphere

            mySphere.setX(myHole.xHole_);
            mySphere.setY(myHole.yHole_);

            boolSphere=true; // la sphere est sur l'arene

            myArm.boolSphere=false;
            removeSphere(4);
        }
}

void Game :: appearSphere()
{

    boolSphere = true; // il y a une sphere sur le jeu
    mySphere.setX(getRandomCoordinates().x());
    mySphere.setY(getRandomCoordinates().y());

    qDebug()<<"Sphere:"<<mySphere.getX()<<" et "<<mySphere.getY();
    qDebug()<<"Angle sphere:" <<mySphere.thetaSphere;

    update();
}

void Game :: appearHole()
{
    boolHole = true; // il y a un trou sur le jeu
    myHole.xHole_ = getRandomCoordinates().x();
    myHole.yHole_ = getRandomCoordinates().y();
    myHole.setRadius(getRandomRadius());

    qDebug()<<"Hole:"<<myHole.xHole_<<" et "<<myHole.yHole_;

    update();
}

void Game::appearTarget()
{
    boolTarget = true; // il y a un trou sur le jeu

    int xLimitLow = myHole.xHole_ + myHole.getRadius();
    int yLimitLow = myHole.yHole_ + myHole.getRadius();

    myTarget.setX(getRandomCoordinates().x());
    myTarget.setY(getRandomCoordinates().y());

    myTarget.setRadius(getRandomRadius()); // rayon aleatoire

    while (myTarget.getX()>xLimitLow && myTarget.getY()>yLimitLow) // on s'assure de ne pas plaer la cible sur le trou
    {
        qDebug()<<"Boucle target";
        myTarget.setX(getRandomCoordinates().x());
        myTarget.setY(getRandomCoordinates().y());
    }

    qDebug()<<"Target:"<<myTarget.getX()<<" et "<<myTarget.getY();
    update();
}

QPoint Game :: getRandomCoordinates ()
{
    int high = myArena.size /2;
    int low = - myArena.size /2;

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
