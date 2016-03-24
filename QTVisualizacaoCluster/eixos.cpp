#include "eixos.h"

Eixos::Eixos(){
    set_cor(0.0f,0.0f,0.0f);
}

Eixos::Eixos(float x0, float y0, float z0,
             float x1, float y1, float z1){

    set_coordenadas(x0, y0, z0, x1, y1, z1);
    set_cor(0.0f,0.0f,0.0f);
}

void Eixos::set_coordenadas(float x0, float y0, float z0,
                       float x1, float y1, float z1){

    ponto_incial[0] = x0;
    ponto_incial[1] = y0;
    ponto_incial[2] = z0;

    ponto_final[0] = x1;
    ponto_final[1] = y1;
    ponto_final[2] = z1;
}

void Eixos::set_cor(float r, float g, float b){
    cor[0] = r;
    cor[1] = g;
    cor[2] = b;
}

void Eixos::pintar(){
    glBegin(GL_LINES);
        glColor3f(cor[0], cor[1], cor[2]);
        glVertex3f(ponto_incial[0], ponto_incial[1], ponto_incial[2]);
        glVertex3f(ponto_final[0], ponto_final[1], ponto_final[2]);
    glEnd();
}
