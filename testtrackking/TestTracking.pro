#-------------------------------------------------
#
# Project created by QtCreator 2012-10-24T15:02:48
#
#-------------------------------------------------

QT       += core gui widgets

TARGET = TestTracking
TEMPLATE = app


SOURCES += main.cpp\
        webcamwindow.cpp

HEADERS  += webcamwindow.h

INCLUDEPATH +=$$(OPENCV_DIR)\include

LIBS += -L$$(OPENCV_DIR)\lib \
    -lopencv_core \
    -lopencv_highgui \
    -lopencv_imgproc \
    -lopencv_video \
    -lopencv_features2d \
    -lopencv_calib3d \
    -lopencv_objdetect

