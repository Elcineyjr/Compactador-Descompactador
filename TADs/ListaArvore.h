#include "Arvore.h"
#ifndef TRAB2_LISTAARVORE_H
#define TRAB2_LISTAARVORE_H

typedef struct lista ListaArvore;

typedef struct celula Celula;

Celula* cria_celula(Arv* arvore);

ListaArvore* cria_listaarvore();

int listaarvore_vazia(ListaArvore* lista);

ListaArvore* listaarvore_insere_celula_ordenada(ListaArvore* lista, Celula* celula);

ListaArvore* gera_lista_caractes(int vetor[], int tamanho_vetor);

void listaarvore_imprime(ListaArvore* lista);

Arv* listaarvore_retira_primeiro(ListaArvore* lista);

Arv* gera_arvore_huffman(ListaArvore* lista);

#endif //TRAB2_LISTAARVORE_H
