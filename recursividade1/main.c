#include <stdio.h>
#include <stdlib.h>

int res = 0;
int counter = 1;
int factor = 0;

int factorial(int num){
    if(factor == 1)
        return num;
    num *= --factor;
    factorial(num);
}


int power(int base, int exp){
    switch (exp) {
        case 0:
            return 1;
        case 1:
            return base;
        default:
            if(counter < exp){
                if(counter == 1)
                    res = base*base;
                else
                    res = res*base;
                counter++;

                power(base, exp);
            }
            return res;
    }
}

int main() {
    int base, exp;
    printf("Digite um inteiro para a base: ");
    scanf("%d", &base);
    factor = base;
    printf("Digite um inteiro para o expoente: ");
    scanf("%d", &exp);
    printf("\no resultado de %d^%d: ", base, exp);
    power(base, exp);
    printf("%d\n\n", power(base, exp));
    printf("o fatorial de %d: ", base);
    printf("%d\n\n", factorial(base));
    printf("o fatorial de %d: ", exp);
    factor = exp;
    printf("%d\n", factorial(exp));
    return 0;
}