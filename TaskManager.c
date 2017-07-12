#include <stdio.h>
#include <stdlib.h>
#include "TaskManager.h"


void vetor_inicializa(int* vetor)
{
    //Limpa todos os campos do vetor
    for(int i = 0; i < 255; i++)
    {
        *(vetor+i) = 0;
    }
}


void vetor_imprime(int* vetor)
{
    //imprime todos os caracteres do arquivo e sua frequencia
    for(int i = 0; i < 255; i++)
    {
        //imprime apenas os caracteres que apareceram pelo menos uma vez no arquivo
        if ( *(vetor+i) == 0) continue;
        printf("%c (%d) - %d\n", i, i, *(vetor+i));
    }
}

void gera_vetor_ascii_frequencia(FILE* arquivo, int* vetor)
{
    vetor_inicializa(vetor);

    //aloca espaço pra um caracter e entao le o primeiro do arquivo
    char* a = (char*)malloc(sizeof(char));
    *a = fgetc(arquivo);

    while(*a != EOF) //EOF = End Of File, lendo assim todos caracteres do arquivo
    {
        int i = (int)*a;
        *(vetor+i) = *(vetor+i) + 1; //tenho que usar dessa forma
        //*(vetor+i)++;        <------- pq isso da erro?
        *a = fgetc(arquivo);
    }
    free(a);
}
