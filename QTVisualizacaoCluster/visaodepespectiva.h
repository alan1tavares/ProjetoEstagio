#ifndef VISAODEPESPECTIVA_H
#define VISAODEPESPECTIVA_H

#include<GL/freeglut.h>

class VisaoDePespectiva
{
private:
    float angulo;
    float aspecto;
    float plano_frente;
    float plano_fundo;

    float posicao_camera[3];
    float direcao_visao[3];
    float orientacao_camera[3];

    float translacao[3];
    float rotacao_angulo[3];

public:
    VisaoDePespectiva();
    void setCamera(float, float, float, float, float, float, float, float, float);
    void fazerTranslacao(float, float, float);
    void fazerRotacao(float, float, float);
    void setPespectiva(float, float, float, float);
    void pintar();
};

#endif // VISAODEPESPECTIVA_H
