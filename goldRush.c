#include<stdio.h>

int division(int a, int b){

    
}

int main()
{   
    int t;
    scanf("%d", &t);

    for( int i = 1; i < t + 1; i++){

        int n, m, resultado = 0;

        scanf("%d %d", &n, &m);


        n -= m;
        
        if (n >= (m / 2)){

            resultado = 1;
        }
        
        if (resultado == 1){
            printf("YES\n");
        }else printf("NO\n");
    }


    return 0;
}