#include <stdio.h>
#include <stdlib.h>
#include "Compacta.h"
#define tamanho_ASCII 255

void compacta_arquivo(FILE* arquivo){
    int vetor[tamanho_ASCII];
    ListaArvore* lista_caracteres;
    Arv* arvore_otima;
    
    gera_vetor_ascii_frequencia(arquivo, vetor);
    lista_caracteres = gera_lista_caractes(vetor, tamanho_ASCII);
    arvore_otima = gera_arvore_huffman(lista_caracteres);
    
    //********** TERMINAR FUNÇAO ***************
}