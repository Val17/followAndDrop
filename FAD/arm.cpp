///fichier arm.cpp
/// Createur: Arnaud DENIZET
/// Binome: DAVY/DENIZET

#include "arm.h"


using namespace std;

Arm::Arm(QGLWidget *parent) : QGLWidget(parent)
{
    alpha_=0; // angle alpha; rotation de la base
    beta_=0; // angle beta; rotation de l'epaule
    gamma_=0; // angle gamma; rotation du coude
    sA_=6; // taille du bras
    sFa_=6; // taille de l'avant bras
    boolSphereArm_=false; // au depart, la sphere n'est pas dans la main du robot
}

Arm::~Arm()
{

}

void Arm::drawArm()
{
    // Socle

    glPushMatrix(); // il y a un scalef dans drawBase
        drawBase();
    glPopMatrix();

    // Epaule

    glPushMatrix();
        glTranslatef(0,0,1); // altitude = 1

            glRotatef(alpha_, 0, 0, 1); // premier angle
            glRotatef(beta_, 0, 1, 0); // deuxieme angle

            glPushMatrix();
                drawSphere(1 ,50,50);
            glPopMatrix();

            // Bras

            glPushMatrix();
                glTranslatef(0,0,1); // altitude = 2
                drawCylinder(1,sA_,20,20);
            glPopMatrix();

            glPushMatrix();
                glTranslatef(0,0,2+sA_); // altitude = 2 + sA

                glPushMatrix();
                    // Coude
                    glRotatef(gamma_, 0, 1, 0);

                    glPushMatrix();
                        drawSphere(1,50,50);
                    glPopMatrix();

                    // Avant-Bras

                    glPushMatrix();
                        glTranslatef(0,0,1);
                        drawCylinder(1, sFa_, 20,20);
                    glPopMatrix();

                    //Main

                    glPushMatrix();
                        glTranslatef(0,0,5);

                        glPushMatrix();
                            drawSphere(1,50,50);
                         glPopMatrix();

                    // Pince 1

                    glPushMatrix();
                        glTranslatef(0,2,2);
                        glRotatef(-30, 1, 0, 1);
                        glRotatef(delta_, 1, 0, -1); // quatrieme angle
                        glScalef(.2,.2,3);
                        drawCylinder(1,1,30,30);
                     glPopMatrix();

                     // le bras a attrape la sphere
                      if (boolSphereArm_ == true)
                      {
                          glPushMatrix();
                             glTranslatef(0,0,3.5);
                             drawSphereGame(2,50,50);
                          glPopMatrix();
                      }

                     // Pince 2
                     glPushMatrix();
                        glTranslatef(0,-2,2);
                         glRotatef(30, 1, 0, 1);
                         glRotatef(delta_, -1, 0, 1);
                         glScalef(.2,.2,3);
                         drawCylinder(1,1,30,30);
                      glPopMatrix();

                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();

      // l'altitude est de sA + sFa + 6

}

void Arm::drawSphere(double r, int lats, int stacks)
{
    GLUquadric* param;
    param = gluNewQuadric();
    glBindTexture(GL_TEXTURE_2D, loadTexture("../FAD/Images/tse.tga"));
    gluQuadricTexture(param, GL_TRUE);
    gluSphere(param, r, lats, stacks);

}

void Arm::drawSphereGame(double r, int lats, int stacks)
{
    GLUquadric* param;
    param = gluNewQuadric();
    glBindTexture(GL_TEXTURE_2D, loadTexture("../FAD/Images/blue.tga"));
    gluQuadricTexture(param, GL_TRUE);
    gluSphere(param, r, lats, stacks);
}

void Arm::drawCylinder(double radius,int height, int slices, int stacks)
{
    GLUquadric* quadric;
    quadric = gluNewQuadric();
    glBindTexture(GL_TEXTURE_2D, loadTexture("../FAD/Images/tse.tga"));
    gluQuadricTexture(quadric, GL_TRUE);
    gluCylinder(quadric, radius, radius, height, slices, stacks);
}

void Arm::drawBase()
{
    GLUquadric* quadric;
    quadric = gluNewQuadric();
    glBindTexture(GL_TEXTURE_2D, loadTexture("../FAD/Images/tse.tga"));
    gluQuadricTexture(quadric, GL_TRUE);

    glScalef(2,2,.1);
    gluSphere(quadric, 1, 50, 50);

}


GLuint Arm::loadTexture ( const char* filename )
{
    FILE* fp;
    char magic[12];
    unsigned char header[6];
    int imageSize;
    GLenum type;
    char temp;
    int i;
    int bpp,width,height;

    GLuint textureId;

    int globalWidth = 1;
    int globalHeight = 1;
    char* imageData;
    char* imageTmp;
    if(!(fp = fopen(filename, "rb"))) return 0;
    if(!fread(&magic, 12, 1, fp)) return 0;
    if(!fread(&header, 6, 1, fp)) return 0;
    bpp = header[4];
    width  = header[1] * 256 + header[0];
    height = header[3] * 256 + header[2];
    if(width <= 0 || height <= 0) return 0;
    if(bpp != 24 && bpp != 32) return 0;
    imageSize = width * height * (bpp / 8);
    imageData = (char *)malloc(sizeof(char) * imageSize);
    if(imageData == NULL) return 0;
    if(!fread(imageData, imageSize, 1, fp)) { free(imageData); return 0; }
    for(i = 0; i < imageSize; i += bpp / 8) {
    temp = imageData[i];
    imageData[i] = imageData[i + 2];
    imageData[i + 2] = temp; }
    if(bpp == 32) for(i=0;i<imageSize;i+=4) imageData[i+3]=255-imageData[i+3];
    fclose(fp);
    while (width>globalWidth) globalWidth*=2;
    while (height>globalHeight) globalHeight*=2;
    glEnable( GL_TEXTURE_2D );
    glGenTextures(1, &textureId);
    glBindTexture(GL_TEXTURE_2D, textureId);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glPixelStorei(GL_UNPACK_ROW_LENGTH,globalWidth);
    glPixelStorei(GL_UNPACK_ALIGNMENT,1);
    if(bpp == 24) type=GL_RGB; else type=GL_RGBA;
    imageTmp = (char *)malloc(sizeof(char)*globalWidth*globalHeight*4);
    if (imageTmp==NULL) return 0;
    glTexImage2D(GL_TEXTURE_2D,0,type,globalWidth,globalHeight,0,
    type,GL_UNSIGNED_BYTE,imageTmp);
    free (imageTmp );
    glPixelStorei(GL_UNPACK_ROW_LENGTH,width);
    glTexSubImage2D(GL_TEXTURE_2D,0, 0,0, width, height,
    type ,GL_UNSIGNED_BYTE, imageData );
free(imageData);

return textureId;
}



