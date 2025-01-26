#include "fila.h"
#include<stdio.h>

int main(){

    Queue* fila = cria_fila();
    enqueue(fila, 1);
    enqueue(fila, 2);
    enqueue(fila, 4);
    enqueue(fila, 3);
    enqueue(fila, 46);
    enqueue(fila, 7);

    int valor = dequeue(fila);
    printf("valor removido: %d\n", valor);
    imprime_fila(fila);

    free_fila(fila);
    return 0;
}