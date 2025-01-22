#include <stdio.h>

int main(){

    int n, d, m, i, j, resultado = 0, soma = 0;
    scanf("%d", &n);

    int lista[n];

    for (i = 0; i < n; i++){

        scanf("%d", &lista[i]);
    }

    scanf("%d %d", &d, &m);

    for (i = 0; i < n; i++){

        soma += lista[i];

        for (j = i + 1; j <= m - 1 + i && j < n; j++){

            soma += lista[j];

        }

        if(soma == d){

            resultado++;
            soma = 0;
        }
        else soma = 0;
    }


    printf("%d", resultado);
    return 0;
}