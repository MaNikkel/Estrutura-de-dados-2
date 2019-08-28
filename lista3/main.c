#include <stdio.h>
#include <stdlib.h>

#define TAM 1000

typedef struct node{
    int data;
    struct node *next;
}node;

int main() {
    node *initial = NULL;
    node *current = NULL;
    initial = (node *) malloc(sizeof(node));
    current = initial;
    int i;
    for(i = 0; i < TAM; i++){
        current->data = i;
        current->next = (node *) malloc(sizeof(node));
        current = current->next;
    }

    current = initial;

    for(i = 0; i < TAM; i++){
        printf("%d \n", current->data);
        current = current->next;
    }

    return 0;
}