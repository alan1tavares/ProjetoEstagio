#include "mainwindow.h"
#include <QApplication>

#include<GL/freeglut.h>

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
