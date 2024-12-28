#include<stdio.h>
#include<string.h>


int main()
{   
    int t;
    scanf("%d", &t);

    for( int i = 1; i < t + 1; i++){

        int n, j, resultado = 0;

        scanf("%d", &n);
        char matriz[2][n + 1];

        scanf("%s", matriz[0]);
        scanf("%s", matriz[1]);

        for (j = 0; j < n; j++){

            if(matriz[0][j] == '1' && matriz[1][j] == '1'){
                break;
            }
            if( j == n - 1){
                resultado = 1;
            }
        }

        if (resultado == 1){
            printf("YES\n");
        }else printf("NO\n");
    }


    return 0;
}