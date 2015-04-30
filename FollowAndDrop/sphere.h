#ifndef SPHERE_H
#define SPHERE_H

#include <QObject>
#include <QGLWidget>
#include <math.h>
#include <GL/gl.h>
#include <stdio.h>
#include <GL/glu.h>

class Sphere : public QObject
{
    Q_OBJECT
public:
    explicit Sphere(QObject *parent = 0);

    void drawSphere(double radius, int slices, int stacks);
signals:

public slots:

protected:
    GLuint loadtgadisplayCDV(const char *filename);
private:

    GLuint GLtexture[1];

};

#endif // SPHERE_H