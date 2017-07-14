#ifndef TRAB2_LISTABITS_H
#define TRAB2_LISTABITS_H

typedef struct listaBits ListaBits;

ListaBits* listabits_cria();

int listabits_vazia(ListaBits* lista);

void listabits_insere_inicio(ListaBits* lista, int bit);

void listabits_libera(ListaBits* lista);

void listabits_imprime(ListaBits* lista);

void listabits_insere_lista_no_final(ListaBits* destino, ListaBits* lista);

#endif //TRAB2_LISTABITS_H