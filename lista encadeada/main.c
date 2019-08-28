#include <stdio.h>
#include <stdlib.h>

typedef struct point {
    int x, y;
    struct point *next;
}t_point;

int main() {
    t_point *initial_point;
    t_point *next_point;
    int resp;

    initial_point = (t_point *) malloc(sizeof(t_point));
    if(initial_point == NULL){
        exit(1);
    }
    next_point = initial_point;
    while(1){
        printf("Digite o x: ");
        scanf("%d", &next_point->x);
        printf("Digite o y: ");
        scanf("%d", &next_point->y);
        printf("Deseja continuar?");
        scanf("%d", &resp);
        if(resp == 1) {
            next_point->next = (t_point *) malloc(sizeof(t_point));
            next_point = next_point->next;
        } else {
            break;
        }


    }
    next_point->next = NULL;
    next_point = initial_point;
    printf("\n");
    while (next_point->next != NULL){
        printf("x: %d, y: %d", next_point->x, next_point->y);
        next_point = next_point->next;
    }
    return 0;
}