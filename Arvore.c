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


Arv* arv_criavazia()
{
    return NULL;
}

int arv_vazia(Arv* arvore)
{
    return (arvore == NULL);
}

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


Arv* arv_cria_no_comum(int peso, Arv* e, Arv* d)
{
    Arv* nova_arvore = (Arv*)malloc(sizeof(Arv));


    nova_arvore->peso = peso;
    nova_arvore->esq = e;
    nova_arvore->dir = d;

    nova_arvore->id_no_ou_folha = ID_PESO;

    return nova_arvore;
}


int arv_get_peso(Arv* arvore)
{
    return arvore->peso;
}


char arv_get_char(Arv* arvore)
{
    return arvore->caracter;
}


Arv* arv_libera (Arv* a)
{
    if(a)
    {
        arv_libera(a->esq);
        arv_libera(a->dir);
        free(a);
    }

    return NULL;
}

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
