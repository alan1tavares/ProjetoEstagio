#ifndef CILINDRO_H
#define CILINDRO_H

#include<math.h>
#include<GL/freeglut.h>

class Cilindro
{
private:
    float raio;
    float slices;
    float cor[3];
    float coord_inicio[3];
    float coord_final[3];

public:
    Cilindro();
    void setRaio(float);
    void setSlices(float);
    void setCor(float, float, float);
    void setCoordenadas(float, float, float, float, float, float);

    void pintar();
};

#endif // CILINDRO_H
