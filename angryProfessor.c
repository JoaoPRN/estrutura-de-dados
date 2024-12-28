#include <stdio.h>

int main(){

    int t, n, k, i, j, presentes = 0;

    scanf("%d", &t);

    for (i = 0; i < t; i++){

        scanf("%d %d", &n, &k);
        int lista[n];

        for (j = 0; j < n; j++){

            scanf("%d", &lista[j]);

            if (lista[j] <= 0){

                presentes++;
            }
        }

        if(presentes >= k)
            printf("NO\n");
        else printf("YES\n");
        presentes = 0;
    }   

    return 0;
}
