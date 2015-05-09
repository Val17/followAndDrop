#ifndef BRASARTICULE_H
#define BRASARTICULE_H

#include <QWidget>
#include <QGLWidget>
#include <GL/glu.h>
#include "math.h"
#include <stdio.h>
#include<iostream>
#include <QDebug>
#include <QMouseEvent>

class ArticulateArm : public QGLWidget
{
    Q_OBJECT
public:
    explicit ArticulateArm(QGLWidget *parent = 0);
    ~ArticulateArm();
    GLuint loadtgadisplayCDV ( const char* filename );
    void drawArm();
    void drawSphere(double r, int lats, int longs);
    void drawCylinder(double r,int height, int lats, int stacks);
    int alpha;
    int beta;
    int gamma;
    int delta;
    int epsilon;

    void moveShoulder(int b);
    //void moveShoulder(int a);
    void movePliers(int g);
    void moveHand(int d);
    void catchSphere(int a, int b, int d, int g);
    void moveBase(int e);
public slots:


};

#endif // BRASARTICULE_H
