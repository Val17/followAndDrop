// myglwidget.cpp

#include <QtWidgets>
#include <QtOpenGL>
#include <GL/glu.h>
#include <GL/gl.h>
#include<iostream>

using namespace std;
#include "myglwidget.h"

MyGLWidget::MyGLWidget(QWidget *parent)
    : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    xRot = 0;
    yRot = 0;
    zRot = 0;
    GLtexture[0];

}

MyGLWidget::~MyGLWidget()
{
}

QSize MyGLWidget::minimumSizeHint() const
{
    return QSize(50, 50);
}

QSize MyGLWidget::sizeHint() const
{
    return QSize(400, 400);
}

static void qNormalizeAngle(int &angle)
{

    while (angle < 0)
        angle += 360 * 20;
    while (angle > 360)
        angle -= 360 * 20;
}

void MyGLWidget::setXRotation(int angle)
{
    qDebug()<<"MyGLWidget: setXRotation";
    qNormalizeAngle(angle);
    if (angle != xRot) {
        xRot = angle;
        emit xRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setYRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != yRot) {
        yRot = angle;
        emit yRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::setZRotation(int angle)
{
    qNormalizeAngle(angle);
    if (angle != zRot) {
        zRot = angle;
        emit zRotationChanged(angle);
        updateGL();
    }
}

void MyGLWidget::initializeGL()
{
    qDebug()<<"initializeGL";
    glClearColor(0,.5,0,0);
    /*glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    static GLfloat lightPosition[4] = { 0, 0, 10, 1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);*/

    //glEnable(GL_LIGHT0);

    //GLtexture[0]= loadtgadisplayCDV("../FollowAndDrop/bois.tga");
}

void MyGLWidget::paintGL()
{
    qDebug()<<"paintGL";
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    // initalize the coordinate system to correct alignement

    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(60, -1, 0, 0);


    //perform world transformation

    glRotatef(-xRot/1, 0.0, 1.0, 0.0); //theta
    glRotatef(-yRot/1, 0.0, 0.0, 1.0); //phi
    glRotatef(-zRot/1, 1.0, 0.0, 0.0);



    draw();
}

void MyGLWidget::resizeGL(int width, int height)
{
    qDebug()<<"resizeGL";
    int side = qMin(width, height);
    glViewport((width - side) / 2, (height - side) / 2, side, side);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    /*
#ifdef QT_OPENGL_ES_1
    glOrthof(-2, +2, -2, +2, 1.0, 15.0);
#else
    glOrtho(-2, +2, -2, +2, 1.0, 15.0);
#endif
    */
    gluPerspective(100, ((float)width/(float)height),0.01,30);
    glMatrixMode(GL_MODELVIEW);
}

void MyGLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void MyGLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton) {
        setXRotation(xRot + 8 * dy);
        setYRotation(yRot + 8 * dx);
    } else if (event->buttons() & Qt::RightButton) {
        setXRotation(xRot + 8 * dy);
        setZRotation(zRot + 8 * dx);
    }

    lastPos = event->pos();
}

void MyGLWidget::draw()
{

    qDebug()<<"draw";
    GLUquadric* params = gluNewQuadric();
    //glColor3f(1,0,0);
    gluQuadricDrawStyle(params,GLU_LINE);
    gluSphere(params,0.75,20,20);

    //gluCylinder(params,1,1,2,20,1);

    //gluLookAt(3,4,2,0,0,0,0,0,1);



}


GLuint MyGLWidget::loadtgadisplayCDV ( const char* filename )
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
if(!(fp = fopen(filename, "rb")))
{
    cout <<"erreur 1"<< endl;
    return 0;
}
if(!fread(&magic, 12, 1, fp))
{
    cout <<"erreur 2"<< endl;
    return 0;
}
if(!fread(&header, 6, 1, fp))
{
    {
        cout <<"erreur 3"<< endl;
        return 0;
    }
}
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