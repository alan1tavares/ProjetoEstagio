#include "esfera.h"

Esfera::Esfera()
{
    raio = 4.0f;
    slices = 20;
    stacks = 100;

    cor[0] = cor[1] = cor[2] = 0.0f;
}

void Esfera::setRaio(float raio){
    this->raio = raio;
}

void Esfera::setSlices(float slices){
    this->slices = slices;
}

void Esfera::setStacks(float stacks){
    this->stacks = stacks;
}

void Esfera::setCor(float r, float g, float b){
    cor[0] = r;
    cor[1] = g;
    cor[2] = b;
}

void Esfera::setCoordenadas(float x, float y, float z){
    coordenadas[0] = x;
    coordenadas[1] = y;
    coordenadas[2] = z;
}

void Esfera::pintar(){
    glPushMatrix();
    glTranslatef(coordenadas[0], coordenadas[1], coordenadas[2]);
    glColor3f(cor[0], cor[1], cor[2]);
    GLUquadricObj *quad = gluNewQuadric();
    gluSphere(quad, raio, slices, stacks);
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);pra dazer o wire
    glPopMatrix();
}


// Fazer o destrutor
