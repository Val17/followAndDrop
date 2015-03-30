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
    -lopencv_core2411 \
    -lopencv_highgui2411 \
    -lopencv_imgproc2411 \
    -lopencv_video2411 \
    -lopencv_features2d2411 \
    -lopencv_calib3d2411 \
    -lopencv_objdetect2411

