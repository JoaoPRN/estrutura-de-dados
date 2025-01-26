#ifndef __QUEUE_H_
#define __QUEUE_H_

typedef struct Node{
    int valor;
    struct Node* proximo;
} Node;

typedef struct Queue{
    Node* inicio;
    Node* fim;
    int quantidade;
} Queue;



Node* cria_no(int valor);

Queue* cria_fila();

void enqueue(Queue* fila, int valor);
void imprime_fila(Queue* fila);
int dequeue(Queue* fila);
void free_fila(Queue* fila);

#endif