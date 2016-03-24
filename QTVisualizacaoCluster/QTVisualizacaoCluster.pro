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
    desenho.cpp \
    malha.cpp \
    visaodepespectiva.cpp \
    esfera.cpp \
    eixos.cpp \
    cilindro.cpp \
    arquivo.cpp \
    forma.cpp

HEADERS  += mainwindow.h \
    glpainel.h \
    desenho.h \
    malha.h \
    visaodepespectiva.h \
    esfera.h \
    eixos.h \
    cilindro.h \
    arquivo.h \
    forma.h

FORMS    += mainwindow.ui
