#include "fila.h"
#include<stdio.h>
#include<stdlib.h>

Node* cria_no(int valor){

    Node* no = (Node*) malloc(sizeof(Node));
    no->proximo = NULL;
    no->valor = valor;
    return no;
}

Queue* cria_fila(){

    Queue* fila = (Queue*) malloc(sizeof(Queue));
    fila->fim=NULL;
    fila->inicio=NULL;
    fila->quantidade = 0;
    return fila;
}

void enqueue(Queue* fila, int valor){    

    Node* no = cria_no(valor);

    if (fila->fim != NULL){

        fila->fim->proximo = no;
    } else {

        fila->inicio = no;
    }

    fila->fim = no;
    fila->quantidade++;
}

int dequeue(Queue* fila){    

    if (fila->inicio == NULL){
        return 0;
    }

    Node* no = fila->inicio;
    int valor = no->valor;

    fila->inicio = fila->inicio->proximo;
    free(no);
    fila->quantidade--;

    return valor;
}


void free_fila(Queue* fila){

    Node* no_atual = fila->inicio;
    Node* no_aux;
    while(no_atual !=NULL){

        no_aux = no_atual;
        no_atual = no_atual->proximo;
        free(no_aux);
    } 

    free(fila);
}

void imprime_fila(Queue* fila){

    Node* no_atual = fila->inicio;

    while(no_atual !=NULL){

        printf("%d ", no_atual->valor);
        no_atual = no_atual->proximo;
    } 
    printf("\n");
    printf("Inicio: %d\n", fila->inicio->valor);
    printf("final: %d\n", fila->fim->valor);
}