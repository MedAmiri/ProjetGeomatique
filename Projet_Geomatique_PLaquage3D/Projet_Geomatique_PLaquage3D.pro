#-------------------------------------------------
#
# Project created by QtCreator 2015-10-18T09:10:51
#
#-------------------------------------------------

QT       += core gui opengl xml
LIBS += -lQGLViewer -lassimp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet_Geomatique_PLaquage3D
TEMPLATE = app


SOURCES += main.cpp\
        interface.cpp \
    objet.cpp \
    viewer.cpp \
    mnt.cpp \
    global.cpp \
    plaquage.cpp \
    plan.cpp

HEADERS  += interface.h \
    objet.h \
    viewer.h \
    mnt.h \
    global.h \
    plaquage.h \
    plan.h

FORMS    += interface.ui
