#include <stdio.h>

int main(){

    int n, d, x, i;
    scanf("%d %d", &n, &d);

    int lista[n];

    for (i = 0; i < n; i++){

        x=(n + i - d)%n;
        scanf("%d", &lista[x]);
    }

     for(i = 0; i < n; i++)
    {
        printf("%d ", lista[i]);
    }
    return 0;
}