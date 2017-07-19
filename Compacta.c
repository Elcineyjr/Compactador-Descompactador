#include <stdio.h>
#include <stdlib.h>
#include "Compacta.h"
#define tamanho_ASCII 255


//Procura o caminho do caracter na arvore e insere na lista 
int procura_caminho(unsigned char c, Arv* arvore, ListaBits* lista){
    if(arvore){
        if(arv_get_char(arvore) == c){
            return 1;
        }
    }else{
        return 0;
    }

    if(procura_caminho(c, arv_retorna_esq(arvore) , lista)){
        listabits_insere_inicio(lista, 0);
        return 1;
    }

    if(procura_caminho(c, arv_retorna_dir(arvore) , lista)){
        listabits_insere_inicio(lista, 1);
        return 1;
    }

    return 0;
}


//Le cada caracter do arquivo e acha seu caminho na arvore
void gera_lista_final_de_caminhos(FILE* arquivo, Arv* arvore_otima, ListaBits* lista_final){
    ListaBits* lista_temporaria = listabits_cria();
    
    //aloca espaço pra um caracter e entao le o primeiro do arquivo
    unsigned char* a = (unsigned char*)malloc(sizeof(char));
    *a = fgetc(arquivo);

    while(*a != EOF) //EOF = End Of File, lendo assim todos caracteres do arquivo
    {
        listabits_limpa(lista_temporaria);
        procura_caminho(*a, arvore_otima, lista_temporaria);
        listabits_insere_lista_no_final(lista_final, lista_temporaria);
        *a = fgetc(arquivo);
        if(*a == 255)
            break;
    }
    free(a);
    free(lista_temporaria);
}


void comprime_lista_caminhos(FILE* arquivo, ListaBits* lista_caminhos){
    int tamanho;
    
    while (!listabits_vazia(lista_caminhos)){
        ListaBits* lista_quebrada = listabits_cria();
        listabits_pega_sete_primeiros(lista_caminhos, lista_quebrada);
        listabits_insere_inicio(lista_quebrada, 0);
        tamanho = listabits_tamanho(lista_quebrada);
        if(tamanho < 8){
            listabits_completa_com_zeros(lista_quebrada);
        }
        
        bitmap bit = bitmapInit(8);
        //printf("Imprimindo os bits:");

        for(int i = 0; i < 8; i++){
            //printf("%d", listabits_retorna_bit_por_index(lista_quebrada, i));
            bitmapAppendLeastSignificantBit(&bit, listabits_retorna_bit_por_index(lista_quebrada, i));
        }
        unsigned char* novo_char = bitmapGetContents(bit);
        //printf("\nQue representa o char: %c\n", *novo_char);
        fprintf(arquivo, "%c", *novo_char);
        listabits_libera(lista_quebrada);
    }
    //free(lista_quebrada);
}


//Funçao que compacta o arquivo de entrada
void compacta_arquivo(FILE* arquivo_entrada){
    FILE* arquivo_saida = fopen("arquivoCompactado.txt", "w");
    int vetor[tamanho_ASCII];
    ListaArvore* lista_caracteres;
    ListaBits* lista_caminhos;
    Arv* arvore_otima;
    
    //le cada caracter do arquivo e incrementa sua frequencia no vetor
    gera_vetor_ascii_frequencia(arquivo_entrada, vetor);
    
    //gera uma lista com todos os caracteres do arquivo e ordena pelos seus respectivos pesos
    lista_caracteres = gera_lista_caractes(vetor, tamanho_ASCII);
    
    //itera a lista de caracteres de acordo com o algoritmo de huffman
    arvore_otima = gera_arvore_huffman(lista_caracteres);
    
    //imprime a arvore otima de huffman no arquivo de modo compactado
    arv_serializa(arvore_otima, arquivo_saida);
    fprintf(arquivo_saida, "\n");
    
    //faz o ponteiro apontar novamente para o ininio do arquivo
    rewind(arquivo_entrada);
    
    //inicializa a lista que guardará os caminhos de cada caracter
    lista_caminhos = listabits_cria();
    
    //le cada caracter do arquivo e insere seu caminho no final da lista de caminhos
    gera_lista_final_de_caminhos(arquivo_entrada, arvore_otima, lista_caminhos);
    
    //quebra a lista de caminhos e transforma em caracteres 
    comprime_lista_caminhos(arquivo_saida, lista_caminhos);
    
    //********** TERMINAR FUNÇAO ***************
}