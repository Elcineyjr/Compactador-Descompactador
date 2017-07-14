/*
*
*   Segundo trabalho de ED1
*
*/



/*
*********************************
* Programa testador
*********************************
*/
#include <stdio.h>
#include <stdlib.h>
#include "TADs/Arvore.h"
#include "TADs/ListaArvore.h"
#include "Compacta.h"

int main()
{
    FILE* arquivo;
    int vetor[255];

    arquivo = fopen("entrada.txt", "r");
    
    if(arquivo == NULL)
    {
        printf("Falha na abertura do arquivo! Abortando execução do programa!\n");
        exit(1);
    }
    
    gera_vetor_ascii_frequencia(arquivo, vetor);

    //vetor_imprime(vetor);

    ListaArvore* nova_lista = gera_lista_caractes(vetor, 255);
    //printf("11111111111\n");

    //lista_imprime(nova_lista);

    Arv* nova_arv = gera_arvore_huffman(nova_lista);
    //printf("22222222222\n");

    //arv_imprime(nova_arv);
    
    arv_serializa(nova_arv);
    printf("\n");

    fclose(arquivo);
    return 0;
}
