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
    double xHole;
    double yHole;
    int radius; /// rayon du trou
    double thetaHole; // angle d'orientation du trou
    double tanThetaHole; // tangente de cet angle
    double r; // distance du centre du trou par rapport  au trou

    void drawHole();

protected:
    GLuint loadtgadisplayCDV(const char *filename);

private:

    GLuint GLtexture[1];
};

#endif // HOLE_H
