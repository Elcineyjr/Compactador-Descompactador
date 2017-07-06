#include <stdio.h>
#include <stdlib.h>
#include "ListaArvore.h"


//funçao que gera a lista com todos os caracteres
//funçao que transforma as duas primeiras celulas em uma arvore
//funçao que insere a arvore na lista (ordenada)
//funçao que retorna a unica arvore que sobrou na lista


struct celula
{
    Arv* arvore;
    struct celula* prox;
};

struct lista
{
    struct celula* prim;
    struct celula* ult;
};


ListaArvore* cria_lista()
{
    ListaArvore* nova_lista = (ListaArvore*)malloc(sizeof(ListaArvore));

    nova_lista->prim = NULL;
    nova_lista->ult = NULL;

    return nova_lista;
}


int lista_vazia(ListaArvore* lista)
{
    if(!lista->prim)
    {
        return 1;
    }
    return 0;
}


ListaArvore* lista_insere_celula_ordenada(ListaArvore* lista, Celula* celula)
{
    if(lista_vazia(lista))
    {
        lista->prim = celula;
        lista->ult = celula;

        return lista;
    }

    Celula* aux = lista->prim;
    Celula* ant = NULL;


    while(aux && arv_get_peso(aux->arvore) < arv_get_peso(celula->arvore))
    {
        ant = aux;
        aux = aux->prox;
    }

    if(aux == lista->prim)
    {
        celula->prox = aux;
        lista->prim = celula;

        return lista;
    }
    if(aux == lista->ult)
    {
        ant->prox = celula;
        celula->prox = aux;

        return lista;
    }
    if(ant == lista->ult)
    {
        lista->ult = celula;
    }
    ant->prox = celula;
    celula->prox = aux;

    return lista;
}


ListaArvore* gera_lista_caractes(int vetor[], int tamanho_vetor)
{
    ListaArvore* lista = (ListaArvore*)malloc(sizeof(ListaArvore));

    for(int i = 0; i < tamanho_vetor; i++)
    {
        if(vetor[i] > 0)
        {
            Celula* nova_celula = (Celula*)malloc(sizeof(Celula));

            nova_celula->arvore = arv_cria((char)i, vetor[i], arv_criavazia(), arv_criavazia());
            nova_celula->prox = NULL;

            lista_insere_celula_ordenada(lista, nova_celula);
        }
    }

    return lista;
}


void lista_imprime(ListaArvore* lista)
{
    if(lista_vazia(lista))
    {
        printf("Lista Vazia\n");
        return;
    }

    Celula* aux = lista->prim;
    while(aux)
    {
        printf("%c\n", arv_get_char(aux->arvore));
        aux = aux->prox;
    }
}


Arv* lista_retira_primeiro(ListaArvore* lista)
{
    if(lista_vazia(lista))
        return NULL;

    Celula* aux = lista->prim;
    Arv* retorna = aux->arvore;

    lista->prim = aux->prox;
    free(aux);

    return retorna;
}


//*****************TERMINAR ESSA FUNÇAO************************
Arv* gera_arvore_huffman(ListaArvore* lista)
{
    while(lista->prim->prox)
    {
        Arv* a = lista_retira_primeiro(lista);
        Arv* b = lista_retira_primeiro(lista);

        int soma = arv_get_peso(a) + arv_get_peso(b);
        Arv* novo = arv_cria(NULL, soma, a, b);

    }
}