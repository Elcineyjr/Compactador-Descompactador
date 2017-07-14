#include "Arvore.h"
#ifndef TRAB2_LISTAARVORE_H
#define TRAB2_LISTAARVORE_H

typedef struct lista ListaArvore;

typedef struct celula Celula;

/*
*Input: Arvore 
*Output: Celula
*Pre-condiçao: Arvore inicializada
*Pos-condiçao: Celula criada
*/
Celula* cria_celula(Arv* arvore);

/*
*Input: Nenhum
*Output: Lista de arvores
*Pre-condiçao: Nenhuma
*Pos-condiçao: Lista de arvores criada e vazia
*/
ListaArvore* cria_listaarvore();

/*
*Input: Lista de arvores
*Output: inteiro(true or false)
*Pre-condiçao: Lista existente
*Pos-condiçao: Nenhuma
*/
int listaarvore_vazia(ListaArvore* lista);

/*
*Input: -Lista de arvores
        -Celula a ser inserida
*Output: Lista de arvore
*Pre-condiçao: Lista e celula existentes
*Pos-condiçao: Celula inserida na lista
*/
ListaArvore* listaarvore_insere_celula_ordenada(ListaArvore* lista, Celula* celula);

/*
*Input: -Vetor 
        -Tamanho do vetor
*Output: Lista de arvores, com cada celula contendo apenas um caracter
*Pre-condiçao: Vetor existente
*Pos-condiçao: Lista de caracteres gerada
*/
ListaArvore* gera_lista_caractes(int vetor[], int tamanho_vetor);

/*
*Input: Lista de arvores (nesse caso uma lista de caracteres)
*Output: Nenhum
*Pre-condiçao: Lista existente
*Pos-condiçao: Lista impressa
*/
void listaarvore_imprime(ListaArvore* lista);

/*
*Input: Lista de arvores
*Output: Arvore da primeira celula
*Pre-condiçao: Lista existente
*Pos-condiçao: Arvore retornada e primeira celula destruida
*/
Arv* listaarvore_retira_primeiro(ListaArvore* lista);

/*
*Input: Lista de arvores (lista de todos os caracteres do arquivo)
*Output: Arvore otima
*Pre-condiçao: Lista existente
*Pos-condiçao: arvore otima gerada e retornada
*/
Arv* gera_arvore_huffman(ListaArvore* lista);

#endif //TRAB2_LISTAARVORE_H
