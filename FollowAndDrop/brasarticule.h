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
    double alpha;
    double beta;
    double gamma;
    double delta;
    double theta;

    void catchSphere(double t);
public slots:

signals:

};

#endif // BRASARTICULE_H
