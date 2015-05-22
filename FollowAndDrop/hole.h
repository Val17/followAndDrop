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

    void drawHole();

protected:
    GLuint loadtgadisplayCDV(const char *filename);

private:

    GLuint GLtexture[1];
};

#endif // HOLE_H
