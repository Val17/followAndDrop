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
    ~Arena(); // destructeur de la classe
    void drawArena(); // dessiner l'arene
    int getSize(){return size_;} // retourne la taille de l'arene
    int getX() {return xLimit_;} // retourne l'abscisse maximale
    int getY() { return yLimit_;} // retourne l'ordonnee maximale

public slots:

protected:

signals:

private:

    int xLimit_; // abscisse limite
    int yLimit_; // ordonnee limite
    int size_; // taille de l'arene
    char* texture_; // texture utilisee pour l'arene
    GLuint glTexture_[1]; // texture de l'arene
    GLuint loadTexture ( const char* filename ); // methode permettant de charge la texture

};

#endif // ARENA_H
