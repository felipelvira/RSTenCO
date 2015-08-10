#-------------------------------------------------
#
# Project created by QtCreator 2015-08-06T18:06:35
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = RSTenCO
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    MatToQImage.cpp

HEADERS  += mainwindow.h\
    MatToQImage.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include/         \
            += /usr/local/include/opencv

LIBS += -L/usr/local/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
LIBS += -lopencv_ml
LIBS += -lopencv_video
LIBS += -lopencv_features2d
LIBS += -lopencv_calib3d
LIBS += -lopencv_objdetect
LIBS += -lopencv_contrib
LIBS += -lopencv_legacy
LIBS += -lopencv_flann
LIBS += -lopencv_nonfree
