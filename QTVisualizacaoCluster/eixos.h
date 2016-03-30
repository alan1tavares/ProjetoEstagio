#ifndef EIXOS_H
#define EIXOS_H

#include<GL/freeglut.h>

class Eixos
{
private:
    float cor[3];
    float ponto_inicial[3];
    float ponto_final[3];

public: 
    Eixos();
    Eixos(float,float,float , float,float,float);
    void setCor(float, float, float);
    void setCoordenadas(float,float,float , float,float,float);

    void pintar();
};

#endif // EIXOS_H
