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

    double thetaSphere; // angle d'orientation de la sphere
    double tanThetaSphere;

    void drawSphere(double radius, int slices, int stacks);
    bool isMovable(int x, int y, int s);
    int getDistance() {return r_;}
    double getX() {return xSphere_;}
    double getY() {return ySphere_;}

    void setX(int x) { xSphere_=x;}
    void setY(int y) { ySphere_=y;}
signals:

public slots:

protected:
    GLuint loadtgadisplayCDV(const char *filename);
private:
    double r_; // distance entre le centre de l'arene et la sphere
    double xSphere_; // abscisse aleatoire
    double ySphere_; // ordonnee aleatoire

    GLuint GLtexture[1];

};

#endif // SPHERE_H
