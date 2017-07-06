#include "Arvore.h"
#ifndef TRAB2_LISTAARVORE_H
#define TRAB2_LISTAARVORE_H

typedef struct lista ListaArvore;

typedef struct celula Celula;

ListaArvore* cria_lista();

int lista_vazia(ListaArvore* lista);

ListaArvore* lista_insere_celula_ordenada(ListaArvore* lista, Celula* celula);

ListaArvore* gera_lista_caractes(int vetor[], int tamanho_vetor);

void lista_imprime(ListaArvore* lista);

Arv* lista_retira_primeiro(ListaArvore* lista);

Arv* gera_arvore_huffman(ListaArvore* lista);

#endif //TRAB2_LISTAARVORE_H
