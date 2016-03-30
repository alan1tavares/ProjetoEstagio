#ifndef MALHA_H
#define MALHA_H

#include<GL/freeglut.h>

class Malha
{
private:
    float cor[3];
    float ponto_inicial[3];
    float ponto_final[3];

public:
    Malha();
    Malha(float,float,float , float,float,float);
    void setCor(float, float, float);
    void setCoordenadas(float,float,float , float,float,float);

    void pintarXZ();
    void pintarXY();
    void pintarYZ();

};


#endif // MALHA_H
