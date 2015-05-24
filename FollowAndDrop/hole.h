#ifndef HOLE_H
#define HOLE_H

#include <QObject>
#include <QGLWidget>
#include <math.h>
#include <GL/gl.h>
#include <stdio.h>
#include <GL/glu.h>
#include <QDebug>


class Hole
{
public:
    Hole();
    void drawHole();
    void setRadius(int r) {radius_ = r;}
    void setX(float x) {xHole_=x;}
    void setY(float y) {yHole_=y;}

    int getRadius() {return radius_;}
    float getDistance() {return r_;}
    float getX() {return xHole_;}
    float getY() {return yHole_;}
    float getTheta() {return thetaHole_;}
    float getTanTheta() {return tanThetaHole_;}

protected:


private:

    GLuint glTexture[1];
    GLuint loadTexture(const char *filename); //methode permettant de charger la texture
    int radius_; // rayon du trou
    float r_; // distance du centre du trou par rapport  au trou
    float xHole_;
    float yHole_;
    float thetaHole_; // angle d'orientation du trou
    float tanThetaHole_; // tangente de cet angle
};

#endif // HOLE_H
