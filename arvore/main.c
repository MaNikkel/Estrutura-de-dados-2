#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node;

void insert(Node **pRoot, int valueForKey){
    if(*pRoot == NULL){
        *pRoot=(Node *)malloc(sizeof (Node));
        (*pRoot)->left=NULL;
        (*pRoot)->right=NULL;
        (*pRoot)->key=valueForKey;
    } else {
        if (valueForKey < ((*pRoot)->key)) {
            insert(&((*pRoot)->left), valueForKey);
        } else {
            insert(&((*pRoot)->right), valueForKey);
        }
    }
}

Node* search(Node **pRoot, int searchedKey){
    if(*pRoot == NULL){
        return NULL;
    } else {
        if(searchedKey == ((*pRoot)->key)){
            return (*pRoot);
        } else if(searchedKey < ((*pRoot)->key)){
            search(&((*pRoot)->left), searchedKey);
        } else if(searchedKey > ((*pRoot)->key)) {
            return search(&((*pRoot)->right), searchedKey);
        }
    }
}

int main() {
    Node* pRoot = NULL;
    int keysArray[5] = {1, 4, 6, 23, 6};
    int i;
    for(i = 0; i < 5; i++){
        insert(&(pRoot), keysArray[i]);
    }

    Node* searched = search(&(pRoot), 4);
    if(searched != NULL)
        printf("elemento: %d\n", searched->key);
    else
        printf("elemento não encontrado", searched->key);
    return 0;
}