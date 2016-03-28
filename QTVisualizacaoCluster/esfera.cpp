#include "esfera.h"

Esfera::Esfera()
{
    raio = 2.0f;
    slices = 30;
    stacks = 30;

    cor[0] = cor[1] = cor[2] = 0.0f;
}

void Esfera::setRaio(float raio){
    this->raio = raio;
}

void Esfera::setSlices(float slices){
    this->slices;
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
    glutWireSphere(raio, slices, stacks);
    glPopMatrix();
}