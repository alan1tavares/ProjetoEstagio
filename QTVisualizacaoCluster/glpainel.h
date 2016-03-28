#ifndef GLPAINEL_H
#define GLPAINEL_H

#include <QGLWidget>
#include <QMouseEvent>
#include <GL/freeglut.h>
#include "eixos.h"
#include "camera.h"
#include "esfera.h"

#include <QtWidgets/QLabel>
#include <stdio.h>
#include <stdlib.h>

class GLPainel : public QGLWidget
{
    Q_OBJECT
private:
    Eixos *ptrEixoX;
    Eixos *ptrEixoY;
    Eixos *ptrEixoZ;

    Camera pespectiva;

    Esfera testeEsfera;

    //Variáveis para o mouse;
    float rotacaoX  = 0;
    float rotacaoY = 0;

    float translacaoX = 0;
    float translacaoY = 0;
    float translacaoZ = 0;

    QPoint inicioTranslacao;
    QPoint inicioRotacao;
    //---------------------//

public:
    explicit GLPainel(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void desenharEixos(bool, bool, bool);

    void mousePressEvent(QMouseEvent *);

    void mouseMoveEvent(QMouseEvent *);

    void wheelEvent(QWheelEvent *);

    QLabel *x;
    QLabel *y;
    QLabel *z;

private:
    void atualizarCamera();
    void visaoPespectiva();
};

#endif // GLPAINEL_H
