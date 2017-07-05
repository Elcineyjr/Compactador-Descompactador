#ifndef TRAB2_ARVORE_H
#define TRAB2_ARVORE_H

typedef struct arvore Arv;


/*
*
*Esse arquivo só foi copiado de um exercicio da patricia
*Nao serao usadas todas as funçoes que estão aqui
*
*/


//Cria uma árvore vazia
Arv* arv_criavazia (void);

//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (char c, int peso, Arv* e, Arv* d);

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a);

//retorna true se a árvore estiver vazia e false
//caso contrário
int arv_vazia (Arv* a);

//indica a ocorrência (1) ou não (0) do caracter c
int arv_pertence (Arv* a, char c);

//imprime as informações dos nós da árvore
void arv_imprime (Arv* a);

//retorna o pai de um dado no
Arv* arv_pai (Arv* a, char c);

//retorna a quantidade de folhas de uma arvore binaria
int folhas (Arv* a);

//retorna o numero de ocorrencias de um dado caracter na arvore
int ocorrencias (Arv* a, char c);

//retorna o campo informacao de um dado no
char info (Arv* a);

int arv_get_peso(Arv* arvore);

char arv_get_char(Arv* arvore);

#endif //TRAB2_ARVORE_H
