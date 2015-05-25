#ifndef ARM_H
#define ARM_H

#include <QWidget>
#include <QGLWidget>
#include <GL/glu.h>
#include "math.h"
#include <stdio.h>
#include<iostream>
#include <QDebug>
#include <QMouseEvent>

class Arm : public QGLWidget
{
    Q_OBJECT
    void drawSphereGame(double r, int lats, int stacks);
public:
    explicit Arm(QGLWidget *parent = 0);
    ~Arm();
    GLuint loadtgadisplayCDV ( const char* filename );
    void drawArm();
    void drawSphere(double r, int lats, int longs);
    void drawCylinder(double r,int height, int lats, int stacks);
    double alpha;
    double beta;
    double gamma;
    double delta;
    double theta;
    double sA; // taille du bras (arm)
    double sFa; // taille de l'avant bras (forearm)
    bool boolSphereArm;
    int altitud;

    void catchSphere(double t);
    void drawBase();
public slots:

signals:

};

#endif // BRASARTICULE_H