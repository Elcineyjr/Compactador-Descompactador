#ifndef TRAB2_LISTABITS_H
#define TRAB2_LISTABITS_H

typedef struct listaBits ListaBits;

typedef struct celula CelulaBit;

/*
*Input: Nenhum
*Output: Lista de bits vazia
*Pre-condiçao: Nenhuma
*Pós-condiçao: Lista de bits criada e vazia
*/
ListaBits* listabits_cria();

/*
*Input: Lista de bits
*Output: inteiro (true or false)
*Pre-condiçao: Lista existente
*Pós-condiçao: Nenhuma
*/
int listabits_vazia(ListaBits* lista);


void listabits_limpa(ListaBits* lista);

void listabits_insere_celula(ListaBits* lista, CelulaBit* celula);

/*
*Input: -Lista de bits existente
        -bit a ser inserido
*Output: Nenhum
*Pre-condiçao: Lista existente
*Pós-condiçao: bit inserido no inicio da lista
*/
void listabits_insere_inicio(ListaBits* lista, int bit);

/*
*Input: Lista de bits
*Output: Nenhum
*Pre-condiçao: Lista existente
*Pós-condiçao: toda memoria alocada para lista liberada
*/
void listabits_libera(ListaBits* lista);

/*
*Input: Lista
*Output: Nenhum
*Pre-condiçao: Lista existente
*Pós-condiçao: Lista impressa
*/
void listabits_imprime(ListaBits* lista);

/*Esta funçao concatena duas listas de bits, inserindo "lista" ao final de "destino" 
*Input: -Lista de destino
        -Lista a ser inserida
*Output: Nenhum
*Pre-condiçao: Listas existentes
*Pós-condiçao: Lista inserida no final da ista destino 
*/
void listabits_insere_lista_no_final(ListaBits* destino, ListaBits* lista);

void listabits_pega_oito_primeiros(ListaBits* lista_geral, ListaBits* lista_nova);

#endif //TRAB2_LISTABITS_H