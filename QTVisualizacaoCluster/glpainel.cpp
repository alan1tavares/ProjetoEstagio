#include "glpainel.h"

GLPainel::GLPainel(QWidget *parent) :
    QGLWidget(parent)
{

    ptrEixoX = NULL;
    ptrEixoY = NULL;
    ptrEixoZ = NULL;
    ptrMalhaXY = NULL;
    ptrMalhaXZ = NULL;
    ptrMalhaYZ = NULL;

}

void GLPainel::initializeGL(){
    glClearColor(1, 1, 1, 1);
}

void GLPainel::paintGL(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (ptrMalhaXZ != NULL)
        ptrMalhaXZ->pintarXZ();
    if (ptrMalhaXY != NULL)
        ptrMalhaXY->pintarXY();
    if (ptrMalhaYZ != NULL)
        ptrMalhaYZ->pintarYZ();

    if(ptrEixoX != NULL)
        ptrEixoX->pintar();
    if(ptrEixoY != NULL)
        ptrEixoY->pintar();
    if(ptrEixoZ != NULL)
        ptrEixoZ->pintar();

    testeEsfera.pintar();

    glFlush();

}

void GLPainel::resizeGL(int w, int h){
    glViewport(0, 0, w, h);

    visaoPespectiva();
}

void GLPainel::atualizarCamera(){
    visaoPespectiva();
    updateGL();
}

void GLPainel::visaoPespectiva(){
    float aspecto = (GLfloat)width()/(GLfloat)height();

    pespectiva.setPespectiva(60.0f, aspecto, 0.5f, 500.0f);
    pespectiva.setCamera(0,0,10 , 0,0,0 , 0,1,0);
    pespectiva.rodarCamera();

}

void GLPainel::desenharEixos(bool x, bool y, bool z){
    if(x && ptrEixoX == NULL){

        ptrEixoX = new Eixos;
        ptrEixoX->setCoordenadas(0.0f,0.0f,0.0f , 1000.0f,0.0f,0.0f);
        ptrEixoX->setCor(1.0f,0.0f,0.0f);

    }else if(!x && ptrEixoX != NULL){
        delete ptrEixoX;
        ptrEixoX = NULL;
    }

    if(y && ptrEixoY == NULL){

        ptrEixoY = new Eixos;
        ptrEixoY->setCoordenadas(0.0f,0.0f,0.0f , 0.0f,1000.0f,0.0f);
        ptrEixoY->setCor(0.0f,1.0f,0.0f);

    } else if(!y && ptrEixoY != NULL){
        delete ptrEixoY;
        ptrEixoY = NULL;
    }

    if(z && ptrEixoZ == NULL){

        ptrEixoZ = new Eixos;
        ptrEixoZ->setCoordenadas(0.0f,0.0f,0.0f , 0.0f,0.0f,1000.0f);
        ptrEixoZ->setCor(0.0f,0.0f,1.0f);

    } else if(!z && ptrEixoZ != NULL){
        delete ptrEixoZ;
        ptrEixoZ = NULL;
    }

    updateGL();
}

void GLPainel::desenharMalha(bool xy, bool xz, bool yz){
    if (xz && ptrMalhaXZ == NULL){
        ptrMalhaXZ = new Malha;
        ptrMalhaXZ->setCoordenadas(-1000.0f, 0.0f, -1000.0f , 1000.0f, 0.0f, 1000.0f);
        ptrMalhaXZ->setCor(0.8f, 0.8f, 0.8f);
    } else if (!xz && ptrMalhaXZ != NULL){
        delete ptrMalhaXZ;
        ptrMalhaXZ = NULL;
    }

    if (xy && ptrMalhaXY == NULL){
        ptrMalhaXY = new Malha;
        ptrMalhaXY->setCoordenadas(-1000.0f, -1000.0f, 0.0f , 1000.0f, 1000.0f, 0.0f);
        ptrMalhaXY->setCor(0.8f, 0.8f, 0.8f);
    } else if (!xy && ptrMalhaXY != NULL){
        delete ptrMalhaXY;
        ptrMalhaXY = NULL;
    }

    if (yz && ptrMalhaYZ == NULL){
        ptrMalhaYZ = new Malha;
        ptrMalhaYZ->setCoordenadas(0.0f, -1000.0f, -1000.0f , 0.0f, 1000.0f, 1000.0f);
        ptrMalhaYZ->setCor(0.8f, 0.8f, 0.8f);
    } else if (!yz && ptrMalhaYZ != NULL){
        delete ptrMalhaYZ;
        ptrMalhaYZ = NULL;
    }

    updateGL();
}

void GLPainel::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton || event->button() == Qt::RightButton){
        inicioTranslacao = event->pos();
        inicioRotacao = event->pos();
        this->x->setText(QString("x -> %1").arg(rotacaoX));
        this->y->setText(QString("y -> %1").arg(rotacaoY));
    }
}

void GLPainel::mouseMoveEvent(QMouseEvent *event){
    float distX, distY;

    if(event->buttons() == Qt::LeftButton){
        distX = (event->pos().x() - inicioTranslacao.x())*0.1f;
        distY = -(event->pos().y() - inicioTranslacao.y())*0.1f;

        translacaoX = (translacaoX + distX);
        translacaoY = (translacaoY + distY);

        this->x->setText(QString("x -> %1").arg(translacaoX));
        this->y->setText(QString("y -> %1").arg(translacaoY));

        pespectiva.fazerTranslacao(translacaoX, translacaoY, translacaoZ);
        atualizarCamera();

    } else if(event->buttons() == Qt::RightButton){

        distX = (event->pos().x() - inicioTranslacao.x())*0.1f;
        distY = (event->pos().y() - inicioTranslacao.y())*0.1f;

        rotacaoX = (rotacaoX + distX);
        rotacaoY = (rotacaoY + distY);

        pespectiva.fazerRotacao(rotacaoY, rotacaoX, 0);
        atualizarCamera();
    }

    inicioTranslacao = event->pos();
}

void GLPainel::wheelEvent(QWheelEvent *event){
    int delta = event->delta();
    if(event->orientation() == Qt::Vertical){
        if(delta < 0){
            translacaoZ = translacaoZ - 0.5f;
            pespectiva.fazerTranslacao(translacaoX,translacaoY,translacaoZ);
        } else if(delta > 0){
            translacaoZ = translacaoZ + 0.5f;
            pespectiva.fazerTranslacao(translacaoX,translacaoY,translacaoZ);
        }
        this->z->setText(QString("z -> %1").arg(translacaoZ));
        atualizarCamera();
    }
}
