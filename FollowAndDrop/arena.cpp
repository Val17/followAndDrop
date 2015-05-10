// Fichier de declaration de la classe Arena
// Davy/Denizet

#include "arena.h"


/**
 * Constructeur de la classe Arena
 * @brief Arena::Arena
 * @param parent
 */
Arena::Arena(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent)
{

    GLtextureArena[0];
    texture = "../FollowAndDrop/Images/ground1.tga";
    size = 20;

}

/**
 * Destructeur de la classe Arena
 * @brief Arena::~Arena
 * @class Arena
 */
Arena::~Arena()
{

}


/**
 * Methode permettant de dessiner l'arene.
 * @brief Arena::drawArena
 */

void Arena::drawArena()
{


    int nb_faces = 100;


    GLtextureArena[0]= loadtgadisplayCDV(texture);


    glBegin(GL_POLYGON);

        for(int i=0; i<nb_faces; i++)
        {
            double angle = 2*M_PI*i/nb_faces;
            double xcos = cos(angle);
            double ycos = sin(angle);

            glTexCoord2f(xcos *0.5 + 0.5, ycos * 0.5 + 0.5);

            glVertex2f(xcos*size, ycos*size );

        }

     glEnd();


}


/**
 * Methode permettant de charger la texture
 * @brief Arena::loadtgadisplayCDV
 * @param filename
 * @return
 */
GLuint Arena::loadtgadisplayCDV ( const char* filename )
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

