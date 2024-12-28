#include<stdio.h>

int main(){

    int n, i, key, minimo, maximo, freq = 0;
    scanf("%d", &n);

    int lista[n];

    for (i = 0; i < n; i++){

        scanf("%d", &lista[i]);

    }

    scanf("%d", &key);
    
    for (i = 0; i < n; i++){

        if (lista[i] == key){
            freq++;
            maximo = i;
            if (freq == 1) minimo = i;
        }
        
    }

    if (freq != 0)
    printf("%d %d %d", minimo, maximo, freq);
    else
    printf("-1 -1 0");
    return 0;
}