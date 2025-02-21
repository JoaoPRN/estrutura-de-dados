#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Pretendente {
	char nome[51];
    char sobrenome[51];
	int altura;
	int peso;
} Pretendente;

typedef struct No{
    Pretendente* pretendente;
    struct No* proximo;
} No;

typedef struct Lista{
	No* inicio;
	int tamanho;
} Lista;

Pretendente* create_pretendente(const char* nome, const char* sobrenome, const int altura, const int peso){

    Pretendente* pretendente = (Pretendente*) malloc(sizeof(Pretendente));

    strcpy(pretendente->nome, nome);
    strcpy(pretendente->sobrenome, sobrenome);
    pretendente->altura = altura;
    pretendente->peso = peso;

    return pretendente;
}

No* create_no(Pretendente* pretendente){
    No* no = (No*) malloc(sizeof(No));
    no->pretendente = pretendente;
    no->proximo = NULL;
    return no;
}

Lista* create_lista(){

    Lista* lista = (Lista*) malloc(sizeof(Lista));

    lista->tamanho= 0;
    lista->inicio=NULL;
    return lista;
}

void print_pretendente(Pretendente* pt){
	printf("%s, %s, %d, %d\n", pt->nome, pt->sobrenome, pt->altura, pt->peso);
}

void print_list(Lista* list){
	printf("List:\n");
	No* aux = list->inicio;
	Pretendente* pt = NULL;

	while(aux != NULL){
		pt = aux->pretendente;
		print_pretendente(pt);
		aux = aux->proximo;
    }
}


void bubble_sort(Lista* lt, int (*sort_key)(Pretendente* pt1, Pretendente* pt2) ){
	No* p_aux = NULL;
	Pretendente* p_st = NULL;
	int result;

	// if(is_empty(lt))
	// 	return;

	for(int i = 0; i < lt->tamanho-1; i++){
		p_aux = lt->inicio;

		for(int j = 0; j < lt->tamanho-1-i; j++){
			result = sort_key(p_aux->pretendente, p_aux->proximo->pretendente);

			if(result > 0){
				p_st = p_aux->pretendente; 
				p_aux->pretendente = p_aux->proximo->pretendente;
				p_aux->proximo->pretendente = p_st;
			}

			p_aux = p_aux->proximo;

		}
	}

}

int nome_key(Pretendente* pt1, Pretendente* pt2){
	return strcmp(pt1->nome, pt2->nome);	
}

int sobrenome_key(Pretendente* pt1, Pretendente* pt2){
	return strcmp(pt1->sobrenome, pt2->sobrenome);	
}

int altura_key(Pretendente* pt1, Pretendente* pt2){

	return abs(pt1->altura - 180) < abs(pt2->altura - 180);
}

int peso_key(Pretendente* pt1, Pretendente* pt2){
	return abs(pt1->peso - 75) < abs(pt2->peso - 75);
}

void adicionar(Lista* lista, Pretendente* pretendente){
    No* no = create_no(pretendente);

    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tamanho++;
}

int main(){

    int n;
    
    scanf("%d", &n);

    Lista* lista = create_lista();

    for(int i = 0; i < n; i++){

        char nome[51], sobrenome[51];
        int altura, peso;
    
        scanf("%s %s %d %d", nome, sobrenome, &altura, &peso);
    
        Pretendente* pretendente =  create_pretendente(nome, sobrenome, altura, peso);
        adicionar(lista, pretendente);
    }

    bubble_sort(lista, altura_key);
    bubble_sort(lista, peso_key);
    bubble_sort(lista, sobrenome_key);
    bubble_sort(lista, nome_key);

    print_list(lista);

    return 0;
}