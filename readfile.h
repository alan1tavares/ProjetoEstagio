#ifndef READFILE_H
#define READFILE_H
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <fstream>

using namespace std;

class Cluster{
private:
    float** matriz;
    int numlinhas;
public:
    Cluster();                      //Construtor
    int getTamanho();               //Função que retorna o numero de pontos
    void imprimeMatriz();           //Função para exibir a matriz
    float getMatriz(int, int);      //Função que retorna a matriz
    ~Cluster();                     //Destrutor
};

Cluster::Cluster(){
    ifstream arquivo;
    string str;
    int cont, i, j;
    cont = 0;

    arquivo.open("Teste1.s3d", ifstream::in);

    if (!arquivo.is_open()) {
        cout << "bye!";
        exit(1);
    }

    while (getline(arquivo, str)){
        if (str[0] == '[')
            cont++;
        if (cont == 3)
            break;
    }

    getline(arquivo, str,' ');
    cout << str << ' ';
    getline(arquivo, str);
    numlinhas = atoi(str.c_str());
    cout << numlinhas << endl;

    matriz = new float*[numlinhas];
    for(i=0; i < numlinhas; i++)
        matriz[i] = new float[numlinhas];

    for (i=0; i < numlinhas; i++){
        for (j=0; j < 9; j++)
            arquivo >> matriz[i][j];
    }
}

int Cluster::getTamanho(){
    return numlinhas;
}

void Cluster::imprimeMatriz(){
    for (int i=0; i < numlinhas; i++){
        for (int j=0; j < 9; j++)
            cout << matriz[i][j] << "   ";
        cout << endl;
    }
}

float Cluster::getMatriz(int i, int j){
    return matriz[i][j];
}

Cluster::~Cluster(){
    int i;
    for (i = 0; i < numlinhas; i++)
        delete [] matriz[i];
    delete [] matriz;
}
#endif
