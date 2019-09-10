/*
 * 2) Seja p o ponteiro para o primeiro nó de uma lista simplesmente encadeada.
 * Considerando que uma lista podem estar vazia ou pode ter elementos, apresente
 * uma definição recursiva para listas encadeadas considerando p como argumento de
 * entrada para eventuais algoritmos que explorem sua caracterização recursiva.
 *
 * 3) Com base na caracterização da questão 2, apresente um procedimento recursivo
 * que imprime todos os elementos de uma lista encadeada simples, do primeiro ao último.
 */


#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

typedef struct node_data {
    int data;
    int key;
    struct node_data *next;
} node;

void search(node *p){
    if(p == NULL){
        return;
    }
    printf("----------\nData: %d\nKey: %d\n----------\n\n", p->data, p->key);
    search(p->next);
}

int main() {
    node *initial;
    node *nextNode;
    initial = (node *) malloc(sizeof(node));
    nextNode = initial;
    int i;
    for(i = 0; i < SIZE; i++){
        nextNode->key = i;
        nextNode->data = random();
        nextNode->next = (node *) malloc(sizeof(node));
        nextNode = nextNode->next;
    }

    search(initial);
    return 0;
}