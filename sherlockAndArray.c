#include <stdio.h>

int main(){

    int t, n, k, i, j, l;

    scanf("%d", &t);

    for (i = 0; i < t; i++){

        int somaEsq = 0, somaDir=0, resultado = 0;

        scanf("%d", &n);
        int lista[n];

        for (j = 0; j < n; j++){

            scanf("%d", &lista[j]);

        }

        for (j = 1; j < n; j++){
            somaDir += lista[j];
        }

        for (j = 0; j < n; j++){

            if  (somaDir == somaEsq){

                resultado = 1;
                break;

            } else {

                somaEsq += lista[j];
                somaDir -= lista[j+1];
            }
        }

    if (resultado == 1)
        printf("YES\n");
    else
        printf("NO\n");
      
    }   
  
    return 0;
}