#include <stdio.h>

int main(){

    int n, k, i, j, resultado = 0;
    scanf("%d %d", &n, &k);

    int lista[n];
    
    for (i = 0; i < n; i++){

        scanf("%d", &lista[i]);
    }

    for (i = 0; i < n; i++){

        for (j = i + 1; j < n; j++){

            if ((lista[i] + lista[j]) % k == 0){

                resultado++;
            }   
        } 
    } 

    printf("%d", resultado);
    return 0;
}