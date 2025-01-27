#include <stdio.h>

#define TRUE 1
#define FALSE 0

int isFila(int* dadosEntrada, int* dadosSaida, int n){

    for(int i = 0; i < n; i++){

        if (dadosEntrada[i] != dadosSaida[i]){

            return FALSE;
        }
    }

    return TRUE;
}

int isPilha(int* dadosEntrada, int* dadosSaida, int n){

    for(int i = 0; i < n; i++){

        if (dadosEntrada[i] != dadosSaida[n - 1 - i]){

            return FALSE;
        }
    }

    return TRUE;
}

int main(){

    int t, i;

    scanf("%d", &t);

    for (i = 0; i < t; i++){

        int n, j;
        scanf("%d", &n);

        int dadosEntrada[n];
        int dadosSaida[n];

        for(j = 0; j < n; j++){

            scanf("%d", &dadosEntrada[j]);
        }

        for(j = 0; j < n; j++){

            scanf("%d", &dadosSaida[j]);   
        }

        int isfila = isFila(dadosEntrada, dadosSaida, n);
        int ispilha = isPilha(dadosEntrada, dadosSaida, n);

        if (isfila == TRUE && ispilha== TRUE)
            printf("both\n");
        
        if (isfila == TRUE && ispilha== FALSE)
            printf("queue\n");
        
        if (isfila == FALSE && ispilha== TRUE)
            printf("stack\n");
        
        if (isfila == FALSE && ispilha== FALSE)
            printf("neither\n");
    }
}