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
    search(elem, ++first, last, (array+1));
}


int main() {
    int arr[SIZE];
    int i;
    for(i = 0;i < SIZE; i++){
        arr[i] = rand() % SIZE;
        printf("%d: %d\n", i, arr[i]);
    }
    int number = search(123, 0, 1000, arr);
    if(number){
        printf("\nnúmero encontrado: %d\n\n", number);
    }else{
        printf("\nnúmero não encontrado\n\n");
    }
    return 0;
}