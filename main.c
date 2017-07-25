#include <stdio.h>
#include <stdlib.h>
#include "TADs/Arvore.h"
#include "TADs/ListaArvore.h"
#include "TADs/Vetor.h"
#include "TADs/ListaBits.h"
#include "Compacta.h"
#include "Descompacta.h"
#include <string.h>

/*
*
*   Segundo trabalho de ED1:
*   Compactador e Descompactador de arquivos
*
*/
int main(int argc, char const *argv[])
{
    const char* comando = argv[argc - 2];
    const char* nome_arquivo = argv[argc - 1];
    
    if(!strcmp(comando, "Compacta")){
        FILE* arquivo = fopen(nome_arquivo, "r");
        if(arquivo == NULL){
            printf("Falha na abertura do arquivo! Abortando execução do programa!\n");
            exit(1);
        }
        
        compacta_arquivo(arquivo);
        printf("Arquivo foi compactado!!\n");
    }else{
        if(!strcmp(comando, "Descompacta")){
            descompacta_arquivo();
            printf("Arquivo foi descompactado!!\n");
        }else{
            printf("Comando inválido!!\n");
        }
    }
    return 0;
}



















