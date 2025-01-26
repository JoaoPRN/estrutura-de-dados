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

Node* inverterNo(Node* noInicial , Node* noSeguinte){

    Node* no_aux = noSeguinte->proximo; 
    noSeguinte->proximo = noInicial; 

    if(no_aux != NULL){
        no_aux = inverterNo(noSeguinte, no_aux);
    } else {
        return noSeguinte;
    }
    
    return no_aux;
}

void reverterLista(Lista* lista){

    if (lista->inicio->proximo != NULL){

        Node* no_inicial = lista->inicio;
        Node* no_aux = no_inicial->proximo;
        Node* no_seguinte = no_aux->proximo;
        no_aux->proximo = no_inicial;
        no_inicial->proximo = NULL;
        
        if(no_seguinte != NULL){

            no_seguinte = inverterNo(no_aux, no_seguinte);
        } 

        lista->inicio = no_seguinte;
    }

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