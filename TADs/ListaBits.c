#include <stdio.h>
#include <stdlib.h>
#include "ListaBits.h"

struct celula{
    int bit;
    struct celula* prox;
};


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


//Limpa uma lista de bits
void listabits_limpa(ListaBits* lista){
    lista->prim = NULL;
    lista->ult = NULL;
}


//insere uma celula em uma lista
void listabits_insere_celula(ListaBits* lista, CelulaBit* celula){
    if(listabits_vazia(lista)){
        lista->prim = celula;
        lista->ult = celula;
        return;
    }
    
    celula->prox = NULL;
    lista->ult->prox = celula;
    lista->ult = celula;
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
    if(listabits_vazia(lista)){
        printf("Lista de Bits vazia!!\n");
        return;
    }
    
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
    if(listabits_vazia(lista))
        return;
    if(listabits_vazia(destino)){
        destino->prim = lista->prim;
        destino->ult = lista->ult;
        return;
    }
    
    //caso contrario será inserida no final da lista destino
    destino->ult->prox = lista->prim;
    destino->ult = lista->ult;
}


//Pega os primeiros 8 elementos de uma lista e insere em uma nova
void listabits_pega_sete_primeiros(ListaBits* lista_geral, ListaBits* lista_nova){
    if(listabits_vazia(lista_geral)){
        printf("Lista geral de bits está vazia!!\n");
        return;
    }
    
    int i = 0;
    CelulaBit* aux = lista_geral->prim;
    CelulaBit* aux2;
    //pega as primeiras 7 celulas da lista_geral e insere na lista_nova
    while(aux && i < 7){
        aux2 = aux->prox;
        listabits_insere_celula(lista_nova, aux);
        aux = aux2;
        i++;
    }
    
    lista_geral->prim = aux;
    //se aux for nulo significa que toda a lista está vazia
    if(!aux)
        lista_geral->ult = NULL;    
}


//confere o tamanho de uma lista
int listabits_tamanho(ListaBits* lista){
    CelulaBit* aux = lista->prim;
    int i = 0;
    
    while(aux){
        i++;
        aux = aux->prox;
    }
    return i;
}


//completa uma lista de bits com 0's
void listabits_completa_com_zeros(ListaBits* lista){
    int tamanho_lista = listabits_tamanho(lista);
    
    while (tamanho_lista < 8){
        CelulaBit* nova_celula = (CelulaBit*)malloc(sizeof(CelulaBit));
        nova_celula->bit = 0;
        nova_celula->prox = NULL;
        
        lista->ult->prox = nova_celula;
        lista->ult = nova_celula;
        tamanho_lista = listabits_tamanho(lista);
    }    
}

//percorre a lista até achar a celula com index dado
int listabits_retorna_bit_por_index(ListaBits* lista, int index){
    CelulaBit* aux = lista->prim;
    int i = 0;
    
    while(i < index){
        aux = aux->prox;
        i++;
    }
    
    int bit = aux->bit;
    return bit;
}


