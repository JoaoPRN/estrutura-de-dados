#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node* proximo;
} Node;

typedef struct Lista{
    Node* inicio;
    int quantidade;
} Lista;

Node* cria_no(int valor){

    Node* no = (Node*) malloc(sizeof(Node));
    no->valor = valor;
    no->proximo=NULL;
    return no;
}

Lista* cria_lista(){

    Lista* lista = (Lista*) malloc(sizeof(Lista));
    lista->inicio=NULL;
    lista->quantidade=0;
    return lista;
}

void append(Lista* lista, int valor){

    Node* no = cria_no(valor);
    if(lista->quantidade==0){

        lista->inicio = no;
    } else {
        Node* prox_no = lista->inicio;

        while(prox_no->proximo != NULL){
            prox_no = prox_no->proximo;
        }
        prox_no->proximo = no;
    }
    lista->quantidade++;
}

void reverterLista(Lista* lista){

    Node* anterior = NULL;
    Node* atual = lista->inicio;
    Node* proximo;

    while(atual != NULL){

        proximo = atual->proximo;
        atual->proximo = anterior;

        anterior = atual;
        atual = proximo;
    }

    lista->inicio = anterior;
}

void imprime_lista(Lista* lista){

    Node* no_atual = lista->inicio;
    while(no_atual != NULL){

        printf("%d ", no_atual->valor);
        no_atual = no_atual->proximo;
    }
}

int main(){ 

    int t, j;
    scanf("%d", &t);

    for (j = 0; j < t; j++){

        Lista* lista = cria_lista();

        int quantidade;
        scanf("%d", &quantidade);

        for(int i = quantidade; i > 0; i--){

            int valor;
            scanf("%d", &valor);
            append(lista, valor);

        }

        reverterLista(lista);
        imprime_lista(lista);
    }

    return 0;
}