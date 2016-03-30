#ifndef ESFERA_H
#define ESFERA_H

#include<GL/freeglut.h>

class Esfera
{
private:
    float raio;
    float slices;
    float stacks;
    float cor[3];
    float coordenadas[3];

public:
    Esfera();
    void setRaio(float);
    void setSlices(float);
    void setStacks(float);
    void setCor(float, float, float);
    void setCoordenadas(float, float, float);

    void pintar();
};

#endif // ESFERA_H
