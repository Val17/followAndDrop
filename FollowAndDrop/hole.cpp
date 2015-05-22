#include "hole.h"
#include <GL/glu.h>
#include "math.h"

#define PI 3.14159265

Hole::Hole()
{
    xHole = -4;
    yHole = -7;
}


void Hole::drawHole()
{
    int nb_faces = 100;
    int rayon = 4;

    //GLtexture[0]= loadtgadisplayCDV("../FollowAndDrop/Images/hole.tga");

    glBegin(GL_POLYGON);

        for(int i=0; i<nb_faces; i++)
        {
            double angle = 2*M_PI*i/nb_faces;
            double xcos = cos(angle);
            double ycos = sin(angle);

            glTexCoord2f(xcos *0.5 + 0.5, ycos * 0.5 + 0.5);

            glVertex2f(xcos*rayon, ycos*rayon );
        }


    glEnd();
}
