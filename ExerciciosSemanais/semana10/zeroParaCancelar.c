#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct No{
    char valor;
    struct No* proximo;
}No;

typedef struct Pilha{
    int quantidade;
    No* topo;
}Pilha;

No* create_no(int valor){
    No* no = (No*) malloc(sizeof(No));
    no->valor = valor;
    no->proximo = NULL;
    return no;
}

Pilha* create_pilha(){
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    pilha->quantidade= 0;
    pilha->topo=NULL;
    return pilha;
}

void push(Pilha* pilha, int valor){
    No* no = create_no(valor);

    no->proximo = pilha->topo;
    pilha->topo = no;
    pilha->quantidade++;
}

int peek(Pilha* pilha){

    return pilha->topo->valor;
}

void pop(Pilha* pilha){

    if (pilha->quantidade > 0){

        No* no_atual = pilha->topo;
        No* no_seguinte = pilha->topo->proximo;
        
        
        no_atual->proximo=NULL;
        pilha->topo = no_seguinte;
    } 
    pilha->quantidade--;
}

int main()
{
    
    int n;
    scanf("%d", &n);
    int soma = 0;
    Pilha* pilha = create_pilha(); 
    for (int i=0; i<n;i++){

        int entrada;

        scanf("%d", &entrada);
        
        if(entrada != 0){
            push(pilha, entrada);
        } else {

            pop(pilha);
        }

    }
    
    No* no_atual = pilha->topo;

    for (int j = 0; j < pilha->quantidade;j++){
        soma += no_atual->valor;
        no_atual=no_atual->proximo;
    }
    printf("%d\n",soma);

return 0;
}
