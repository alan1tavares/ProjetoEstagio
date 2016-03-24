#include "glpainel.h"

GLPainel::GLPainel(QWidget *parent) :
    QGLWidget(parent)
{

    ptrEixoX = NULL;
    ptrEixoY = NULL;
    ptrEixoZ = NULL;
}

void GLPainel::initializeGL(){
    glClearColor(1, 1, 1, 1);
}

void GLPainel::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(ptrEixoX != NULL)
        ptrEixoX->pintar();
    if(ptrEixoY != NULL)
        ptrEixoY->pintar();
    if(ptrEixoZ != NULL)
        ptrEixoZ->pintar();

    glFlush();
}

void GLPainel::resizeGL(int w, int h){

}

void GLPainel::desenharEixos(bool x, bool y, bool z){
    if(x && ptrEixoX == NULL){

        ptrEixoX = new Eixos;
        ptrEixoX->set_coordenadas(0.0f,0.0f,0.0f , 1000.0f,0.0f,0.0f);
        ptrEixoX->set_cor(1.0f,0.0f,0.0f);

    }else if(!x && ptrEixoX != NULL){
        delete ptrEixoX;
        ptrEixoX = NULL;
    }

    if(y && ptrEixoY == NULL){

        ptrEixoY = new Eixos;
        ptrEixoY->set_coordenadas(0.0f,0.0f,0.0f , 0.0f,1000.0f,0.0f);
        ptrEixoY->set_cor(0.0f,1.0f,0.0f);

    } else if(!y && ptrEixoY != NULL){
        delete ptrEixoY;
        ptrEixoY = NULL;
    }

    if(z && ptrEixoZ == NULL){

        ptrEixoZ = new Eixos;
        ptrEixoZ->set_coordenadas(0.0f,0.0f,0.0f , 0.0f,0.0f,1000.0f);
        ptrEixoZ->set_cor(0.0f,0.0f,1.0f);

    } else if(!z && ptrEixoZ != NULL){
        delete ptrEixoZ;
        ptrEixoZ = NULL;
    }

    update();
}
