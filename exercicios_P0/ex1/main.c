/* 1)Apresente um procedimento que recebe um ponteiro de ponteiro para um nó
 * de uma struct  (a mesma da questão anterior).
 * Sua função deve criar 3 variáveis ponteiros e fazer com que cada
 * uma delas aponte para um campo da struct dada.
 * Apresente um diagrama ilustrando o mapa de memória constanto todas as
 * variáveis envolvidas.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int inteiro;
    char caractere;
    float flutante;
    struct no *prox;
}No;

void exercicio1(No **p){
    char *c = &((*p)->caractere);
    int *i = &((*p)->inteiro);
    float *f = &((*p)->flutante);

    printf("\n-------------------------\n\n");
    printf("Caractere: %c\n", (*c));
    printf("Inteiro: %d\n", (*i));
    printf("Flutuante: %f\n", (*f));
    printf("\n-------------------------\n\n");
}

int main() {
    No *ponteiro = (No *) malloc(sizeof(No));
    ponteiro->caractere = 'a';
    ponteiro->inteiro = 1;
    ponteiro->flutante = 1.2;
    exercicio1(&ponteiro);
    return 0;
}