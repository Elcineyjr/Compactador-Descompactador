#include <stdio.h>
#include <stdlib.h>
#include "Descompacta.h"


Arv* arv_desserializa(FILE* fp) {
    char* c = (char*)malloc(sizeof(char));
    *c = fgetc(fp);

    Arv* a = NULL;
    if (*c == '0') {
        Arv* esquerda = arv_desserializa(fp);
        Arv* direita = arv_desserializa(fp);

        a = arv_cria_no_comum(0, esquerda, direita);
        return a;
    }
    if (*c == '1') {
        *c = fgetc(fp);
        a = arv_cria(*c, 0, NULL, NULL);
        return a;
    }
    free(c);
    return a;
}

