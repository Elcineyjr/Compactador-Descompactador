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
    FILE* arquivo = NULL;
    const char* nome_arquivo = argv[argc - 1];
    
    arquivo = fopen(nome_arquivo, "r");
    
    if(arquivo == NULL)
    {
        printf("Falha na abertura do arquivo! Abortando execução do programa!\n");
        exit(1);
    }
    
    compacta_arquivo(arquivo);
    fclose(arquivo);
    
    // FILE* descompacta = fopen("arquivoCompactado.txt", "r");
    // 
    // if(descompacta == NULL)
    // {
    //     printf("Falha na abertura do arquivo! Abortando execução do programa!\n");
    //     exit(1);
    // }
    // Arv* a = arv_desserializa(descompacta);
    // arv_imprime(a);
    // 
    // fclose(descompacta);
    return 0;
}



















