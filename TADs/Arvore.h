#ifndef TRAB2_ARVORE_H
#define TRAB2_ARVORE_H

typedef struct arvore Arv;

/*
*Input: Nenhum
*Output: Arvore vazia
*Pre-condiçao: Nenhuma
*Pos-condiçao: Arvore criada e vazia
*/
Arv* arv_criavazia (void);

/*
*Input: Arvore
*Output: inteiro(true or false)
*Pre-condiçao: Arvore existente
*Pos-condiçao: Nenhuma
*/
int arv_vazia(Arv* arvore);

/*Cria um nó que contem uma arvore 
*Input: -char
        -peso
        -arvore da esquerda
        -arvore da direita
*Output: Arvore
*Pre-condiçao: Nenhuma
*Pos-condiçao: Arvore criada
*/
Arv* arv_cria (char c, int peso, Arv* e, Arv* d);

/*Cria um nó comum, sem caracter
*Input: -peso
        -arvore da esquerda
        -arvore da direita
*Output: Arvore
*Pre-condiçao: Nenhuma
*Pos-condiçao: Arvore criada
*/
Arv* arv_cria_no_comum(int peso, Arv* e, Arv* d);

/*
*Input: Arvore
*Output: Nenhum
*Pre-condiçao: Nenhuma
*Pos-condiçao: Memoria liberada
*/
void arv_libera (Arv* a);

/*
*Input: arvore
*Output: peso da arvore
*Pre-condiçao: Arvore existente
*Pos-condiçao: Peso retornado
*/
int arv_get_peso(Arv* arvore);

/*
*Input: Arvore
*Output: caracter da arvore
*Pre-condiçao: Arvore existente
*Pos-condiçao: caracter retornado
*/
char arv_get_char(Arv* arvore);

/*
*Input: Arvore
*Output: Nenhum
*Pre-condiçao: Nenhuma
*Pos-condiçao: Arvore impressa
*/
void arv_imprime(Arv* arvore);

/*
*Input: Arvore
*Output: Nenhum
*Pre-condiçao: arvore existente
*Pos-condiçao: Imprime toda a arvore de maneira compacta para ser usada no arquivo de saida
*/
void arv_serializa(Arv* arvore, FILE* arquivo);

/*
*Input: Arvore
*Output: Arvore
*Pre-condiçao: arvore existente
*Pós-condiçao: arvore da esquerda retornada
*/
Arv* arv_retorna_esq(Arv* arvore);

/*
*Input: Arvore
*Output: Arvore
*Pre-condiçao: arvore existente
*Pós-condiçao: arvore da direita retornada
*/
Arv* arv_retorna_dir(Arv* arvore);
#endif //TRAB2_ARVORE_H