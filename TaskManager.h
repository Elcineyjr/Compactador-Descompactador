#ifndef TRAB2_TASKMANAGER_H
#define TRAB2_TASKMANAGER_H

/*
*Input: -Arquivo
*Output: ponteiro pro primeiro indice de um vetor
*Pre-condiçao: Arquivo aberto e vetor existente
*Pos-condiçao: arquivo lido e frequencia dos caracteres inseridos no respectivos indice no vetor
*/
void gera_vetor_ascii_frequencia(FILE* arquivo, int* vetor);

void vetor_imprime(int* vetor);

#endif //TRAB2_TASKMANAGER_H
