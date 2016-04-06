#-------------------------------------------------
#
# Project created by QtCreator 2016-03-15T23:48:32
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTVisualizacaoCluster
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glpainel.cpp \
    malha.cpp \
    esfera.cpp \
    eixos.cpp \
    cilindro.cpp \
    arquivo.cpp \
    camera.cpp

HEADERS  += mainwindow.h \
    glpainel.h \
    malha.h \
    esfera.h \
    eixos.h \
    cilindro.h \
    arquivo.h \
    camera.h

FORMS    += mainwindow.ui

LIBS += libfreeglut -lopengl32 -lglu32 -luser32
