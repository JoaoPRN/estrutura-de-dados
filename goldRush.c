#include<stdio.h>

void division(int n, int m, int *resultado){
    
    if (n > m){

        int pilhaMaior = (n * 2) / 3;
        int pilhaMenor = n / 3;
        // printf("n: %d\n", n);
        // printf("m: %d\n", m);
        // printf("pilhaMaior: %d\n", pilhaMaior);
        // printf("pilhaMenor: %d\n", pilhaMenor);

        if (pilhaMaior + pilhaMenor != n){
            *resultado = 0; // não é possivel
            return;
        }

        if (pilhaMaior == m || pilhaMenor == m){
            *resultado = 1; //é possível
            return;
        } 

        division(pilhaMaior, m, resultado);
        division(pilhaMenor, m, resultado);
    }

    if (n == m){
        *resultado = 1; //é possível
        return;
    }
}

int main(){   
    int t;
    scanf("%d", &t);

    for( int i = 1; i < t + 1; i++){

        int n, m, resultado = 0;

        scanf("%d %d", &n, &m);

        division(n, m, &resultado);
        
        if (resultado == 1){
            printf("YES\n");
        } else printf("NO\n");
    }

    return 0;
}