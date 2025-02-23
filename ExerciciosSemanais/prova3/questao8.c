#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Estudante {
	char nome[101];
    char sobrenome[101];
	char nota[3];
} Estudante;

typedef struct No{
    Estudante* estudante;
    struct No* proximo;
} No;

typedef struct Lista{
	No* inicio;
	int tamanho;
} Lista;

Estudante* cria_estudante(const char* nome, const char* sobrenome, const char* nota){

    Estudante* estudante = (Estudante*) malloc(sizeof(Estudante));

    strcpy(estudante->nome, nome);
    strcpy(estudante->sobrenome, sobrenome);
    strcpy(estudante->nota, nota);

    return estudante;
}

No* cria_no(Estudante* estudante){
    No* no = (No*) malloc(sizeof(No));
    no->estudante = estudante;
    no->proximo = NULL;
    return no;
}

Lista* cria_lista(){

    Lista* lista = (Lista*) malloc(sizeof(Lista));

    lista->tamanho= 0;
    lista->inicio=NULL;
    return lista;
}

void imprime_estudante(Estudante* pt){
	printf("%s %s %s\n", pt->nota, pt->nome, pt->sobrenome);
}

void imprime_lista(Lista* list){
	No* aux = list->inicio;
	Estudante* pt = NULL;

	while(aux != NULL){
		pt = aux->estudante;
		imprime_estudante(pt);
		aux = aux->proximo;
    }
}

void add(Lista* lista, Estudante* estudante){
    No* no = cria_no(estudante);

    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tamanho++;
}

int ordenar(Estudante* pt1, Estudante* pt2){

    if (strcmp(pt1->nota, pt2->nota) == 0){

        if (strcmp(pt1->nome, pt2->nome) == 0){

            return strcmp(pt1->sobrenome, pt2->sobrenome);
        }

        return strcmp(pt1->nome, pt2->nome);
    }

    if (strcmp(pt1->nota, "SS") == 0) {
        return 0;
    } 
    else if (strcmp(pt1->nota, "MS") == 0 && strcmp(pt2->nota, "SS") != 0) {
        return 0;
    } 
    else if (strcmp(pt1->nota, "MM") == 0 && strcmp(pt2->nota, "SS") != 0 && strcmp(pt2->nota, "MS") != 0) {
        return 0;
    } 
    else if (strcmp(pt1->nota, "MI") == 0 && strcmp(pt2->nota, "SS") != 0 && strcmp(pt2->nota, "MS") != 0 
    && strcmp(pt2->nota, "MM") != 0) {
        return 0;
    } 
    else if (strcmp(pt1->nota, "II") == 0 && strcmp(pt2->nota, "SS") != 0 && strcmp(pt2->nota, "MS") != 0 
    && strcmp(pt2->nota, "MM") != 0 && strcmp(pt2->nota, "MI") != 0) {
        return 0;
    }

    return 1;
}


void bubble_sort(Lista* lt){

	No* p_aux = NULL;
	Estudante* p_st = NULL;
	int result;

	for(int i = 0; i < lt->tamanho-1; i++){
		p_aux = lt->inicio;

		for(int j = 0; j < lt->tamanho-1-i; j++){

			result = ordenar(p_aux->estudante, p_aux->proximo->estudante);

			if(result > 0){
				p_st = p_aux->estudante; 
				p_aux->estudante = p_aux->proximo->estudante;
				p_aux->proximo->estudante = p_st;
			}

			p_aux = p_aux->proximo;

		}
	}

}


int main(){

    int n;
    
    scanf("%d", &n);

    Lista* lista = cria_lista();

    for(int i = 0; i < n; i++){

        char nome[101], sobrenome[101], nota[3];
    
        scanf("%s %s %s", nota, nome, sobrenome);
    
        Estudante* estudante =  cria_estudante(nome, sobrenome, nota);
        add(lista, estudante);
    }

    bubble_sort(lista);

    imprime_lista(lista);

    return 0;

}

