#include "sphere.h"
#include "math.h"
#include<stdio.h>
#include<GL/gl.h>
#include <GL/glu.h>

/**
 * Cette classe gere l'ensemble des attributs de la sphere.
 * @brief Sphere::Sphere
 */

GLuint loadtga ( const char* filename );
GLfloat GLfloatData[4];
GLdouble GLdoubleData[4];
GLuint GLdisplayList[1];

Sphere::Sphere(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{
    GLtexture[0];
}



/**
 * @brief Sphere::initializeSphere
 * Cette methode permet d'initialiser la sphere
 */
void Sphere::initializeGL()
{
    glClearColor(0,0,0,0);

    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);
    glShadeModel(GL_SMOOTH);
    glEnable( GL_TEXTURE_2D );

    GLtexture[0]= loadtgadisplayCDV("../FollowAndDrop/texturebois2.tga");

}

/**
 * @brief Sphere::paintSphere
 * Cette methode fixe les differents parametres pour l'affichage de la sphere.
 * Cette methode est appelee a chaque fois qu'il y a reaffichage d'une sphere.
 */

void Sphere::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // netoyage de tous les buffers
    glLoadIdentity(); // comme matrice de transf = matrice identite

    draw(); // contient le code brut corresp  la visualisation; on va principalement agir dans cette fonction
}

/**
 * @brief Sphere::drawSphere
 * Cette methode permet de dessiner la sphere
 */
void Sphere::draw()
{

    int nb_faces = 100;
    int rayon = 1;

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

/**
  propriete d'affichage; a chaque fois que l'on redimensionne
 * @brief Sphere::resizeGL
 * @param width
 * @param height
 */
void Sphere::resizeGL(int width, int height)
{
    //int side = qMin(width, height); // bordure
    int side = width;

    glViewport((width - side)/2, (height - side)/2, side, side);

    glMatrixMode(GL_PROJECTION); // on desire etablir la matrice permettant de passer des coord globales à celles de l'ecran; declare une seule fois!
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    gluPerspective(90,((float)width/(float)height),0.01, 30);



}

GLuint Sphere::loadtgadisplayCDV ( const char* filename )
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




