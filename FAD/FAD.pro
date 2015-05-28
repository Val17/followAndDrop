#-------------------------------------------------
#
# Project created by QtCreator 2015-05-25T10:36:35
#
#-------------------------------------------------

TEMPLATE = app
TARGET = FAD
INCLUDEPATH += .

# Input
HEADERS += mainwindow.h \
    arena.h \
    target.h \
    sphere.h \
    hole.h \
    arm.h \
    gamewindow.h \
    webcamwindow.h \
    game.h
FORMS += mainwindow.ui \
    gamewindow.ui
SOURCES += main.cpp mainwindow.cpp \
    arena.cpp \
    target.cpp \
    sphere.cpp \
    hole.cpp \
    arm.cpp \
    gamewindow.cpp \
    webcamwindow.cpp \
    game.cpp
QT += core gui opengl

LIBS += -L$$(OPENCV_DIR)\lib \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    #-lopencv_videoio \
    -lopencv_features2d \
    -lopencv_calib3d \
    -lopencv_objdetect \
    -lGLU #-lglut \

RESOURCES +=
