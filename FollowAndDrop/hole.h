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
    double xHole_;
    double yHole_;
    double thetaHole; // angle d'orientation du trou
    double tanThetaHole; // tangente de cet angle


    void drawHole();
    void setRadius(int r) {radius_ = r;}
    int getRadius() {return radius_;}
    int getDistance() {return r_;}

protected:
    GLuint loadtgadisplayCDV(const char *filename);

private:

    GLuint GLtexture[1];
    int radius_; /// rayon du trou
    double r_; // distance du centre du trou par rapport  au trou
};

#endif // HOLE_H
