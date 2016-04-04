#include "eixos.h"

Eixos::Eixos(){
    setCor(0.0f,0.0f,0.0f);
}

Eixos::Eixos(float x0, float y0, float z0,
             float x1, float y1, float z1){

    setCoordenadas(x0, y0, z0, x1, y1, z1);
    setCor(0.0f,0.0f,0.0f);
}

void Eixos::setCoordenadas(float x0, float y0, float z0,
                       float x1, float y1, float z1){

    ponto_inicial[0] = x0;
    ponto_inicial[1] = y0;
    ponto_inicial[2] = z0;

    ponto_final[0] = x1;
    ponto_final[1] = y1;
    ponto_final[2] = z1;
}

void Eixos::setCor(float r, float g, float b){
    cor[0] = r;
    cor[1] = g;
    cor[2] = b;
}

void Eixos::pintar(){
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
        glColor3f(cor[0], cor[1], cor[2]);
        glVertex3f(ponto_inicial[0], ponto_inicial[1], ponto_inicial[2]);
        glVertex3f(ponto_final[0], ponto_final[1], ponto_final[2]);
    glEnd();
    glEnable(GL_LIGHTING);
}
