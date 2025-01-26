#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct Status{
    int dado;
    int estado;
}Status;

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

Status* pop(Pilha* pilha){

    Status* status = (Status*) malloc(sizeof(Status));

    if (pilha->quantidade != 0){

        No* no_atual = pilha->topo;
        No* no_seguinte = pilha->topo->proximo;
        status->dado = no_atual->valor;
        status->estado = TRUE;
        no_atual->proximo=NULL;
        pilha->topo = no_seguinte;
    } else {
        status->estado = FALSE;
    }
    pilha->quantidade--;
    return status;
}

int main()
{
    char nome[] = "(";
    int i;
    Pilha* pilha = create_pilha();

    for(i = 0; nome[i] != '\0'; i++){

        char caractere = nome[i];

        if (caractere == '{' || caractere == '[' || caractere == '(' ){
                push(pilha, caractere);
            }

        if ((peek(pilha) == '{' && caractere == '}') || (peek(pilha) == '[' && caractere == ']') || (peek(pilha) == '(' && caractere == ')')){
            pop(pilha);
        }
    }

    if (pilha->topo==NULL){
        printf("DEu certo");
    }else{
        printf("ERRO");
    }

return 0;
}
