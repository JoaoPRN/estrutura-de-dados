#include <stdio.h>

int main(){

    int t, n, k, i, j, l, trocas = 0;

    scanf("%d", &t);

    for (i = 0; i < t; i++){

        scanf("%d", &n);
        k = (n + 1)/ 2;
        int lista[n];

        for (j = 0; j < n; j++){

            scanf("%d", &lista[j]);

        }

        for (j = 0; j < n && trocas < 3; j++){

            for (l = j + 1; l < n - k && trocas < 3; l++){

                if (lista[j] > lista[l]){

                    int valor = lista[j];
                    lista[j] = lista[l];
                    lista[l] = valor;
                    trocas++;
                }

            }

        }

        for (j = n - k; j < n && trocas < 3; j++){

            for (l = j + 1; l < n && trocas < 3; l++){

                if (lista[j] > lista[l]){

                    int valor = lista[j];
                    lista[j] = lista[l];
                    lista[l] = valor;
                    trocas++;
                }

            }

        }

        printf("%s", lista);
    }   
  
// colocar o maior no meio
    return 0;
}