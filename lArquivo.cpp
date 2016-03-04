#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lArquivo.h"

#include <iostream>


using namespace std;
//==============================================================================
//
//==============================================================================
char *tira_quebra(char *str)
{
	int i;
		
	for(i=0; str[i]!='\n'; i++)
		;
	
	str[i-1] = '\0';
	
	return str;
}
//==============================================================================
//
//==============================================================================
void lArquivo()
{
	//variaveis
	char str[300];
	FILE *parquivo;
	int tam, i;
	
	//Abrindo o arquivo
	parquivo = fopen("Teste.s3d", "r");
	
	// Programa irá rodar todo o arquivo e irá parar em [ARESTAS]..	
	do{
		fgets(str, 300, parquivo);
	}while( strcmp( tira_quebra(str) , "[ARESTAS]" ) );

	//pegando o tamanho, a quantidade de linhas a seguir, e terminando a linha.
	
	fscanf(parquivo, "%s %d", str, &tam);
	fgets(str, 300, parquivo);

	//Lendo todos os numeros e salvando em uma matriz
	long double matriz[tam][9];
	
	for(i = 0; i< tam; i++){
		fscanf(parquivo, "%LF %LF %LF %LF %LF %LF %LF %LF %LF", &matriz[i][0], &matriz[i][1], &matriz[i][2], &matriz[i][3], &matriz[i][4], &matriz[i][5], &matriz[i][6], &matriz[i][7], &matriz[i][8]);
		fgets(str, 300, parquivo);
	}

	for(i = 0; i< tam; i++){
		printf("%.14LF %.14LF %.14LF %.14LF %.14LF %.14LF %.14LF %.14LF %.14LF\n", matriz[i][0], matriz[i][1], matriz[i][2], matriz[i][3], matriz[i][4], matriz[i][5], matriz[i][6], matriz[i][7], matriz[i][8]);
		fgets(str, 300, parquivo);
	}
	fclose(parquivo);
	// Grande problema, agora tenho que achar como retornar essa matriz por parametro

	//continua...
}
