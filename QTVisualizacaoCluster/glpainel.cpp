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

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    if(arquivo != NULL)
        desenharOQueEstaNoArquivo();

    if(ptrEixoX != NULL)
        ptrEixoX->pintar();
    if(ptrEixoY != NULL)
        ptrEixoY->pintar();
    if(ptrEixoZ != NULL)
        ptrEixoZ->pintar();

    if (ptrMalhaXZ != NULL)
        ptrMalhaXZ->pintarXZ();
    if (ptrMalhaXY != NULL)
        ptrMalhaXY->pintarXY();
    if (ptrMalhaYZ != NULL)
        ptrMalhaYZ->pintarYZ();

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

    pespectiva.setPespectiva(60.0f, aspecto, 0.5f, 5000.0f);
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
            translacaoZ = translacaoZ - 2.6f;
            pespectiva.fazerTranslacao(translacaoX,translacaoY,translacaoZ);
        } else if(delta > 0){
            translacaoZ = translacaoZ + 2.6f;
            pespectiva.fazerTranslacao(translacaoX,translacaoY,translacaoZ);
        }
        this->z->setText(QString("z -> %1").arg(translacaoZ));
        atualizarCamera();
    }
}


void GLPainel::carregarArquivo(QString caminho){
    caminhoArquivo = caminho;

    // Carrega o arquivo
    arquivo = new Arquivo(caminho.toStdString());

    // Coloca a matriz do arquiv em outra matriz
    // Nota: Acho que da pra alterar a classe arquivo e mudar isso
    // aq retornando a matriz que esta no objeto arquivo
    int t = arquivo->getTamanho();
    int i, j;

    matrizPontos = new float*[t];       //Aloca matriz
    for(i=0; i < t; i++)
        matrizPontos[i] = new float[t];

    for (i=0; i < t; i++){
        for (j=0; j < 9; j++)
            matrizPontos[i][j] = arquivo->getMatriz(i,j);
    }
}


void GLPainel::desenharOQueEstaNoArquivo(){
    esferas = new Esfera;
    cilindros = new Cilindro;

    for (int i = 0; i < arquivo->getTamanho(); i++){
        esferas->setCoordenadas(matrizPontos[i][3], matrizPontos[i][4], matrizPontos[i][5]);
        esferas->setCor(matrizPontos[i][6], matrizPontos[i][7], matrizPontos[i][8]);
        esferas->pintar();
        esferas->setCoordenadas(matrizPontos[i][0], matrizPontos[i][1], matrizPontos[i][2]);
        esferas->setCor(matrizPontos[i][6], matrizPontos[i][7], matrizPontos[i][8]);
        esferas->pintar();
        cilindros->setCoordenadas(matrizPontos[i][0],matrizPontos[i][1],matrizPontos[i][2],matrizPontos[i][3],matrizPontos[i][4],matrizPontos[i][5]);
        cilindros->setCor(matrizPontos[i][6],matrizPontos[i][7],matrizPontos[i][8]);
        cilindros->pintar();
    }
}


// Fazer o destrutor
