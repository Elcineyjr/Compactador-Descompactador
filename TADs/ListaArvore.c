#include <stdio.h>
#include <stdlib.h>
#include "ListaArvore.h"


//funçao que gera a lista com todos os caracteres
//funçao que transforma as duas primeiras celulas em uma arvore
//funçao que insere a arvore na lista (ordenada)
//funçao que retorna a unica arvore que sobrou na lista


struct celula{
    Arv* arvore;
    struct celula* prox;
};

struct lista{
    struct celula* prim;
    struct celula* ult;
};

Celula* cria_celula(Arv* arvore){
    Celula* nova_celula = (Celula*)malloc(sizeof(Celula));

    nova_celula->arvore = arvore;
    nova_celula->prox = NULL;

    return nova_celula;
}

ListaArvore* cria_listaarvore(){
    ListaArvore* nova_lista = (ListaArvore*)malloc(sizeof(ListaArvore));

    nova_lista->prim = NULL;
    nova_lista->ult = NULL;

    return nova_lista;
}


int listaarvore_vazia(ListaArvore* lista){
    return (lista->prim == NULL);
}


ListaArvore* listaarvore_insere_celula_ordenada(ListaArvore* lista, Celula* celula){
    if(listaarvore_vazia(lista)){
        lista->prim = celula;
        lista->ult = celula;

        return lista;
    }

    Celula* aux = lista->prim;
    Celula* ant = NULL;


    while(aux && arv_get_peso(aux->arvore) < arv_get_peso(celula->arvore)){
        ant = aux;
        aux = aux->prox;
    }

    if(aux == lista->prim){
        celula->prox = aux;
        lista->prim = celula;

        return lista;
    }
    if(aux == lista->ult){
        ant->prox = celula;
        celula->prox = aux;

        return lista;
    }
    if(ant == lista->ult){
        lista->ult = celula;
    }
    ant->prox = celula;
    celula->prox = aux;

    return lista;
}


ListaArvore* gera_lista_caractes(int* vetor, int tamanho_vetor){
    ListaArvore* lista = (ListaArvore*)malloc(sizeof(ListaArvore));

    for(int i = 0; i < tamanho_vetor; i++){
        if( vetor[i] > 0){
            Arv* a = arv_cria((char)i, vetor[i], arv_criavazia(), arv_criavazia());
            Celula* nova_celula = cria_celula(a);

            listaarvore_insere_celula_ordenada(lista, nova_celula);
        }
    }

    return lista;
}


void listaarvore_imprime(ListaArvore* lista){
    if(listaarvore_vazia(lista)){
        printf("Lista Vazia\n");
        return;
    }

    Celula* aux = lista->prim;
    while(aux){
        printf("%c\n", arv_get_char(aux->arvore));
        aux = aux->prox;
    }
}


Arv* listaarvore_retira_primeiro(ListaArvore* lista){
    if(listaarvore_vazia(lista))
        return NULL;

    Celula* aux = lista->prim;
    Arv* retorna = aux->arvore;

    lista->prim = aux->prox;
    free(aux);

    return retorna;
}


Arv* gera_arvore_huffman(ListaArvore* lista){
    while(lista->prim->prox){
        Arv* a = listaarvore_retira_primeiro(lista);
        Arv* b = listaarvore_retira_primeiro(lista);

        int soma = arv_get_peso(a) + arv_get_peso(b);

        Arv* nova_arvore = arv_cria_no_comum(soma, a, b);
        Celula* nova_celula = cria_celula(nova_arvore);

        listaarvore_insere_celula_ordenada(lista, nova_celula);
    }

    Arv* retorna = listaarvore_retira_primeiro(lista);
    free(lista);

    return retorna;
}
