
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int valor[2];
    struct Node* proximo;
} Node;

typedef struct Queue{
    Node* inicio;
    Node* fim;
    int quantidade;
} Queue;

Node* cria_no(int chegada, int saida){

    Node* no = (Node*) malloc(sizeof(Node));
    no->proximo = NULL;
    no->valor[0] = chegada;
    no->valor[1] = saida;
    return no;
}

Queue* cria_fila(){

    Queue* fila = (Queue*) malloc(sizeof(Queue));
    fila->fim=NULL;
    fila->inicio=NULL;
    fila->quantidade = 0;
    return fila;
}

void enqueue(Queue* fila, int chegada, int saida){    

    Node* no = cria_no(chegada, saida);

    if (fila->fim != NULL){

        fila->fim->proximo = no;
    } else {

        fila->inicio = no;
    }

    fila->fim = no;
    fila->quantidade++;
}

int* dequeue(Queue* fila){    

    if (fila->inicio == NULL){
        return 0;
    }

    Node* no = fila->inicio;
    int* valor = no->valor;

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

int main(){

    int t, i;

    scanf("%d", &t);
    for (i = 0; i < t; i++){
        int n, j;
        scanf("%d", &n);
        Queue* fila = cria_fila();

        for(j = 0; j < n; j++){

            int tempoChegada, tempoSaida;
            scanf("%d %d", &tempoChegada, &tempoSaida);
            enqueue(fila, tempoChegada, tempoSaida);
        }
        int tempoNecessario = 0;

        for(j = 0; j < n; j++){

            int tempoEntrada = fila->inicio->valor[0];
            int tempoSaida = fila->inicio->valor[1];

            if (tempoEntrada < tempoNecessario){

                tempoEntrada = tempoNecessario;
            }
            tempoNecessario = tempoEntrada + 1;

            if (tempoSaida >= tempoEntrada){
                printf("%d ", tempoEntrada);
            } else {
                tempoNecessario--;
                printf("0 ");
            }
            
            dequeue(fila);
        }
        printf("\n");
        free_fila(fila);
    }
    

    return 0;
}