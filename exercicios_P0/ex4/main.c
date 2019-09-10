/*
 * 4) Apresente um procedimento recursivo que recebe o endereço que aponta para o
 * campo auto-referenciado ("prox") da struct definida na questão 0 (note que o endereço
 * não aponta para o nó gtodo, só o campo.
 * Assuma que a lista tem pelo menos um nó).
 * Para cada nó, você deve imprimir tanto o endereço do campo auto-referenciado como seu conteúdo.
 * Comece imprimindo do último nó e termine no primeiro.
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct no {
    int inteiro;
    char caractere;
    float flutante;
    struct no *prox;
}No;

int exercicio4(No *p){
    int num;
    if(p->prox != NULL){
        num = exercicio4(p->prox);
        printf("%d\n", num);
    }
    return p->inteiro;


}

int main() {
    No *inicial;
    inicial = (No *) malloc(sizeof(No));
    inicial->prox = (No *) malloc(sizeof(No));
    No *proximo = NULL;
    proximo = inicial->prox;
    int i;
    for(i = 0; i < SIZE; i++){
        proximo->flutante = random();
        proximo->inteiro = i;
        proximo->caractere = 'a';
        proximo->prox = (No *) malloc(sizeof(No));
        proximo = proximo->prox;
    }
    proximo->prox = NULL;
    i = exercicio4(inicial);
    //printf("%d\n", i);
    return 0;
}