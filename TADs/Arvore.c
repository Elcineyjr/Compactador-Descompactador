#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
#define ID_PESO 0
#define ID_CHAR 1

struct arvore
{
    int id_no_ou_folha;
    int peso;
    char caracter;
    struct arvore* esq;
    struct arvore* dir;
};

//Cria uma arvore vazia
Arv* arv_criavazia()
{
    return NULL;
}


//Verifica se uma arvore é vazia
int arv_vazia(Arv* arvore)
{
    return (arvore == NULL);
}


//Cria uma arvore FOLHA (com caracter)
Arv* arv_cria (char c, int peso, Arv* e, Arv* d)
{
    Arv* nova_arvore = (Arv*)malloc(sizeof(Arv));


    nova_arvore->caracter = c;
    nova_arvore->peso = peso;
    nova_arvore->esq = e;
    nova_arvore->dir = d;

    nova_arvore->id_no_ou_folha = ID_CHAR;

    return nova_arvore;
}


//Cria uma arvore sem caracter
Arv* arv_cria_no_comum(int peso, Arv* e, Arv* d)
{
    Arv* nova_arvore = (Arv*)malloc(sizeof(Arv));


    nova_arvore->peso = peso;
    nova_arvore->esq = e;
    nova_arvore->dir = d;

    nova_arvore->id_no_ou_folha = ID_PESO;

    return nova_arvore;
}


//Retorna o peso de uma arvore
int arv_get_peso(Arv* arvore)
{
    return arvore->peso;
}


//retorna o caracter de uma arvore
char arv_get_char(Arv* arvore)
{
    return arvore->caracter;
}


//Libera uma arvore
void arv_libera (Arv* a)
{
    if(a)
    {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }
}


//Imprime uma arvore
void arv_imprime(Arv* arvore)
{
    if(arv_vazia(arvore))
        return;

    arv_imprime(arvore->esq);
    arv_imprime(arvore->dir);
    if(arvore->id_no_ou_folha == ID_CHAR)
    {
        printf("NO FOLHA: %c\n", arvore->caracter);
    }
    else
    {
        printf("NO COMUM: %d\n", arvore->peso);
    }
}


//Faz o processo de serialização de uma arvore
void arv_serializa(Arv* arvore)
{
    if(arv_vazia(arvore))
        return;
    
    if(arvore->id_no_ou_folha == ID_CHAR)
    {
        printf("1%c", arvore->caracter);
        return;
    }    
    printf("0");
    arv_serializa(arvore->esq);
    arv_serializa(arvore->dir);  
}


//Procura o caminho do caracter na arvore
int procura_caminho(char c, Arv* arvore, ListaBits* lista){
    if(arvore){
        if(arvore->caracter == c){
            return 1;
        }
    }else{
        return 0;
    }

    if(procura_caminho(c, arvore->esq, lista)){
        listabits_insere_inicio(lista, 0);
        return 1;
    }

    if(procura_caminho(c, arvore->dir, lista)){
        listabits_insere_inicio(lista, 1);
        return 1;
    }

    return 0;
}