#include <stdio.h>

int somaDado(int n, int soma){

    if (soma > n) {
        return 0; 
    }

    if (soma == n){

        return 1;
    }

    int total = 0;

    if (soma < n){

        for (int i = 1; i <= 6; i++) {
            int retorno = somaDado(n, soma + i);
            if (retorno == 0) break;

            total += retorno; 
        }
    }

    return total;
}

int main(){

    int n;

    scanf("%d", &n);

    int contador = somaDado(n, 0);
  
    printf("%d", contador);

    return 0;
}