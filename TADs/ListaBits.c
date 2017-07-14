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


ListaBits* listabits_cria(){
    ListaBits* nova_lista = (ListaBits*)malloc(sizeof(ListaBits));
    
    nova_lista->prim = NULL;
    nova_lista->ult = NULL;
    
    return nova_lista;
}

int listabits_vazia(ListaBits* lista){
    return (lista->prim == NULL);
}

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


void listabits_libera(ListaBits* lista){
    CelulaBit* aux = lista->prim;
    
    while(aux){
        CelulaBit* aux2 = aux->prox;
        free(aux);
        aux = aux2;
    }
    free(lista);
}


void listabits_imprime(ListaBits* lista){
    CelulaBit* aux = lista->prim;
    
    while(aux)
    {
        printf("%d\n",aux->bit);
        aux = aux->prox;
    }
}

void listabits_insere_lista_no_final(ListaBits* destino, ListaBits* lista){
    if(listabits_vazia(destino)){
        destino->prim = lista->prim;
        destino->ult = lista->ult;
        return;
    }
    
    destino->ult->prox = lista->prim;
    destino->ult = lista->ult;
}
