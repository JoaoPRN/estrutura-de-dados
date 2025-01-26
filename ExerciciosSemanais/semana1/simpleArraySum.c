#include <stdio.h>

int main(){

    int quantidade;
    int soma = 0;
    scanf("%d", &quantidade);
    int vetor[quantidade];

    for(int i = 0; i < quantidade;i++){

        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }
    
    printf("%d\n", soma);
    return 0;
}
