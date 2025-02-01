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

void retornaEstados(Lista* lista, int k, int valorPreferido){
    Node* noK = lista->inicio;
    for (int i = 0; i < k; i++){
        noK = noK->proximo;
    }
    int valork = noK->valor;

    if(valorPreferido < valork){
        printf("NO");
    }

    if (valorPreferido > valork){
        printf("YES");
    }

    if (valorPreferido == valork){
        printf("MAYBE");
    }

}

void ordenar(Lista* lista){
    if (lista->quantidade >= 2){
        
        int contador = -1;
        int limite = lista->quantidade;

        for (int j = 0; j <= limite - contador; j++){

            Node* no_atual = lista->inicio;

            for (int i = 0;no_atual->proximo != NULL && i < lista->quantidade; i++){

                Node* no_proximo = no_atual->proximo; 

                if (no_proximo != NULL){

                    if (no_atual->valor < no_proximo->valor){
                        int aux = no_atual->valor;
                        no_atual->valor =  no_proximo->valor;
                        no_proximo->valor = aux;
                    }

                    no_atual = no_proximo;
                } 
            }

            contador++;
        }

    }
}

int main(){ 

    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++){

        int n, f, k, cuboPreferido;
        scanf("%d %d %d", &n, &f, &k);

        Lista* lista = cria_lista();

        for(int j = 0; j < n;j++){
            int valor;
            scanf("%d", &valor);
            if (j == f - 1){

                cuboPreferido = valor;
            }
            append(lista, valor);
        } 

        ordenar(lista);
        retornaEstados(lista, k, cuboPreferido);
    }

    return 0;
}