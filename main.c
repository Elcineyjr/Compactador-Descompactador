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
#include "TaskManager.h"

int main()
{
    FILE* arquivo;
    int vetor[255];

    arquivo = fopen("entrada.txt", "r");

    gera_vetor_ascii_frequencia(arquivo, vetor);

    vetor_imprime(vetor);

    return 0;
}
