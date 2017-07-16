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
    
    printf("GERANDO VETOR COM FREQUENCIA DOS CARACTERES:\n");
    gera_vetor_ascii_frequencia(arquivo, vetor);
    printf("IMPRIMINDO VETOR\n");
    vetor_imprime(vetor);

    printf("\n");

    printf("GERANDO LISTA DE CARACTERES:\n");
    ListaArvore* nova_lista = gera_lista_caractes(vetor, 255);
    printf("IMPRIMINDO LISTA DE CARACTERES:\n");
    listaarvore_imprime(nova_lista);

    printf("\n");

    printf("GERANDO ARVORE OTIMA:\n");
    Arv* nova_arv = gera_arvore_huffman(nova_lista);
    printf("IMPRIMINDO ARVORE OTIMA:\n");
    arv_imprime(nova_arv);
    printf("LIBERANDO ARVORE OTIMA:\n");
    arv_libera(nova_arv);
    // arv_serializa(nova_arv);
    


    // ListaBits* lista_bits = listabits_cria();
    // procura_caminho('b', nova_arv, lista_bits);
    // printf("CAMINHO B:\n");
    // listabits_imprime(lista_bits);
    // 
    // 
    // 
    // ListaBits* lista_final = listabits_cria();
    // listabits_insere_lista_no_final(lista_final, lista_bits);
    // 
    // printf("LISTA FINAL:\n");
    // listabits_imprime(lista_final);
    
    fclose(arquivo);
    return 0;
}



















