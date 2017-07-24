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
*Input:
*Output:
*Pre-condiçao:
*Pós-condiçao:
*/
CelulaBit* listabits_cria_celula(int bit);

/*
*Input: Lista de bits
*Output: inteiro (true or false)
*Pre-condiçao: Lista existente
*Pós-condiçao: Nenhuma
*/
int listabits_vazia(ListaBits* lista);

/*
*Input: Lista de bits
*Output: Nenhum
*Pre-condiçao: Lista existente
*Pós-condiçao: ponteiros apontando pra NULL
*/
void listabits_limpa(ListaBits* lista);

/*
*Input: -Lista de bits
        -Celula de bit
*Output: Nenhum
*Pre-condiçao: Lista existente
*Pós-condiçao: Celula inserida
*/
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

/*
*Input: -Lista de bits com todos os caminhos
        -Lista a ser inrerido 7 bits
*Output: Nenhum
*Pre-condiçao: Listas existentes
*Pós-condiçao: 7 primeiros bits retirados da lista geral e inseridos na lista nova_arv
*/
void listabits_pega_sete_primeiros(ListaBits* lista_geral, ListaBits* lista_nova);

/*
*Input: -Lista de bits
*Output: inteiro
*Pre-condiçao: Lista existente
*Pós-condiçao: Tamanho da lista retornado
*/
int listabits_tamanho(ListaBits* lista);

/*
*Input: -Lista de bits
*Output: Nenhum
*Pre-condiçao: Lista existente
*Pós-condiçao: 0's insereridos na lista até ter ela ter tamanho 8
*/
void listabits_completa_com_zeros(ListaBits* lista);

/*
*Input: -Lista de bits
        -index do bit procurado
*Output: inteiro (Bit procurado)
*Pre-condiçao: Lista existente e index no maximo no tamanho da lista
*Pós-condiçao: Bit do index procurado retornado
*/
int listabits_retorna_bit_por_index(ListaBits* lista, int index);

int listabits_retira_primeiro(ListaBits* lista);

#endif //TRAB2_LISTABITS_H