#include <stdio.h>
#include <stdlib.h>
#include "ListaBits.h"

struct celula{
    int bit;
    struct celula* prox;
};

typedef struct celula CelulaBit;

struct listaBits{
    CelulaBit* prim;
    CelulaBit* ult;
};

//Cria uma lista de bits vazia
ListaBits* listabits_cria(){
    ListaBits* nova_lista = (ListaBits*)malloc(sizeof(ListaBits));
    
    nova_lista->prim = NULL;
    nova_lista->ult = NULL;
    
    return nova_lista;
}


//verifica se a lista é vazia
int listabits_vazia(ListaBits* lista){
    return (lista->prim == NULL);
}


//insere um unico bit no inicio da lista
void listabits_insere_inicio(ListaBits* lista, int bit){
    CelulaBit* nova_celula = (CelulaBit*)malloc(sizeof(CelulaBit));
    
    nova_celula->bit = bit;
    
    if(listabits_vazia(lista)){
        nova_celula->prox = NULL;
        lista->prim = nova_celula;
        lista->ult = nova_celula;
        return;
    }
    
    nova_celula->prox = lista->prim;
    lista->prim = nova_celula;
}


//libera uma lista de bits
void listabits_libera(ListaBits* lista){
    CelulaBit* aux = lista->prim;
    
    while(aux){
        CelulaBit* aux2 = aux->prox;
        free(aux); //libera cada celula
        aux = aux2;
    }
    free(lista); //libera a lista vazia
}


//imprime um lista de bits
void listabits_imprime(ListaBits* lista){
    CelulaBit* aux = lista->prim;
    
    while(aux)
    {
        printf("%d\n",aux->bit);
        aux = aux->prox;
    }
}


//concatena duas listas de bits
void listabits_insere_lista_no_final(ListaBits* destino, ListaBits* lista){
    //se a lista destino for vazia a nova lista será inserida no inicio
    if(listabits_vazia(destino)){
        destino->prim = lista->prim;
        destino->ult = lista->ult;
        return;
    }
    
    //caso contrario será inserida no final da lista destino
    destino->ult->prox = lista->prim;
    destino->ult = lista->ult;
}
