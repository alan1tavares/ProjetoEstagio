#ifndef EIXOS_H
#define EIXOS_H

#include "forma.h"
#include<GL/freeglut.h>

class Eixos : public Forma
{
private:
    int tamanho;
    float cor[3];
    float ponto_incial[3];
    float ponto_final[3];

public: 
    Eixos();
    Eixos(float,float,float , float,float,float);
    void set_cor(float, float, float);
    void set_coordenadas(float,float,float , float,float,float);

    void pintar();
};

#endif // EIXOS_H
