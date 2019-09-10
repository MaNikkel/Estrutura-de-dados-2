/*
 * 0) Proponha uma struct auto-referenciada com três campos quaisquer.
 * Após isso apresente um procedimento que recebe um ponteiro p para essa
 * struct e imprime na tela o endereço do segundo campo da struct acessível
 * a partir de p.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int inteiro;
    char caractere;
    float flutante;
    struct no *prox;
}No;

void exercicio0(No *p){
    printf("%d", &(p->caractere));
}

int main() {
    No *ponteiro = (No *) malloc(sizeof(No));
    exercicio0(ponteiro);

    return 0;
}