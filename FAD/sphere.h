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

    void drawSphere();
    bool isMovable(int x, int y, int s);
    int getDistance() {return r_;}
    double getX() {return xSphere_;}
    double getY() {return ySphere_;}
    double getZ() {return zSphere_;}
    double getRadius() {return radius_;} // retourne le rayon de la sphere
    void setX(int x) { xSphere_=x;}
    void setY(int y) { ySphere_=y;}
    void setZ(float z) { zSphere_=z;}

signals:

public slots:

protected:
    GLuint loadtgadisplayCDV(const char *filename);
private:
    double r_; // distance entre le centre de l'arene et la sphere
    double radius_; // rayon de la sphere
    double xSphere_; // abscisse
    double ySphere_; // ordonnee
    float zSphere_; // hauteur

    GLuint GLtexture[1];

};

#endif // SPHERE_H
