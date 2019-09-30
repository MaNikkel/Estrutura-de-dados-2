#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int busca1(int ini, int fim, int menor, int *v){
    if(fim < ini){
        return menor;
    } else {
        if(*(v+ini) < menor){
            return busca1(++ini, fim, *(v+ini), v);
        } else {
            return busca1(++ini, fim, menor, v);
        }
    }

}

int busca2(int ini, int fim, int menor, int *v){
    if(ini > fim){
        return menor;
    }

    int meio = (ini+fim)/2;

    if(*(v+meio) < menor){
        menor = *(v+meio);
    }
    //verifica primeira metade do vetor
    int men = busca2(ini, meio-1, menor, v);
    //verifica segunda metade do vetor
    return busca2(meio+1, fim, men, v);
}



int main() {
    int vetor[TAM];
    int i;
    for(i = 0; i < TAM; i++) {
        vetor[i] = rand();
        printf("%d\n", vetor[i]);
    }

    i = busca2(0, TAM-1, vetor[0],vetor);
    printf("menor: %d\n", i);
    return 0;
}