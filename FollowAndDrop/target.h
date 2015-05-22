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
    double xTarget; // abscisse aleatoire
    double yTarget; // ordonnee aleatoire
    double thetaTarget; // angle d'orientation de la cible
    double tanThetaTarget;
    double r; // distance entre le centre de l'arene et la cible

protected:

signals:

public slots:

private:


};

#endif // TARGET_H
