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

protected:

signals:

public slots:

private:

    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;
};

#endif // TARGET_H
