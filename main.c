/*
*
*   Segundo trabalho de ED1
*
*/



/*
*********************************
* Programa testador
*********************************
*/
#include <stdio.h>
#include "Arvore.h"
#include "ListaArvore.h"

int main()
{
    int tam = 70;
    int vetor[tam];

    int i = 0;
    while(i < tam)
    {
        vetor[i] = 0;
        i++;
    }

    vetor[65] = 1;
    vetor[66] = 2;
    vetor[67] = 3;
    vetor[68] = 4;
    vetor[69] = 5;


    ListaArvore* a;

    a = gera_lista_caractes(vetor, tam);

    lista_imprime(a);

    lista_retira_primeiro(a);
    lista_retira_primeiro(a);
    lista_imprime(a);
    return 0;
}
