#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

No* cria_no(int numero){

    No* pt_no = (No*)  (sizeof(No));
    
    pt_no->valor=numero;
    pt_no->proximo=NULL;

    return pt_no;
}

Lista* cria_lista(void){

    Lista* lista = (Lista*) malloc(sizeof(Lista));

    lista->inicio=NULL;
    lista->quantidade=0;

    return lista;
}

void add(Lista* lista, int valor){

    No* pt_no = cria_no(valor);
    pt_no->proximo = lista->inicio;
    lista->inicio = pt_no;
    lista->quantidade++;
}

void append(Lista* lista, int valor){

    No* pt_no = cria_no(valor);

    if (lista->inicio == NULL){
        
        lista->inicio = pt_no;
    } else {

        No* no_atual = lista->inicio;
        while (no_atual->proximo != NULL){

            no_atual = no_atual->proximo;
        } 
        no_atual->proximo = pt_no;
    }
    lista->quantidade++;
}

void imprime_lista(Lista* lista){

    No* no_atual = lista->inicio;
    // for (int i = 0; i < lista->quantidade; i++){
            
    //     printf("%d\n", no_atual->valor);
    //     no_atual = no_atual->proximo;
    // } 

    while( no_atual != NULL){
        printf("%d\n", no_atual->valor);
        no_atual = no_atual->proximo;
    }
}


