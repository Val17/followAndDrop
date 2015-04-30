#ifndef ARENA_H
#define ARENA_H

#include <QWidget>
#include <QGLWidget>
#include <GL/glu.h>
#include "math.h"
#include <stdio.h>
#include<iostream>
#include <QDebug>
#include <QMouseEvent>


class Arena : public QGLWidget
{
    Q_OBJECT

public:

    explicit Arena(QWidget *parent = 0);
    GLuint loadtgadisplayCDV ( const char* filename );
    ~Arena();
    void drawArena();
    GLuint GLtextureArena[1];

public slots:


protected:

signals:


private:


    int xRot;
    int yRot;
    int zRot;
    QPoint lastPos;
};

#endif // ARENA_H
