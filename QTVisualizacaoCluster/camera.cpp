#include "camera.h"

Camera::Camera(){

}


void Camera::setPespectiva(float angulo, float aspecto, float frente, float fundo){
    this->angulo = angulo;
    this->aspecto = aspecto;
    this->plano_frente = frente;
    this->plano_fundo = fundo;
}

void Camera::setCamera(float posicao_cameraX, float posicao_cameraY, float posicao_cameraZ,
                             float posicao_objetoX, float posicao_objetoY, float posicao_objetoZ,
                             float orientacao_cameraX, float orientacao_cameraY, float orientacao_cameraZ){

    posicao_camera[0] = posicao_cameraX;
    posicao_camera[1] = posicao_cameraY;
    posicao_camera[2] = posicao_cameraZ;

    direcao_visao[0] = posicao_objetoX;
    direcao_visao[1] = posicao_objetoY;
    direcao_visao[2] = posicao_objetoZ;

    orientacao_camera[0] = orientacao_cameraX;
    orientacao_camera[1] = orientacao_cameraY;
    orientacao_camera[2] = orientacao_cameraZ;
}

void Camera::fazerTranslacao(float x, float y, float z){
    translacao[0] = x;
    translacao[1] = y;
    translacao[2] = z;
}

void Camera::fazerRotacao(float anguloX, float anguloY, float anguloZ){
    rotacao_angulo[0] = anguloX;
    rotacao_angulo[1] = anguloY;
    rotacao_angulo[2] = anguloZ;
}

void Camera::rodarCamera(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(angulo, aspecto, plano_frente, plano_fundo);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

     gluLookAt(posicao_camera[0], posicao_camera[1], posicao_camera[2],
               direcao_visao[0], direcao_visao[1], direcao_visao[2],
               orientacao_camera[0], orientacao_camera[1], orientacao_camera[2]);

    glTranslatef(translacao[0], translacao[1], translacao[2]);

    glRotatef(rotacao_angulo[0], 1,0,0);
    glRotatef(rotacao_angulo[1], 0,1,0);
    glRotatef(rotacao_angulo[2], 0,0,1);
}


// Fazer um destrutor
