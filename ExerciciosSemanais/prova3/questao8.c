#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct Aluno {
	char nome[101];
    char sobrenome[101];
	char mencao[3];
} Aluno;

typedef struct No{
    Aluno* aluno;
    struct No* proximo;
} No;

typedef struct Lista{
	No* inicio;
	int tamanho;
} Lista;

Aluno* create_aluno(const char* nome, const char* sobrenome, const char* mencao){

    Aluno* aluno = (Aluno*) malloc(sizeof(Aluno));

    strcpy(aluno->nome, nome);
    strcpy(aluno->sobrenome, sobrenome);
    strcpy(aluno->mencao, mencao);

    return aluno;
}

No* create_no(Aluno* aluno){
    No* no = (No*) malloc(sizeof(No));
    no->aluno = aluno;
    no->proximo = NULL;
    return no;
}

Lista* create_lista(){

    Lista* lista = (Lista*) malloc(sizeof(Lista));

    lista->tamanho= 0;
    lista->inicio=NULL;
    return lista;
}

void print_aluno(Aluno* pt){
	printf("%s %s %s\n", pt->mencao, pt->nome, pt->sobrenome);
}

void print_list(Lista* list){
	No* aux = list->inicio;
	Aluno* pt = NULL;

	while(aux != NULL){
		pt = aux->aluno;
		print_aluno(pt);
		aux = aux->proximo;
    }
}

int ordenar(Aluno* pt1, Aluno* pt2){

    if (strcmp(pt1->mencao, pt2->mencao) == 0){

        if (strcmp(pt1->nome, pt2->nome) == 0){

            return strcmp(pt1->sobrenome, pt2->sobrenome);
        }

        return strcmp(pt1->nome, pt2->nome);
    }

    else if ((strcmp(pt1->mencao,"SS") == 0)
    || (strcmp(pt1->mencao,"MS") == 0 && strcmp(pt2->mencao, "SS") != 0)
    || (strcmp(pt1->mencao,"MM") == 0 && strcmp(pt2->mencao, "SS") != 0 && strcmp(pt2->mencao, "MS") != 0)
    || (strcmp(pt1->mencao,"MI") == 0 && strcmp(pt2->mencao, "SS") != 0 && strcmp(pt2->mencao, "MS") != 0 && strcmp(pt2->mencao, "MM") != 0)
    || (strcmp(pt1->mencao,"II") == 0 && strcmp(pt2->mencao, "SS") != 0 && strcmp(pt2->mencao, "MS") != 0 && strcmp(pt2->mencao, "MM") != 0 && strcmp(pt2->mencao, "MI") != 0)
    ){

        return 0;
    }

    return 1;
}


void bubble_sort(Lista* lt){

	No* p_aux = NULL;
	Aluno* p_st = NULL;
	int result;

	for(int i = 0; i < lt->tamanho-1; i++){
		p_aux = lt->inicio;

		for(int j = 0; j < lt->tamanho-1-i; j++){

			result = ordenar(p_aux->aluno, p_aux->proximo->aluno);

			if(result > 0){
				p_st = p_aux->aluno; 
				p_aux->aluno = p_aux->proximo->aluno;
				p_aux->proximo->aluno = p_st;
			}

			p_aux = p_aux->proximo;

		}
	}

}


void adicionar(Lista* lista, Aluno* aluno){
    No* no = create_no(aluno);

    no->proximo = lista->inicio;
    lista->inicio = no;
    lista->tamanho++;
}

int main(){

    int n;
    
    scanf("%d", &n);

    Lista* lista = create_lista();

    for(int i = 0; i < n; i++){

        char nome[101], sobrenome[101], mencao[3];
    
        scanf("%s %s %s", mencao, nome, sobrenome);
    
        Aluno* aluno =  create_aluno(nome, sobrenome, mencao);
        adicionar(lista, aluno);
    }

    bubble_sort(lista);

    print_list(lista);

    return 0;

}

