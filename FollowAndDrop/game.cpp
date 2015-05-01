#include "game.h"
#include <QTimer>

#include <QtWidgets>
#include <QtOpenGL>
#include <GL/glu.h>
#include <GL/gl.h>
#include<iostream>

using namespace std;


Game::Game(QWidget *parent) :
    QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;

    xRandom=5;
    yRandom=0;
    zRandom=7;

    /*QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(10);

    int VALUE = 10;

    timer -> start(VALUE);*/

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
    //qDebug()<<"Game:qNormalizeAngle";
    //while (angle < 0)
        //angle += 360 * 20;
        //angle +=360;
    //while (angle > 360)
        //angle -= 360 * 20;
        //angle -= 360;
}

void Game::setXRotation(int angle)
{
    //qDebug()<<"Game: setXRotation";
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void Game::setYRotation(int angle)
{
    //qDebug()<<"Game: setYRotation";
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void Game::setZRotation(int angle)
{
    //qDebug()<<"Game: setZRotation";
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}


void Game::initializeGL()
{
    qDebug()<<"Game: init";

    theArena = glGenLists(5);

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
    glEndList();

}

void Game::paintGL()
{
    qDebug()<<"Game: paintGL";
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glLoadIdentity();


    // initalize the coordinate system to correct alignement

    glTranslatef(0.0, -5.0, -20.0);
    glRotatef(40, -1, 0, 0);

    /*glRotatef(-xRot/16, 0.0, 1.0, 0.0); //theta
    glRotatef(-yRot/16, 0.0, 0.0, 1.0); //phi
    glRotatef(-zRot/16, 1.0, 0.0, 0.0);*/

    //glRotatef(-xRot/16, 1.0, 0.0, 0.0); //theta
    glRotatef(-yRot/16, 0.0, 0.0, 1.0); //phi
    //glRotatef(-zRot/16, 1.0, 0.0, 0.0);

    draw();


}

void Game::resizeGL(int width, int height)
{
    qDebug()<<"Game: resizeGL";
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(110, ((float)width/(float)height),0.01,30);
    glMatrixMode(GL_MODELVIEW);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<"Game: mouseEvent";
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dx);
        setYRotation(yRot + 8 * dy);
        //setZRotation(zRot + 8 * dy);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dx);
        setZRotation(zRot + 8 * dy);
    }

    lastPos = event->pos();
}

void Game::draw()
{
    qDebug()<<"Game: draw";

    qDebug()<<xRot<<"-"<<yRot<<"-"<<zRot;
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

        /* Ces lignes servent a incrementer ou decrementer
         * l'attribut chrono pour le deplacement*/

        /*glTranslatef(chrono *-.5,0,0);
        if (chrono <10)
        {
            chrono +=1;
        }

        else
        {
            chrono -=104;
        }

        //qDebug()<<chrono;*/


        //glColor3f(1,0,.8);
        glTranslatef(1,.2,7);
        glCallList(theArena);


        //glTranslatef(10,13,3);
        glCallList(theArticulateArm);

        glTranslatef(0,5,0);
        glCallList(theTarget);


    glPopMatrix();



    glPushMatrix();

        glTranslatef(xRandom, yRandom, zRandom);
        glCallList(theSphere);

    glPopMatrix();

    //glCallList(theArticulateArm);




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







