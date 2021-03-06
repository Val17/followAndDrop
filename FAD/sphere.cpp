///fichier sphere.cpp
/// Createur: Valentin DAVY
/// Binome: DAVY/DENIZET

#include "sphere.h"

#define PI 3.14159265

Sphere::Sphere()
{
    r_ = 0;
    thetaSphere_ = 0;
    setZ(2);
    radius_=2;
}

void Sphere::drawSphere()
{
    int stacks = 50;
    int slices = 50;


    GLUquadric* param;
    param = gluNewQuadric();
    glBindTexture(GL_TEXTURE_2D, loadtgadisplayCDV("../FAD/Images/blue.tga"));
    gluQuadricTexture(param, GL_TRUE);
    gluSphere(param, radius_, slices, stacks);

    r_ = sqrt (xSphere_*xSphere_+ySphere_*ySphere_);

    if (xSphere_>0 && ySphere_>0) // 1er quart
    {
        tanThetaSphere_ = ySphere_/(double)xSphere_;
        thetaSphere_ = atan(tanThetaSphere_); // angle en radian
        thetaSphere_ = thetaSphere_ * 180 / PI;
    }

    else if (xSphere_<0 && ySphere_>0) // 2eme quart

    {
        tanThetaSphere_ = -ySphere_/(double)xSphere_;
        thetaSphere_ = atan(tanThetaSphere_); // angle en radian
        thetaSphere_ = 90 + thetaSphere_ * 180 / PI;
    }

    else if (xSphere_<0 && ySphere_<0) // 3eme quart

    {
        tanThetaSphere_ = xSphere_/(double)ySphere_;
        thetaSphere_ = atan(tanThetaSphere_); // angle en radian
        thetaSphere_ = -90 - thetaSphere_ * 180 / PI;
    }

    else if (xSphere_>0 && ySphere_<0) // 4eme quart

    {
        tanThetaSphere_ = -ySphere_/(double)xSphere_;
        thetaSphere_ = atan(tanThetaSphere_); // angle en radian
        thetaSphere_ = -thetaSphere_ * 180 / PI;
    }


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

/**
 * @brief Sphere::isMovable
 * @param x abscisse limite
 * @param y ordonnee limite
 * @param s seuil a ne pas depasser
 */
bool Sphere::isMovable(int x, int y, int s)
{
    bool b = true;

    if (sqrt((xSphere_+x)*(xSphere_+x)+(ySphere_+y)*(ySphere_+y))>=s)
    {
        b = false;
        return b;
    }

    else
    {
        return b;
    }
}


