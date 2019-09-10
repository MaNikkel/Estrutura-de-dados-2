#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

typedef struct node_data {
    int data;
    int key;
    struct node_data *next;
} node;

node* search(node *p, int key){
    if(p == NULL){
        return NULL;
    }
    if(p->key == key){
        printf("achou!\n");
        return p;
    } else {
        printf("não achou\n");
        return  search(p->next, key);
    }
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

    node *searched;
    searched = search(initial, (10000-1));

    printf("\n\n-----------------------\n");
    printf("chave: %d\ndado: %d", searched->key, searched->data);
    printf("\n\n-----------------------\n");

    return 0;
}