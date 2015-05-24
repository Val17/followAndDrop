#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGLWidget>
#include <QTimer>
#include <QtWidgets>
#include <QtOpenGL>
#include <GL/glu.h>
#include <GL/gl.h>
#include "math.h"
#include <arena.h>
#include <sphere.h>
#include <target.h>
#include <hole.h>
#include <brasarticule.h>
#include<iostream>

class Game : public QGLWidget
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = 0);
    int xRot;
    int yRot;
    int zRot;
    int xTrans;
    int yTrans;
    int zTrans;
    ~Game();

    QPoint lastPos; // Point correspondant au point ou l'utilisateur a clique
    Arena myArena;

    /*
     * Booleens qui permettent de controler
     * la presence de l'element graphique
     * correspondant.
     * Exemple: boolArena a comme valeur true
     * si il y a l'Arene qui est a l'ecran.
     * */

    bool boolTarget;
    bool boolArena;
    bool boolArm;
    bool boolSphere;
    bool boolHole;
    bool boolDrop; // booleen pour savoir si le bras a la sphere

    Sphere mySphere;
    Target myTarget;
    ArticulateArm myArm;
    Hole myHole;
    int intGluPerspective;
    void removeSphere(int step); // attrape la sphere
    void moveY(int y);
    void moveZ(int z);
    void moveX(int x);
    void appearSphere();
    QPoint getRandomCoordinates();

    bool detectVictory();
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
    void appearTarget();
    void catchSphere(); // methode permettant d'attraper la sphere
    void reinitializeArm(); // slot permettant de mettre le bras a sa position initiale
    void dropSphere(); // slot permettant d'amener la sphere dans le trou
    void appearHole();

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);


private:

    int chrono;
    int xRandom;
    int yRandom;
    int zRandom;
    QTimer *timerCatch;
    QTimer *timerMoveArm; // timer utilise pour le deplacement du bras a son etat initial
    QTimer *timerDrop; // timer utilise pour que le bras lache la sphere
    GLuint loadtgadisplayCDV(const char *filename);


    int getRandomRadius();
};

#endif // GAME_H
