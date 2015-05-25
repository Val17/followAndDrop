#ifndef TARGET_H
#define TARGET_H

#include <QWidget>
#include <QGLWidget>
#include <GL/glu.h>
#include "math.h"
#include <stdio.h>
#include<iostream>
#include <QDebug>
#include <QMouseEvent>
#include <arena.h>
#include <sphere.h>

class Target : public QGLWidget
{
    Q_OBJECT
public:
    explicit Target(QWidget *parent = 0);
    GLuint loadtgadisplayCDV(const char *filename);
    void drawTarget();
    GLuint GLtexture[1];

    double thetaTarget_; // angle d'orientation de la cible
    double tanThetaTarget_;


    void setRadius(float r) {radius_ = r;}
    float getRadius() {return radius_;}
    int getDistance() {return r_;}

    double getX() {return xTarget_;}
    double getY() {return yTarget_;}

    void setX(int x) { xTarget_=x;}
    void setY(int y) { yTarget_=y;}


protected:

signals:

public slots:

private:

    float radius_; // rayon de la cible
    float r_; // distance entre le centre de l'arene et la cible
    float xTarget_; // abscisse
    float yTarget_; // ordonnee

};

#endif // TARGET_H
