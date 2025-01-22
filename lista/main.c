#include <stdio.h>
#include "lista.h"


int main(){

    Lista* lista = cria_lista();

    add(lista, 2);
    add(lista, 3);
    add(lista, 4);
    add(lista, 5);

    imprime_lista(lista);
}