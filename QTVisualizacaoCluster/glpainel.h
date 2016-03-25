#ifndef GLPAINEL_H
#define GLPAINEL_H

#include <QGLWidget>
#include <GL/glut.h>
#include "eixos.h"
#include "visaodepespectiva.h"

class GLPainel : public QGLWidget
{
    Q_OBJECT
private:
    Eixos *ptrEixoX;
    Eixos *ptrEixoY;
    Eixos *ptrEixoZ;

    VisaoDePespectiva pespectiva;

public:
    explicit GLPainel(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void desenharEixos(bool, bool, bool);
};

#endif // GLPAINEL_H
