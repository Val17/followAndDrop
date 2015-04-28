#ifndef ARENA_H
#define ARENA_H

#include <QWidget>
#include <QGLWidget>


class Arena : public QGLWidget
{
    Q_OBJECT

public:

    explicit Arena(QWidget *parent = 0);
    GLuint loadtgadisplayCDV ( const char* filename );
    ~Arena();

public slots:
    void setYRotation(int angle);
    void setZRotation(int angle);
    void setXRotation(int angle);
protected:

    void initializeGL();
    void paintGL();
    void resizeGL(int width, int height);
    QSize sizeHint() const;

signals:
    // signaling rotation from mouse movement
    void xRotationChanged(int angle);
    void yRotationChanged(int angle);
    void zRotationChanged(int angle);

private:

    void draw();

    GLuint GLtexture[1];
    int xRot;
    int yRot;
    int zRot;
};

#endif // ARENA_H
