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
#include "Compacta.h"

int main()
{
    FILE* arquivo;
    //int vetor[255];

    arquivo = fopen("entrada.txt", "r");
    
    if(arquivo == NULL)
    {
        printf("Falha na abertura do arquivo! Abortando execução do programa!\n");
        exit(1);
    }
    
    compacta_arquivo(arquivo);
    
    // printf("GERANDO VETOR COM FREQUENCIA DOS CARACTERES:\n");
    // gera_vetor_ascii_frequencia(arquivo, vetor);
    // printf("IMPRIMINDO VETOR\n");
    // vetor_imprime(vetor);
    // fclose(arquivo);
    // 
    // printf("\n");
    // 
    // printf("GERANDO LISTA DE CARACTERES:\n");
    // ListaArvore* nova_lista = gera_lista_caractes(vetor, 255);
    // printf("IMPRIMINDO LISTA DE CARACTERES:\n");
    // listaarvore_imprime(nova_lista);
    // 
    // printf("\n");
    // 
    // printf("GERANDO ARVORE OTIMA:\n");
    // Arv* nova_arv = gera_arvore_huffman(nova_lista);
    // printf("IMPRIMINDO ARVORE OTIMA:\n");
    // arv_imprime(nova_arv);
    // 
    // printf("SERIALIZANDO ARVORE:\n");
    // arv_serializa(nova_arv);
    // printf("\n");
    // 
    // 
    // arquivo = fopen("entrada.txt", "r");
    // ListaBits* lista_caminhos = listabits_cria();
    // gera_lista_final_de_caminhos(arquivo, nova_arv, lista_caminhos);
    // listabits_imprime(lista_caminhos);
    // 
    // 
    // printf("RETIRANDO OITO PRIMEIROS:\n");
    // ListaBits* lista = listabits_cria();
    // listabits_pega_oito_primeiros(lista_caminhos, lista);
    // 
    // 
    // printf("IMPRIMINDO OS OITO:\n");
    // listabits_imprime(lista);
    // printf("IMPRIMINDO A GERAL:\n");
    // listabits_imprime(lista_caminhos);
    // 
    // 
    // 
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
    // 
    // printf("LIBERANDO ARVORE OTIMA:\n");
    // arv_libera(nova_arv);
    
    fclose(arquivo);
    return 0;
}



















