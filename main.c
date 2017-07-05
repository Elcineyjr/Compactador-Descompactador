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

    vetor[65] = 0;
    vetor[66] = 0;
    vetor[67] = 1;
    vetor[68] = 10;
    vetor[69] = 0;


    ListaArvore* a;

    a = gera_lista_caractes(vetor, tam);

    lista_imprime(a);
    return 0;
}
