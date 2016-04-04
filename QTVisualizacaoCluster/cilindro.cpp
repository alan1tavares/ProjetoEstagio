#include "cilindro.h"

Cilindro::Cilindro()
{
    raio = 1.0f;
    slices = 20;

    cor[0] = cor[1] = cor[2] = 0.0f;
}

void Cilindro::setRaio(float raio){
    this->raio = raio;
}

void Cilindro::setSlices(float slices){
    this->slices = slices;
}

void Cilindro::setCor(float r, float g, float b){
    cor[0] = r;
    cor[1] = g;
    cor[2] = b;
}

void Cilindro::setCoordenadas(float x1, float y1, float z1, float x2, float y2, float z2){
    coord_inicio[0] = x1;
    coord_inicio[1] = y1;
    coord_inicio[2] = z1;
    coord_final[0] = x2;
    coord_final[1] = y2;
    coord_final[2] = z2;
}

void Cilindro::pintar(){
    float vx = coord_final[0] - coord_inicio[0];
    float vy = coord_final[1] - coord_inicio[1];
    float vz = coord_final[2] - coord_inicio[2];

    //se por algum motivo z1 == z2 ele contorna esse problema fazendo uma aproximação
    if(vz == 0)
        vz = .0001;

    float v = sqrt(vx*vx + vy*vy + vz*vz);
    float ax = 57.2957795 * acos(vz/v);
    if (vz < 0.0)
        ax = -ax;
    float rx = -vy*vz;
    float ry = vx*vz;

    GLUquadricObj *quadric = gluNewQuadric();
    glPushMatrix();
    //desenha o corpo do cilindro
        glColor3f(cor[0], cor[1], cor[2]);
        glTranslatef(coord_inicio[0], coord_inicio[1], coord_inicio[2]);
        glRotatef(ax, rx, ry, 0.0);
        gluQuadricOrientation(quadric, GLU_OUTSIDE);
        gluCylinder(quadric, raio, raio, v, slices, 1);

        //draw the first cap
        gluQuadricOrientation(quadric, GLU_INSIDE);
        gluDisk(quadric, 0.0, raio, slices, 1);
        glTranslatef(0 ,0 ,v);

        //draw the second cap
        gluQuadricOrientation(quadric, GLU_OUTSIDE);
        gluDisk(quadric, 0.0, raio, slices, 1);
    glPopMatrix();
}
