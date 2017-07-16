#include <stdio.h>
#include <stdlib.h>
#include "ListaArvore.h"


struct celula{
    Arv* arvore;
    struct celula* prox;
};

struct lista{
    struct celula* prim;
    struct celula* ult;
};


//Cria uma celula e insere uma arvore na nova celula 
Celula* cria_celula(Arv* arvore){
    Celula* nova_celula = (Celula*)malloc(sizeof(Celula));

    nova_celula->arvore = arvore;
    nova_celula->prox = NULL;

    return nova_celula;
}


//Cria uma lista de arvore vazia
ListaArvore* cria_listaarvore(){
    ListaArvore* nova_lista = (ListaArvore*)malloc(sizeof(ListaArvore));

    nova_lista->prim = NULL;
    nova_lista->ult = NULL;

    return nova_lista;
}


//Verifica se a lista de arvore é vazia
int listaarvore_vazia(ListaArvore* lista){
    return (lista->prim == NULL);
}


//Insere uma celula na lista, ordenada pelo peso do caracter da celula
ListaArvore* listaarvore_insere_celula_ordenada(ListaArvore* lista, Celula* celula){
    if(listaarvore_vazia(lista)){
        lista->prim = celula;
        lista->ult = celula;

        return lista;
    }

    Celula* aux = lista->prim;
    Celula* ant = NULL;

    //itera a lista até achar a celula que será a prox da celula a ser inserida
    while(aux && arv_get_peso(aux->arvore) < arv_get_peso(celula->arvore)){
        ant = aux;
        aux = aux->prox;
    }

    //verificaçao de onde a nova celula será inserida e atualizaçao dos ponteiros prim e ult
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


//Gera uma lista com todos os caracteres do arquivo atraves do vetor ASCII
ListaArvore* gera_lista_caractes(int* vetor, int tamanho_vetor){
    ListaArvore* lista = (ListaArvore*)malloc(sizeof(ListaArvore));
    lista->prim = NULL;
    lista->ult = NULL;
    
    for(int i = 0; i < tamanho_vetor; i++){
        //vetor[i] indica a frequencia de cada caracter no arquivo
        //ou seja, se o caracter aparecer no arquivo pelo menos uma vez será inserido na lista
        if( vetor[i] > 0){
            Arv* a = arv_cria((char)i, vetor[i], arv_criavazia(), arv_criavazia());
            Celula* nova_celula = cria_celula(a);

            //insere o caracter na lista ordenando pela sua frequencia no arquivo 
            listaarvore_insere_celula_ordenada(lista, nova_celula);
        }
    }

    return lista;
}


//Imprime uma lista de caracteres
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


//Retorna a arvore da primeira celula da lista e destroi a celula 
Arv* listaarvore_retira_primeiro(ListaArvore* lista){
    if(listaarvore_vazia(lista))
        return NULL;

    Celula* aux = lista->prim;
    Arv* retorna = aux->arvore;

    lista->prim = aux->prox;
    free(aux);

    return retorna;
}


//Gera a arvore otima
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
