#include "arquivo.h"

Arquivo::Arquivo(string entrada){
    ifstream arquivo;
    string str;

    int cont, i, j;
    cont = 0;

    arquivo.open(entrada.c_str(), ifstream::in);

    // Alterar como uma janela de aviso
    if (!arquivo.is_open()) {
        cout << "Arquivo não encontrado";
        exit(1);
    }

    while (getline(arquivo, str)){
        if (str[0] == '[')
            cont++;
        if (cont == 3)
            break;
    }

    getline(arquivo, str,' ');
    //cout << str << ' ';
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

int Arquivo::getTamanho(){
    return numlinhas;
}

void Arquivo::imprimeMatriz(){
    for (int i=0; i < numlinhas; i++){
        for (int j=0; j < 9; j++)
            cout << matriz[i][j] << "   ";
        cout << endl;
    }
}

float Arquivo::getMatriz(int i, int j){
    return matriz[i][j];
}

Arquivo::~Arquivo(){
    int i;
    for (i = 0; i < numlinhas; i++)
        delete [] matriz[i];
    delete [] matriz;
}
