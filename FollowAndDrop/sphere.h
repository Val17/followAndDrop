#ifndef SPHERE_H
#define SPHERE_H

#include <QObject>
#include <QGLWidget>
#include <math.h>
#include <GL/gl.h>
#include <stdio.h>
#include <GL/glu.h>
#include <QDebug>

class Sphere : public QObject
{
    Q_OBJECT
public:
    explicit Sphere();
    double xSphere; // abscisse aleatoire
    double ySphere; // ordonnee aleatoire
    double thetaSphere; // angle d'orientation de la sphere
    double tanThetaSphere;
    double r; // distance entre le centre de l'arene et la sphere
    void drawSphere(double radius, int slices, int stacks);
    bool isMovable(int x, int y, int s);
signals:

public slots:

protected:
    GLuint loadtgadisplayCDV(const char *filename);
private:

    GLuint GLtexture[1];

};

#endif // SPHERE_H
