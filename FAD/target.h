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

    void setRadius(float r) {radius_ = r;}
    float getRadius() {return radius_;}
    double getTheta() {return thetaTarget_;}
    float getDistance() {return r_;}

    float getX() {return xTarget_;}
    float getY() {return yTarget_;}

    void setX(float x) { xTarget_=x;}
    void setY(float y) { yTarget_=y;}


protected:

signals:

public slots:

private:

    float radius_; // rayon de la cible
    float r_; // distance entre le centre de l'arene et la cible
    float xTarget_; // abscisse
    float yTarget_; // ordonnee
    double thetaTarget_; // angle d'orientation de la cible
    double tanThetaTarget_;

};

#endif // TARGET_H
