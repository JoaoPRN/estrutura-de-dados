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

void deleteNode(Lista* lista, int posicao){

    Node* no_atual = lista->inicio;

    if (posicao == 0){

        Node* no_aux = lista->inicio;
        lista->inicio = no_atual->proximo;
        free(no_atual);
        return;
    }

    Node* no_anterior = NULL;

    for(int i = 0; i < posicao; i++){

        no_anterior = no_atual;
        no_atual = no_atual->proximo;
    }

    no_anterior->proximo = no_atual->proximo;
    free(no_atual);
}

void freeLista(Lista* lista){

    Node* no_atual = lista->inicio;

    while(no_atual != NULL){
        lista->inicio = lista->inicio->proximo;
        free(no_atual);
        no_atual = lista->inicio;
    }

    free(lista);
}

void imprime_lista(Lista* lista){

    Node* no_atual = lista->inicio;
    while(no_atual != NULL){

        printf("%d ", no_atual->valor);
        no_atual = no_atual->proximo;
    }
}

int main(){ 

    Lista* lista = cria_lista();

    int quantidade, posicao;
    scanf("%d", &quantidade);

    for(int i = quantidade; i > 0; i--){
        int valor;
        scanf("%d", &valor);
        append(lista, valor);

    }
    scanf("%d", &posicao);
    deleteNode(lista, posicao);
    imprime_lista(lista);
    freeLista(lista);
    return 0;
}