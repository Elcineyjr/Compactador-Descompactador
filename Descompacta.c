#include <stdio.h>
#include <stdlib.h>
#include "Descompacta.h"


Arv* arv_desserializa(FILE* arquivo_compactado) {
    char* c = (char*)malloc(sizeof(char));
    *c = fgetc(arquivo_compactado);

    Arv* a = NULL;
    if (*c == '0') {
        Arv* esquerda = arv_desserializa(arquivo_compactado);
        Arv* direita = arv_desserializa(arquivo_compactado);

        a = arv_cria_no_comum(0, esquerda, direita);
        free(c);
        return a;
    }
    if (*c == '1') {
        *c = fgetc(arquivo_compactado);
        a = arv_cria(*c, 0, NULL, NULL);
        free(c);
        return a;
    }
    free(c);
    return a;
}


//transforma um caracter dado em uma sequencia de bits e insere na lista
void transforma_char_em_bits(ListaBits* lista, char c){
    // i = 6 pois o primeiro bit sempre é 0
    for(int i = 6; i >= 0; i--){
        CelulaBit* celula;
        if ((c >> i) & 0x01){
            celula = listabits_cria_celula(1);
        }else{
            celula = listabits_cria_celula(0);
        }
        listabits_insere_celula(lista, celula);
    }
}


//le um caracter do arquivo, transforma em binario e insere na lita de bits
void gera_listabits_com_caminhos_originais(FILE* arquivo_compactado, ListaBits* lista_original){
    ListaBits* lista_temporaria = listabits_cria();
    
    //aloca espaço pra um caracter e entao le o primeiro do arquivo
    unsigned char* c = (unsigned char*)malloc(sizeof(char));
    *c = fgetc(arquivo_compactado);
    
    while(*c != EOF){ //EOF = End Of File, lendo assim todos caracteres do arquivo
        listabits_limpa(lista_temporaria);
        transforma_char_em_bits(lista_temporaria, *c);
        listabits_insere_lista_no_final(lista_original, lista_temporaria);
        
        *c = fgetc(arquivo_compactado);
        if(*c == 255)
            break;
    }
    free(c);
    free(lista_temporaria);
}  


//Navega na arvore otima conforme a lista de caminhos e entao imprime o caracter original
void gera_caracteres_originais(FILE* arquivo_descompactado, Arv* arvore_otima, ListaBits* lista_caminhos){
    if(arv_get_id(arvore_otima) == 1){
        fprintf(arquivo_descompactado, "%c",arv_get_char(arvore_otima));
        return;
    }
    if(!listabits_vazia(lista_caminhos)){
        int direcao = listabits_retira_primeiro(lista_caminhos);
        if(direcao){
            gera_caracteres_originais(arquivo_descompactado, arv_retorna_dir(arvore_otima), lista_caminhos);
        }else{
            gera_caracteres_originais(arquivo_descompactado, arv_retorna_esq(arvore_otima), lista_caminhos);
        }
    }else{
        return;
    }
    
} 


//gera todos os caracteres do arquivo original 
void gera_arquivo_original(FILE* arquivo_descompactado, Arv* arvore_otima, ListaBits* lista_caminhos){
    while (!listabits_vazia(lista_caminhos)){
        gera_caracteres_originais(arquivo_descompactado, arvore_otima, lista_caminhos);
    }
    free(lista_caminhos);
}


//Funçao que descompacta o arquivo compactado
void descompacta_arquivo(){
    FILE* arquivo_compactado = fopen("arquivoCompactado.txt", "r");
    Arv* arvore_otima;
    ListaBits* lista_caminhos_originais; 
    
    
    
    //le a arvore serializada no arquivo compactado e gera a arvore otima para manipulaçao
    arvore_otima = arv_desserializa(arquivo_compactado);
    
    //inicializa lista que guardara os caminhos dos caracteres originais
    lista_caminhos_originais = listabits_cria();
    
    //le o arquivo compactado e insere o caminho de todos os caracteres na lista
    gera_listabits_com_caminhos_originais(arquivo_compactado, lista_caminhos_originais);
    
    //fecha o arquivo compactado após ser lido 
    fclose(arquivo_compactado);
    
    //abre o arquivo que sera uma copia do original
    FILE* arquivo_descompactado = fopen("arquivoDescompactado.txt", "w"); 
    
    //imprime todos os caracteres do arquivo original
    gera_arquivo_original(arquivo_descompactado, arvore_otima, lista_caminhos_originais);
    
    //fecha o arquivo_descompactado
    fclose(arquivo_descompactado); 
    
    arv_libera(arvore_otima);
    /****************TERMINAR ESSA FUNÇAO************************/
}