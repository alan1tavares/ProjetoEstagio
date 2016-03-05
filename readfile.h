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
    int tam;
public:
    Cluster();
    int getTamanho();
    void imprimeMatriz();
    float getMatriz(int, int);
};

Cluster::Cluster(){
    ifstream arquivo;
    string str;
    int cont, i, j;
    cont = 0;

    arquivo.open("Teste.s3d", ifstream::in);

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
    tam = atoi(str.c_str());
    cout << tam << endl;

    matriz = new float*[tam];
    for(i=0; i < tam; i++)
        matriz[i] = new float[tam];

    for (i=0; i < tam; i++){
        for (j=0; j < 9; j++)
            arquivo >> matriz[i][j];
    }
}

int Cluster::getTamanho(){
    return tam;
}

void Cluster::imprimeMatriz(){
    for (int i=0; i < tam; i++){
        for (int j=0; j < 9; j++)
            cout << matriz[i][j] << "   ";
        cout << endl;
    }
}

float Cluster::getMatriz(int i, int j){
    return matriz[i][j];
}
#endif
