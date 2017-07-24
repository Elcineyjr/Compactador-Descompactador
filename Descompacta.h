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
*Input:
*Output:
*Pre-condiçao:
*Pós-condiçao:
*/
void transforma_char_em_bits(ListaBits* lista, char c);

/*
*Input:
*Output:
*Pre-condiçao:
*Pós-condiçao:
*/
void gera_listabits_com_caminhos_originais(FILE* arquivo_compactado, ListaBits* lista_original);

/*
*Input:
*Output:
*Pre-condiçao:
*Pós-condiçao:
*/
void descompacta_arquivo();



/*
*Input:
*Output:
*Pre-condiçao:
*Pós-condiçao:
*/


#endif //TRAB2_DESCOMPACTA_H
