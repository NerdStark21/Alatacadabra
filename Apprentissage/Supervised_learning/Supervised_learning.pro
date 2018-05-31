#-------------------------------------------------
#
# Project created by QtCreator 2018-05-25T11:31:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Supervised_learning

CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    skin.cpp \
    bayesien.cpp \
    background.cpp \
    texture.cpp \
    direction.cpp \
    imageutile.cpp

HEADERS += \
        mainwindow.h \
    skin.h \
    bayesien.h \
    background.h \
    texture.h \
    direction.h \
    imageutile.h

FORMS += \
        mainwindow.ui


INCLUDEPATH +=$$(OPENCV_DIR)\..\..\include

LIBS +=-L$$(OPENCV_DIR)\lib \
    -lopencv_core2413 \
    -lopencv_highgui2413 \
    -lopencv_imgproc2413 \
    -lopencv_features2d2413 \
    -lopencv_calib3d2413