#ifndef VISAODEPESPECTIVA_H
#define VISAODEPESPECTIVA_H


class VisaoDePespectiva
{
private:
    float angulo;
    float aspecto;
    float plano_frente;
    float plano_fundo;
    float posicao_camera[3];
    float posicao_objeto[3];
    float orientacao_camera[3];

public:
    VisaoDePespectiva();
    VisaoDePespectiva(float, float, float, float);
    void setCamera(float, float, float, float, float, float, float, float, float);
    void translandar(float, float, float);
    void fazer_rotacao(float, float, float,);
};

#endif // VISAODEPESPECTIVA_H
