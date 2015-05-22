// Fichier de definition de la classe Arena
// Davy/Denizet

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

    explicit Arena(QWidget *parent = 0); // constructeur de la classe
    GLuint loadtgadisplayCDV ( const char* filename ); // charge la texture
    ~Arena(); // destructeur de la classe
    void drawArena(); // dessiner l'arene
    GLuint GLtextureArena[1]; // texture de l'arene
    char* texture; // texture utilisee pour l'arene
    int getSize(){qDebug()<<"lalal"<<size;return size;}

    int xLimit; // abscisse limite
    int yLimit; // ordonnee limite
    int size; // taille de l'arene



public slots:


protected:



signals:

private:

};

#endif // ARENA_H
