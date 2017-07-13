#ifndef TRAB2_ARVORE_H
#define TRAB2_ARVORE_H

typedef struct arvore Arv;

//Cria uma árvore vazia
Arv* arv_criavazia (void);

//cria uma árvore com a informação do nó raiz c, e
//com subárvore esquerda e e subárvore direita d
Arv* arv_cria (char c, int peso, Arv* e, Arv* d);

Arv* arv_cria_no_comum(int peso, Arv* e, Arv* d);

//libera o espaço de memória ocupado pela árvore a
Arv* arv_libera (Arv* a);

int arv_get_peso(Arv* arvore);

char arv_get_char(Arv* arvore);

void arv_imprime(Arv* arvore);

#endif //TRAB2_ARVORE_H
