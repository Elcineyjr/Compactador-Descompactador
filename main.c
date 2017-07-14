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
#include "TADs/Vetor.h"
#include "TADs/ListaBits.h"


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

    //lista_imprime(nova_lista);

    Arv* nova_arv = gera_arvore_huffman(nova_lista);

    // printf("ARVORE::::::::\n");
    // arv_imprime(nova_arv);
    
    // arv_serializa(nova_arv);
    // printf("\n");

    ListaBits* lista_bits = listabits_cria();
    procura_caminho('b', nova_arv, lista_bits);
    printf("CAMINHO B:\n");
    listabits_imprime(lista_bits);
    
    ListaBits* lista_bits2 = listabits_cria();
    procura_caminho('o', nova_arv, lista_bits2);
    printf("CAMINHO O:\n");
    listabits_imprime(lista_bits2);
    
    ListaBits* lista_bits3 = listabits_cria();
    procura_caminho('m', nova_arv, lista_bits3);
    printf("CAMINHO M:\n");
    listabits_imprime(lista_bits3);
    
    
    ListaBits* lista_final = listabits_cria();
    listabits_insere_lista_no_final(lista_final, lista_bits);
    listabits_insere_lista_no_final(lista_final, lista_bits2);
    listabits_insere_lista_no_final(lista_final, lista_bits3);
    
    printf("LISTA FINAL:\n");
    listabits_imprime(lista_final);
    
    fclose(arquivo);
    return 0;
}



















