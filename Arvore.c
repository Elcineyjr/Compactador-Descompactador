#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

struct arvore
{
    int id_peso_ou_char;
    int peso;
    char caracter;
    struct arvore* esq;
    struct arvore* dir;
};


Arv* arv_criavazia()
{
    return NULL;
}


Arv* arv_cria (char c, int peso, Arv* e, Arv* d)
{
    Arv* nova_arvore = (Arv*)malloc(sizeof(Arv));

    //preciso alocar memoria pra um unico char ???
    //nova_arvore->caracter = (char)malloc(sizeof(char));
    nova_arvore->caracter = c;

    nova_arvore->peso = peso;

    nova_arvore->esq = e;
    nova_arvore->dir = d;

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
        //free(a->caracter);
    }

    return NULL;
}
