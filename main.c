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
#include "Descompacta.h"
#include <ctype.h>

int main(int argc, char const *argv[])
{
    const char* nome_arquivo = argv[argc - 1];
    
    FILE* arquivo = fopen(nome_arquivo, "r");
    if(arquivo == NULL){
        printf("Falha na abertura do arquivo! Abortando execução do programa!\n");
        exit(1);
    }
    
    compacta_arquivo(arquivo);
    fclose(arquivo);
    printf("Arquivo foi compactado!!\n");
    // FILE* descompacta = fopen("arquivoCompactado.txt", "r");
    // if(descompacta == NULL)
    // {
    //     printf("Falha na abertura do arquivo! Abortando execução do programa!\n");
    //     exit(1);
    // }
    descompacta_arquivo();
    
    //fclose(descompacta);
    
    
    
    
    
    
    
    
    
    
    
    
    // ListaBits* lista = listabits_cria();
    // printf("aaaaaaaa\n");
    // transforma_char_em_bits(lista, 'a'); //ALGO ERRADO NAO ESTÁ CERTO
    // listabits_imprime(lista);
    // listabits_limpa(lista);
    // 
    // printf("bbbbbbbb\n");
    // transforma_char_em_bits(lista, 'b'); //ALGO ERRADO NAO ESTÁ CERTO
    // listabits_imprime(lista);
    // listabits_limpa(lista);
    // 
    // printf("ccccccccc\n");
    // transforma_char_em_bits(lista, 'c'); //ALGO ERRADO NAO ESTÁ CERTO
    // listabits_imprime(lista);
    // listabits_limpa(lista);
    // 
    // printf("ddddddddd\n");
    // transforma_char_em_bits(lista, 'd'); //ALGO ERRADO NAO ESTÁ CERTO
    // listabits_imprime(lista);
    // listabits_limpa(lista);
    // 
    // printf("eeeeeeeeee\n");
    // transforma_char_em_bits(lista, 'e'); //ALGO ERRADO NAO ESTÁ CERTO
    // listabits_imprime(lista);
    // listabits_limpa(lista);
    
    
    
    // a 01100001
    // b 01100010
    // c 01100011
    // d 01100100
    // e 01100101
    // f 01100110
    // g 01100111
    return 0;
}



















