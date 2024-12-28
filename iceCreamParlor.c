#include<stdio.h>

int main(){

    int t, m, n, i, j, k;

    scanf("%d", &t);

    for (i = 0; i < t; i++){

        scanf("%d", &m);
        scanf("%d", &n);

        int cost[n];

        for (j = 0; j < n; j++){

            scanf("%d", &cost[j]);
        }

        for (j = 0; j < n; j++){

            for (k = j + 1; k < n; k++){

                if (cost[j] + cost[k] == m){

                    printf("%d %d\n", j + 1, k + 1);
                }
                
            }
        }
    }

    return 0;
}