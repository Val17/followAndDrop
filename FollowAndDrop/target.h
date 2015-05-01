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
    int xTar; // abscisse aleatoire
    int yTar; // ordonnee aleatoire

protected:

signals:

public slots:

private:


};

#endif // TARGET_H
