#include <stdio.h>
#include <stdlib.h>
#include "Vetor.h"


void vetor_inicializa(int* vetor)
{
    //Limpa todos os campos do vetor
    for(int i = 0; i < 255; i++)
    {
        vetor[i] = 0;
    }
}


void vetor_imprime(int* vetor)
{
    //imprime todos os caracteres do arquivo e sua frequencia
    for(int i = 0; i < 255; i++)
    {
        //imprime apenas os caracteres que apareceram pelo menos uma vez no arquivo
        if ( vetor[i] == 0) continue;
        printf("%c (%d) - %d\n", i, i, vetor[i]);
    }
}

int vetor_verifica_vazio(int* vetor)
{
    for(int i = 0; i < 255; i++)
    {
        if(vetor[i] > 0)
            return 0;
    }
    return 1;
}


void gera_vetor_ascii_frequencia(FILE* arquivo, int* vetor)
{
    vetor_inicializa(vetor);

    //aloca espaço pra um caracter e entao le o primeiro do arquivo
    unsigned char* a = (unsigned char*)malloc(sizeof(char));
    *a = fgetc(arquivo);

    while(*a != EOF) //EOF = End Of File, lendo assim todos caracteres do arquivo
    {
        int i = (int)*a;
        vetor[i]++;
        *a = fgetc(arquivo);
        if(*a == 255)
            break;
    }
    free(a);
    
    if(vetor_verifica_vazio(vetor))
    {
        printf("Arquivo vazio! O programa será abortado!\n");
        exit(2);
    }
}
