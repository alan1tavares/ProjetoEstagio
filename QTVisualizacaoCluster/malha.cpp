#include "malha.h"

Malha::Malha(){
    setCor(0.8f,0.8f,0.8f);
}

Malha::Malha(float x0, float y0, float z0,
         float x1, float y1, float z1){

    setCoordenadas(x0, y0, z0, x1, y1, z1);
    setCor(0.8f,0.8f,0.8f);
}

void Malha::setCoordenadas(float x0, float y0, float z0,
                   float x1, float y1, float z1){

    ponto_inicial[0] = x0;
    ponto_inicial[1] = y0;
    ponto_inicial[2] = z0;

    ponto_final[0] = x1;
    ponto_final[1] = y1;
    ponto_final[2] = z1;
}

void Malha::setCor(float r, float g, float b){
    cor[0] = r;
    cor[1] = g;
    cor[2] = b;
}

void Malha::pintarXZ(){
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    for (int i = ponto_inicial[0]; i <= ponto_final[2]; i+=1){
        glColor3f(cor[0], cor[1], cor[2]);

        glVertex3f((float)i, 0.0f, ponto_inicial[2]);
        glVertex3f((float)i, 0.0f, ponto_final[2]);
        glVertex3f(ponto_inicial[0], 0.0f,(float)i);
        glVertex3f(ponto_final[0], 0.0f,(float)i);
    }
    glEnd();
    glEnable(GL_LIGHTING);
}

void Malha::pintarXY(){
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    for (int i = ponto_inicial[0]; i <= ponto_final[1]; i+=1){
        glColor3f(cor[0], cor[1], cor[2]);

        glVertex3f((float)i, ponto_inicial[1], 0.0f);
        glVertex3f((float)i, ponto_final[1], 0.0f);
        glVertex3f(ponto_inicial[0], (float)i, 0.0f);
        glVertex3f(ponto_final[0], (float)i, 0.0f);
    }
    glEnd();
    glEnable(GL_LIGHTING);
}

void Malha::pintarYZ(){
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
    for (int i = ponto_inicial[1]; i <= ponto_final[2]; i+=1){
        glColor3f(cor[0], cor[1], cor[2]);

        glVertex3f(0.0f, ponto_inicial[1], (float)i);
        glVertex3f(0.0f, ponto_final[1], (float)i);
        glVertex3f(0.0f, (float)i, ponto_inicial[2]);
        glVertex3f(0.0f, (float)i, ponto_final[2]);
    }
    glEnd();
    glEnable(GL_LIGHTING);
}
