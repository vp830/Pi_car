#-------------------------------------------------
#
# Project created by QtCreator 2016-09-23T05:39:34
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia
QT       += multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QThello
TEMPLATE = app
INCLUDEPATH += /usr/local/include \
                /usr/include/opencv \
                /usr/include/opencv2  \


LIBS += /usr/lib/arm-linux-gnueabihf/libopencv_highgui.so \
        /usr/lib/arm-linux-gnueabihf/libopencv_core.so    \
        -lwiringPi

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

