#include "TADs/Arvore.h"
#include "TADs/ListaArvore.h"
#include "TADs/Vetor.h"
#include "TADs/ListaBits.h"
#include "TADs/bitmap.h"
#ifndef TRAB2_COMPACTA_H
#define TRAB2_COMPACTA_H

/*
*Input: -char
        -Arvore a se procrar o char
        -Lista a ser inserido o caminho achado
*Output: int pois é recursiva
*Pre-condiçao: Arvore e lista existentes
*Pos-condiçao: Caminho ate o caracter inserido na lista dada
*/
int procura_caminho(unsigned char c, Arv* arvore, ListaBits* lista);

/*
*Input: -Arquivo a ser compactado
        -Arvore otima de huffman
        -Lista de bits 
*Output: Nenhum
*Pre-condiçao: Arvore e lista existentes
*Pós-condiçao: lista_final contem todos os caminhos na arvore de todos os caracteres do arquivo
*/
void gera_lista_final_de_caminhos(FILE* arquivo, Arv* arvore_otima, ListaBits* lista_final);

/*
*Input: -Arquivo a ser compactado 
*Output: Nenhum
*Pre-condiçao: Nenhum
*Pós-condiçao: Arquivo compactado
*/
void compacta_arquivo(FILE* arquivo_entrada);

#endif //TRAB2_COMPACTA_H