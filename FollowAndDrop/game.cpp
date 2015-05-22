#include "game.h"
#include <QTimer>

#include <QtWidgets>
#include <QtOpenGL>
#include <GL/glu.h>
#include <GL/gl.h>
#include "math.h"
#include<iostream>

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

    timer = new QTimer(this);

}

Game::~Game()
{
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

    /*theArena = glGenLists(5);

    glNewList(theArena, GL_COMPILE);
         myArena.drawArena();

    glEndList();

    theSphere = glGenLists(3);

    glNewList(theSphere, GL_COMPILE);
         mySphere.drawSphere(2,20,20);
    glEndList();

    theTarget = glGenLists(6);

    glNewList(theTarget, GL_COMPILE);
        myTarget.drawTarget();
    glEndList();

    theArm = glGenLists(7);

    glNewList(theArm, GL_COMPILE);
        myArm.drawArm();
    glEndList();

    theArticulateArm = glGenLists(1);

    glNewList(theArticulateArm, GL_COMPILE);
        myArticulateArm.drawArm();
    glEndList();*/

    glDisable(GL_CULL_FACE);



}

void Game::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glLoadIdentity();


    // initalize the coordinate system to correct alignement

    glTranslatef(0.0, 0.0, -30.0);
    glRotatef(70, -1, 0.0, 0.0);

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
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(intGluPerspective, ((float)width/(float)height),0.01,1000);
    glMatrixMode(GL_MODELVIEW);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
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

    if (boolTarget==true)
    {
        glPushMatrix();
            glTranslatef(myTarget.xTarget, myTarget.yTarget,0);
            myTarget.drawTarget();
        glPopMatrix();

    }

    if (boolSphere==true)
    {
        glPushMatrix();
            glTranslatef(mySphere.xSphere, mySphere.ySphere,0);
            mySphere.drawSphere(2,20,20);
        glPopMatrix();
    }

    if (boolHole==true)
    {
        glPushMatrix();
            glTranslatef(myHole.xHole, myHole.yHole, 0);
            myHole.drawHole();
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


void Game::appearTarget()
{

    boolTarget = true;
    update();
}

void Game::dropSphere()
{

    double cosAngle1 = (myArm.sA*myArm.sA+myTarget.r*myTarget.r-myArm.sFa*myArm.sFa)/(2*myArm.sA*myTarget.r);
    double cosAngle2 = (myArm.sA*myArm.sA+myArm.sFa*myArm.sFa-myTarget.r*myTarget.r)/(2*myArm.sA*myArm.sFa);

    double angle1 = acos(cosAngle1); // angle1 en radian
    double angle2 = acos(cosAngle2); // angle2 en radian

    angle1 = angle1 *180 / PI;
    angle2 = angle2 * 180 /PI;

    double a = myTarget.thetaTarget;
    double b = 90 - angle1;
    double g = 180 - angle2;

    qDebug()<<"alpha;"<<a<<"% beta:"<<b<<"% gamma:"<<g;
    cout<<"Bras:"<<myArm.alpha<<" % "<<myArm.beta<<" % "<<myArm.gamma<<endl;

    if (a>0 && myArm.alpha<a)
    {

        myArm.alpha+=1;
        update();
    }

    else if (a<0 && myArm.alpha>a)
    {
        myArm.alpha-=1;
        update();
    }

    else
    {
        if (myArm.beta<b)
        {
            myArm.beta+=1;
            update();
        }

        else
        {
            if (myArm.gamma<g)
            {
                myArm.gamma+=1;
                update();
            }

            else if (myArm.boolSphere == false)
            {
                myArm.boolSphere = true;
                update();
            }

            else if (myArm.delta<55)

            {
                myArm.delta+=1;
                update();


            }

            else
            {
                timer->stop();
            }
        }

    }


}


void Game :: startChrono()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(dropSphere()));
    timer->start(1);

}

void Game :: appearSphere()
{
    boolSphere = true;
    update();
}

void Game :: appearHole()
{
    boolHole = true;
    update();
}

