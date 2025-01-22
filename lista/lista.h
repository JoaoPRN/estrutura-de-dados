#ifndef __LISTA_H__
#define __LISTA_H__


typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct Lista{
    No* inicio;
    int quantidade;
} Lista;


Lista* cria_lista(void);

No* cria_no(int numero);

void add(Lista*, int valor);

void append(Lista*, int valor);

void imprime_lista(Lista* lista);
#endif