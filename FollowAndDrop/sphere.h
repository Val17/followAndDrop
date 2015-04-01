#ifndef SPHERE_H
#define SPHERE_H
#include <GL/glut.h>

class Sphere
{
public:
    Sphere();

protected:
    void initializeSphere();
    void paintSphere();
    void resizeSphere(int width, int height);
    void displaySphereDisplayList( void );


private:
    void drawSphere();
    GLuint GLdisplayList[1];


};

#endif // SPHERE_H
