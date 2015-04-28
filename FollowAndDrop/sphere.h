#ifndef SPHERE_H
#define SPHERE_H
#include <GL/glu.h>
#include <QWidget>
#include <QGLWidget>

class Sphere : public QGLWidget
{
public:
    explicit Sphere(QWidget *parent = 0);
    GLuint loadtgadisplayCDV ( const char* filename );

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);


private:
    void draw();
    GLuint GLdisplayList[1];

    GLuint GLtexture[1];
    int xRot;
    int yRot;
    int zRot;



public slots:
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setXRotation(int angle);


signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);



};

#endif // SPHERE_H
