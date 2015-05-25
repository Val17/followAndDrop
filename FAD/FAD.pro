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
    game.h \
    sphere.h \
    gamewidget.h \
    webcamwindow.h \
    hole.h \
    arm.h
FORMS += mainwindow.ui \
    gamewidget.ui
SOURCES += main.cpp mainwindow.cpp \
    arena.cpp \
    target.cpp \
    game.cpp \
    sphere.cpp \
    gamewidget.cpp \
    webcamwindow.cpp \
    hole.cpp \
    arm.cpp
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
