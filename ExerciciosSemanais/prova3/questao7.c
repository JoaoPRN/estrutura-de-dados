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
	printf("%s, %s\n", pt->sobrenome, pt->nome);
}

void print_list(Lista* list){
	No* aux = list->inicio;
	Pretendente* pt = NULL;

	while(aux != NULL){
		pt = aux->pretendente;
		print_pretendente(pt);
		aux = aux->proximo;
    }
}

int ordenar(Pretendente* pt1, Pretendente* pt2){

    if (abs(pt1->altura - 180) == abs(pt2->altura - 180)){

        if (pt1->peso == pt2->peso){

            if (strcmp(pt1->sobrenome, pt2->sobrenome) == 0){

                return strcmp(pt1->nome, pt2->nome);

            };	

            return strcmp(pt1->sobrenome, pt2->sobrenome);	
        }

        else if (pt1->peso > 75 && pt2->peso > 75){

            return pt1->peso > pt2->peso;
        }

        else if (pt1->peso <= 75 && pt2->peso > 75){

            return 0;
        }

        else if (pt1->peso > 75 && pt2->peso <= 75){

            return 1;
        }

        return abs(pt1->peso-75) > abs(pt2->peso-75);
    }

    return abs(pt1->altura - 180) > abs(pt2->altura - 180);
}


void bubble_sort(Lista* lt){

	No* p_aux = NULL;
	Pretendente* p_st = NULL;
	int result;

	for(int i = 0; i < lt->tamanho-1; i++){
		p_aux = lt->inicio;

		for(int j = 0; j < lt->tamanho-1-i; j++){

			result = ordenar(p_aux->pretendente, p_aux->proximo->pretendente);

			if(result > 0){
				p_st = p_aux->pretendente; 
				p_aux->pretendente = p_aux->proximo->pretendente;
				p_aux->proximo->pretendente = p_st;
			}

			p_aux = p_aux->proximo;

		}
	}

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

    bubble_sort(lista);

    print_list(lista);

    return 0;

}