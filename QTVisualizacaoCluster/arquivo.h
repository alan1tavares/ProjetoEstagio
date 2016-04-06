#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>


using namespace std;

class Arquivo{
private:
    float** matriz;
    int numlinhas;
public:
    Arquivo(string);                //Construtor
    int getTamanho();               //Função que retorna o numero de pontos
    void imprimeMatriz();           //Função para exibir a matriz
    float getMatriz(int, int);      //Função que retorna a matriz
    ~Arquivo();                     //Destrutor
};

#endif // ARQUIVO_H
