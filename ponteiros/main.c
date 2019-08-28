#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void alter(int *p1, int *p2){
    int aux;
    aux = *p1;
    *p1 = *p2;
    *p2 = aux;
}



int main() {
    int a, b;
    a = rand();
    b = rand();

    printf("a = %d", a);
    printf("\n");
    printf("b = %d", b);
    printf("\n");
    alter(&a, &b);
    printf("\n");
    printf("\n");
    printf("a = %d", a);
    printf("\n");
    printf("b = %d", b);
    printf("\n");
    return 0;
}