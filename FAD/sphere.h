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



    void drawSphere();
    bool isMovable(int x, int y, int s);
    int getDistance() {return r_;}
    float getX() {return xSphere_;}
    float getY() {return ySphere_;}
    float getZ() {return zSphere_;}
    float getRadius() {return radius_;} // retourne le rayon de la sphere
    void setX(int x) { xSphere_=x;}
    void setY(int y) { ySphere_=y;}
    void setZ(float z) { zSphere_=z;}
    double getTheta() {return thetaSphere_;}

signals:

public slots:

protected:
    GLuint loadtgadisplayCDV(const char *filename);
private:
    double r_; // distance entre le centre de l'arene et la sphere
    float radius_; // rayon de la sphere
    float xSphere_; // abscisse
    float ySphere_; // ordonnee
    float zSphere_; // hauteur
    double thetaSphere_; // angle d'orientation de la sphere
    double tanThetaSphere_;

    GLuint GLtexture[1];

};

#endif // SPHERE_H
