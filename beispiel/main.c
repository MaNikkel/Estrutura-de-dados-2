#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    char data;
    struct No *next;
}node;



int main() {
    /*
     * Como regiões alocadas com malloc não tem nome, precisamos usar ponteiros.
     * Esse ponteiro representa toda a estrutura de dados pois, a partir dele,
     * acessamos o primeiro nó e, a partir dele, acessamos todos os demais por
     * meio do campo next
     */
    node *p = NULL;
    p = (node *) malloc(sizeof(node));
    /*
     * para acessarmos os campos da variável abaixo usamos seu nome, isto é,
     * myVar e o operador ponto, por exemplo: myVar.next = NULL
     */
    node myVar;
    if(p == NULL){
        exit(1);
    }
    /*
     * diferentemente da variável myVar, a variável p não é do tipo node, mas sim
     * um ponteiro para tal tipo. Nesses casos, para acessar um campo da região
     * alocada pelo mallox a partir de p usamos o operador seta "->" em vez do ponto
     */
    p->key = 10;
    /*
     * supondo que o malloc tenha retornado 0xa0, este será o centeúdo de p. Logo
     * no comando acima o sistema executará "0xa0->chave = 10"que significa que a
     * partir do byte cujo endereço é 0xa0 existe uma variável tipo node, nesse caso, uma
     * variável com 3 campos. O comando dado ordena que o valor 10 seja gravado em key
     */
    p->data ='m';
    p->next = NULL;

    p->next = (node *) malloc(sizeof(node));
    /*
     * com o malloc acima não mudamos o conteúdo de p, que continua sendo 0xa0. Ao
     * fazeros "p->next = malloc" queremos que a saída do malloc seja gravado no campo
     * next da região de memória apontada por p
     */
    if(p->next == NULL){
        exit(1);
    }
    /*
     * para atribuirmos valores aos campos do segundo nó alocado, precisamos do
     * ponteiro para este node, que está alocado em next do primeiro no
     */

    node *secondNode = p->next;
    secondNode->key = 11;       //p->next->key = 11;
    secondNode->data = 'n';     //p->next->data = 'n';
    secondNode->next = NULL;    //p->next->next = NULL;

    return 0;
}