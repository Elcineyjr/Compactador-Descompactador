#include <stdio.h>
#include <stdlib.h>
#include "Compacta.h"
#define tamanho_ASCII 255


//Procura o caminho do caracter na arvore e insere na lista 
int procura_caminho(char c, Arv* arvore, ListaBits* lista){
    if(arvore){
        if(arv_get_char(arvore) == c){
            return 1;
        }
    }else{
        return 0;
    }

    if(procura_caminho(c, arv_retorna_esq(arvore) , lista)){
        listabits_insere_inicio(lista, 0);
        return 1;
    }

    if(procura_caminho(c, arv_retorna_dir(arvore) , lista)){
        listabits_insere_inicio(lista, 1);
        return 1;
    }

    return 0;
}


//Le cada caracter do arquivo e acha seu caminho na arvore
void gera_lista_final_de_caminhos(FILE* arquivo, Arv* arvore_otima, ListaBits* lista_final){
    ListaBits* lista_temporaria = listabits_cria();
    
    //aloca espaço pra um caracter e entao le o primeiro do arquivo
    char* a = (char*)malloc(sizeof(char));
    *a = fgetc(arquivo);

    while(*a != EOF) //EOF = End Of File, lendo assim todos caracteres do arquivo
    {
        listabits_limpa(lista_temporaria);
        procura_caminho(*a, arvore_otima, lista_temporaria);
        listabits_insere_lista_no_final(lista_final, lista_temporaria);
        *a = fgetc(arquivo);
    }
    free(a);
    free(lista_temporaria);
}

void compacta_arquivo(FILE* arquivo){
    int vetor[tamanho_ASCII];
    ListaArvore* lista_caracteres;
    Arv* arvore_otima;
    
    gera_vetor_ascii_frequencia(arquivo, vetor);
    lista_caracteres = gera_lista_caractes(vetor, tamanho_ASCII);
    arvore_otima = gera_arvore_huffman(lista_caracteres);
    
    //********** TERMINAR FUNÇAO ***************
}