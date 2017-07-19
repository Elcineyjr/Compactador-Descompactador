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

void gera_lista_final_de_caminhos(FILE* arquivo, Arv* arvore_otima, ListaBits* lista_final);

void compacta_arquivo(FILE* arquivo_entrada);

#endif //TRAB2_COMPACTA_H