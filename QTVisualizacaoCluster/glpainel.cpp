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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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
