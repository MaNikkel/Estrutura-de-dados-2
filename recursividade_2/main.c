#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int search(int elem, int first, int last, int *array){
    if(first > last){
        printf("\n----------------\n");
        return NULL;
    }
    if(*(array) == elem){
        printf("\n----------------\nindex = %d", first);
        return *(array);
    }
    return search(elem, ++first, last, (array+1));//array+1 aponta para o próximo elemento
    //nesse return acontece o empilhamento
}

int search2(int elem, int first, int last, int *array){
    if(first > last){
        printf("\n----------------\n");
        return NULL;
    }

    int middle = (first+last)/2;

    if(*(array+middle) == elem){
        printf("\n----------------\nindex = %d", middle);
        return middle;
    }

    //pesquisa em toda a primeira metade,por empilhamento
    int ind = search2(elem, first, middle-1, array);
    if(!ind){
        //se não estiver na primeira metade, aí busca na segunda
        return search2(elem, middle+1, last, array);
    } else {
        return *(array+ind);
    }
}

int main() {
    int arr[SIZE];
    int i;
    for(i = 0;i < SIZE; i++){
        arr[i] = i;//rand() % SIZE;
        //printf("%d: %d\n", i, arr[i]);
    }
    int elem;
    printf("Entre com o número a ser encontrado: ");
    scanf("%d", &elem);

    int number = search2(elem, 0, SIZE, arr);//arr é o endereço para arr[0]
    if(number){
        printf("\nnúmero encontrado: %d\n\n", number);
    }else{
        printf("\nnúmero não encontrado\n\n");
    }
    return 0;
}