#include "brasarticule.h"
#include <iostream>

using namespace std;

ArticulateArm::ArticulateArm(QGLWidget *parent) : QGLWidget(parent)
{
    alpha=0;
    beta=0;
    gamma=0;
}

ArticulateArm::~ArticulateArm()
{

}

void ArticulateArm::drawArm()
{


    //base
    glPushMatrix();
        glTranslatef(0,0,1);
        glScalef(1,1,0.5);
        //glColor3f (1.0, 0, 0.0);
        drawSphere(1, 50,50);
    glPopMatrix();

    glPushMatrix();

        glTranslatef(0,0, 1.5);
        glPushMatrix();

        // epaule

            glRotatef(alpha, 1, 0, 0);

            glPushMatrix();
            glScalef(1,1,1);
            //glColor3f(0.0,1.0,0.0);
            drawSphere(1 ,50,50);
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0,0, 2.25);

            glScalef(1,1,1);
            //glColor3f(0.0,1.0,1.0);
            drawCylinder(1, 3, 20, 1);
            glPopMatrix();

            glPushMatrix();



                glTranslatef(0,0,7.5);
                glPushMatrix();
                //coude

                    glRotatef(beta, 0, 1, 0);


                    glPushMatrix();
                        glScalef(1,1,1);
                        //glColor3f(1.0, 0, 0);
                        drawSphere(1, 50, 50);
                    glPopMatrix();

                    //avant-bras
                    glPushMatrix();
                        glTranslatef(0,0,2.5);
                        //glColor3f(1,0,1);
                        drawCylinder(1,3,20,1);
                    glPopMatrix();

                    glPushMatrix();

                        glTranslatef(0,0,7);
                        // poignet

                        glRotatef(gamma, 0, 0, 1);

                        glPushMatrix();
                            glScalef(1,1,1);
                            drawSphere(1, 50, 50);
                        glPopMatrix();

                        // pince 1

                        glPushMatrix();
                            glTranslatef(0, 2, 1.5);
                            glRotatef(-40, 1, 0, 1);
                            //glColor3f(1.0,0,1.0);
                            glScalef(.5,.5,2);
                            drawCylinder(.5,1,20,1);
                         glPopMatrix();

                         // pince 2

                         glPushMatrix();
                             glTranslatef(0, -2, 1.5);
                             glRotatef(40, 1, 0, 1);
                             //glColor3f(1.0,0,1.0);
                             glScalef(.5,.5,2);
                             drawCylinder(.5,1,20,1);
                          glPopMatrix();

                     glPopMatrix();

                 glPopMatrix();

             glPopMatrix();

        glPopMatrix();

    glPopMatrix();



}

void ArticulateArm::drawSphere(double r, int lats, int stacks)
{
    GLUquadric* param;
    param = gluNewQuadric();
    glBindTexture(GL_TEXTURE_2D, loadtgadisplayCDV("../FollowAndDrop/Images/robot.tga"));
    gluQuadricTexture(param, GL_TRUE);
    gluSphere(param, r, lats, stacks);


}

void ArticulateArm::drawCylinder(double r,int height, int lats, int longs)
{

    GLUquadric* param;
    param = gluNewQuadric();
    glBindTexture(GL_TEXTURE_2D, loadtgadisplayCDV("../FollowAndDrop/Images/robot.tga"));
    gluQuadricTexture(param, GL_TRUE);
    gluCylinder(param, r, r, height, lats, longs);
}

GLuint ArticulateArm::loadtgadisplayCDV ( const char* filename )
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

void ArticulateArm::moveShoulder(int b)
{

    beta=b;
    //drawArm();
}

void ArticulateArm::moveBase(int a)
{
    alpha = a;
}

void ArticulateArm::moveHand(int g)
{
    gamma = g;
}
