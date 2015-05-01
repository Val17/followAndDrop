#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGLWidget>
#include <arena.h>
#include <sphere.h>
#include <target.h>
#include <arm.h>
#include <brasarticule.h>



class Game : public QGLWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = 0);
    int xRot;
    int yRot;
    int zRot;
    ~Game();
    void dropSphere();
protected:

    void initializeGL();
    void paintGL();
    void draw();
    void resizeGL(int width, int height);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);


public slots:
    // slots for xyz-rotation slider
    void setXRotation(int angle);
    void setYRotation(int angle);
    void setZRotation(int angle);
signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);


private:

    GLuint theArena;
    GLuint theSphere;
    GLuint theTarget;
    GLuint theArm;
    GLuint theArticulateArm;
    Arena myArena;
    Sphere mySphere;
    Target myTarget;
    Arm myArm;
    ArticulateArm myArticulateArm;

    bool boolDrop;



    QPoint lastPos;
    int chrono;

    int xRandom;
    int yRandom;
    int zRandom;


    GLuint loadtgadisplayCDV(const char *filename);
};

#endif // GAME_H
