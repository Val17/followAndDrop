#ifndef TARGET_H
#define TARGET_H

#include <QWidget>
#include <QGLWidget>
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

    double thetaTarget_; // angle d'orientation de la cible
    double tanThetaTarget_;


    void setRadius(int r) {radius_ = r;}
    int getRadius() {return radius_;}
    int getDistance() {return r_;}

    double getX() {return xTarget_;}
    double getY() {return yTarget_;}

    void setX(int x) { xTarget_=x;}
    void setY(int y) { yTarget_=y;}


protected:

signals:

public slots:

private:

    double radius_; // rayon de la cible
    double r_; // distance entre le centre de l'arene et la cible
    double xTarget_; // abscisse
    double yTarget_; // ordonnee

};

#endif // TARGET_H
