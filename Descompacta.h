#include "TADs/Arvore.h"
#include "TADs/ListaArvore.h"
#include "TADs/Vetor.h"
#include "TADs/ListaBits.h"
#include "TADs/bitmap.h"
#ifndef TRAB2_DESCOMPACTA_H
#define TRAB2_DESCOMPACTA_H

/*
*Input: -Arquivo compactado
*Output: Arvore otima
*Pre-condiçao: Nenhum
*Pós-condiçao: Arvore serializada no arquivo lida e então desserializada
*/
Arv* arv_desserializa(FILE* fp);

/*
*Input: -lista de bits
        -caracter
*Output: Nenhum
*Pre-condiçao: lista existente
*Pós-condiçao: sequencia de bits do char inserido na lista
*/
void transforma_char_em_bits(ListaBits* lista, char c);

/*
*Input: -arquivo compactado
        -lista de caminhos
*Output: Nenhum
*Pre-condiçao: lista existente
*Pós-condiçao: lista completa com caminhos de todos os caracteres
*/
void gera_listabits_com_caminhos_originais(FILE* arquivo_compactado, ListaBits* lista_original);

/*
*Input: Nenhum
*Output: Nenhum
*Pre-condiçao: Nenhuma
*Pós-condiçao: Arquivo compactado
*/
void descompacta_arquivo();

#endif //TRAB2_DESCOMPACTA_H
