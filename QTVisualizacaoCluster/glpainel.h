#ifndef GLPAINEL_H
#define GLPAINEL_H

#include <QGLWidget>
#include <QMouseEvent>
#include <GL/freeglut.h>
#include "eixos.h"
#include "camera.h"
#include "esfera.h"
#include "malha.h"
#include "cilindro.h"

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
    Malha *ptrMalhaXZ;
    Malha *ptrMalhaXY;
    Malha *ptrMalhaYZ;

    Camera pespectiva;

    Esfera *testeEsfera;

    Cilindro *testeCilindro;

    //Variáveis para o mouse;
    float rotacaoX  = 0;
    float rotacaoY = 0;

    float translacaoX = 0;
    float translacaoY = 0;
    float translacaoZ = 0;

    QPoint inicioTranslacao;
    QPoint inicioRotacao;
    //---------------------//

    //Variáveis para iluminação
    const GLfloat light_ambient[4]  = { 0.0f, 0.0f, 0.0f, 1.0f };
    const GLfloat light_diffuse[4]  = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_specular[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat light_position[4] = { 2.0f, 5.0f, 5.0f, 0.0f };

    const GLfloat mat_ambient[4]    = { 0.7f, 0.7f, 0.7f, 1.0f };
    const GLfloat mat_diffuse[4]    = { 0.8f, 0.8f, 0.8f, 1.0f };
    const GLfloat mat_specular[4]   = { 1.0f, 1.0f, 1.0f, 1.0f };
    const GLfloat high_shininess[1] = { 100.0f };
    //---------------------//

public:
    explicit GLPainel(QWidget *parent = 0);

    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void desenharCilindro();
    //void desenharCilindro(float, float, float, float, float, float, float, float, float);
    void desenharEsfera();
    //void desenharEsfera(float, float, float, float, float, float);
    void desenharEixos(bool, bool, bool);
    void desenharMalha(bool, bool, bool);

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
