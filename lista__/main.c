#include <stdio.h>
#include <stdlib.h>

typedef struct node_data {
    int data;
    struct node_data *next;
} node;

node *initial;
node *nextNode;

void insert(){
    printf("insira um inteiro: ");
    printf("\n");
    scanf("%d", &nextNode->data);
}

void list(){
    node *aux;
    aux = initial;
    while(aux->next != NULL){
        printf("%d", aux->data);
        printf(" --> ");
        aux = aux->next;
    }
    printf("NULL");
    printf("\n");
}

void remove_node(){
    int value;
    node *aux;
    node *remNode;
    aux = initial;
    printf("indique o valor a ser removido: ");
    scanf("%d", &value);
    while(aux->next != NULL){
        if(value == aux->next->data){
            remNode = aux->next;
            aux->next = remNode->next;
            printf("\n\n");
            printf("nó removido!");
            printf("\n\n");
            break;
        }
        aux = aux->next;
    }


}

void menu(){
    int op = 0;
    while(op != 4){
        printf("--lita encadeada--");
        printf("\n");
        printf("1 - inserir");
        printf("\n");
        printf("2 - listar");
        printf("\n");
        printf("3 - remover");
        printf("\n");
        printf("4 - sair");
        printf("\n");
        scanf("%d", &op);
        switch (op){
            case 1:
                insert();
                nextNode->next = (node *) malloc(sizeof(node));
                nextNode = nextNode->next;
                break;
            case 2:
                nextNode->next = NULL;
                list();
                break;
            case 3:
                remove_node();
                break;
        }
    }

}

int main() {
    initial = (node *) malloc(sizeof(node));
    nextNode = initial;
    if(initial == NULL){
        exit(1);
    }
    menu();
    return 0;
}