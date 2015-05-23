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

    boolDrop = false;
    boolArena = false;
    boolArm = true;
    boolTarget = false;
    boolSphere = false;
    boolHole = false;

    intGluPerspective = 80;
    altitud = 0;

    timerCatch = new QTimer(this);
}

Game::~Game()
{
    delete timerCatch;
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
    //glViewport((width - side) / 2, (height - side) / 2, side, side);

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

    if (boolArm==true)
    {
        glPushMatrix();
            myArena.drawArena();
        glPopMatrix();

        glPushMatrix();
            myArm.drawArm();
        glPopMatrix();
    }

    if (boolSphere == true)
    {
        glPushMatrix();
            glTranslatef(mySphere.xSphere, mySphere.ySphere,0);
            mySphere.drawSphere(1, 50, 50);

            //qDebug()<<mySphere.xSphere<<"-"<<mySphere.ySphere<<"-"<<mySphere.r;
        glPopMatrix();
    }

    /*if (myHole.xHole == 0 && myHole.yHole==0)
    {
        myHole.xHole=getRandomCoordinates().x();
        myHole.yHole=getRandomCoordinates().y();
    }

        glPushMatrix();
            glTranslatef(myHole.xHole, myHole.yHole,0);
            myHole.drawHole();

        glPopMatrix();*/

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


void Game::moveArm()
{
    /*
     * Calcul des angles beta et gamma du bras
     * Methode: Theoreme d'Al-Khashi
     * Modelisation: triangle forme par les sommets:
     * - centre de la sphere/epaule du bras
     * - centre de la sphere/coude du bras
     * - centre de la sphere a attraper*/

    ///Cotes du triangle

    double side1 = myArm.sA+2; // cote 1 du triangle
    double side2 = myArm.sFa+2; // cote 2 du triangle
    double side3 = mySphere.r; // cote 3 du triangle

    /// Cosinus

    double cosAngle1 = (side1*side1+side3*side3-side3*side3)/(2*side1*side3); // angle beta a atteindre
    double cosAngle2 = (side1*side1+side2*side2-side3*side3)/(2*side1*side2); // angle gamma a atteindre

    ///Angles en degres

    double angle1 = acos(cosAngle1) * 180 / PI; // angle1 en radian
    double angle2 = acos(cosAngle2) * 180/ PI; // angle2 en radian

    ///Limites
    double a = mySphere.thetaSphere;
    double b = 90 - angle1;
    double g = 180 - angle2;

    qDebug()<<"Angles a atteindre: "<<a<<" et "<<b<<" et "<<g;
    cout<<"Angles du bras: "<<myArm.alpha<<" et "<<myArm.beta<<" et "<<myArm.gamma<<endl;

    if (a-myArm.alpha>1)
    {
        myArm.alpha+=1;
        update();
    }

    else if (myArm.alpha-a>1)
    {
        myArm.alpha-=1;
        update();
    }

     // Orientation bonne

    else if (b-myArm.beta>1)
    {
        myArm.beta+=1;
        update();
    }

    else if (myArm.beta-b>1)
    {
        myArm.beta-=1;
        update();
    }

    // Angle beta bon

    else if (g-myArm.gamma>1)
    {
        myArm.gamma+=1;
        update();
    }

    else if (myArm.gamma-g>1)
    {
        myArm.gamma-=1;
        update();
    }

    else
    {
        qDebug()<<"Cotes du triangle: "<<side1<<" "<<side2<<" "<<side3;
        timerCatch->stop();
    }
}


void Game :: catchSphere()
{
    connect(timerCatch, SIGNAL(timeout()), this, SLOT(moveArm()));
    timerCatch->start(1);
}

void Game :: appearSphere()
{

    boolSphere = true; // il y a une sphere sur le jeu
    mySphere.xSphere = getRandomCoordinates().x();
    mySphere.ySphere = getRandomCoordinates().y();

    /*qDebug()<<"Sphere:"<<mySphere.xSphere<<" et "<<mySphere.ySphere;
    qDebug()<<"Angle sphere:" <<mySphere.thetaSphere;*/

    update();
}

void Game :: appearHole()
{
    boolHole = true; // il y a un trou sur le jeu
    myHole.xHole = getRandomCoordinates().x();
    myHole.yHole = getRandomCoordinates().y();

    //qDebug()<<"Hole:"<<myHole.xHole<<" et "<<myHole.yHole;

    update();
}

void Game::appearTarget()
{

    boolTarget = true; // il y a un trou sur le jeu
    myTarget.xTarget = getRandomCoordinates().x();
    myTarget.yTarget = getRandomCoordinates().y();

    //qDebug()<<"Target:"<<myTarget.xTarget<<" et "<<myTarget.yTarget;

    update();
}

QPoint Game :: getRandomCoordinates ()
{
    qDebug()<<"coord";
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
    qDebug()<<lastPos;
}


