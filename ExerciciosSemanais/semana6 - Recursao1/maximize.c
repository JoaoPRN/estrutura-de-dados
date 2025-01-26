#include<stdio.h>

int greatestCommonDivisor(int a, int b){

    int result = ((a < b) ? a : b);

    while (result > 0){

        if (a % result == 0 && b % result == 0){
            break;
        }
        result--;
    }
    
    return result;
}

int main()
{   
    int t;
    scanf("%d", &t);

    for( int i = 1; i < t + 1; i++){

        int x, y, gcd = 0, maiorValor = 0, resultado = 0;
        {
            scanf("%d", &x);

            for(y=x - 1; y > 0; y--){

                gcd = greatestCommonDivisor(x, y);

                if(gcd + y >= maiorValor){
                    maiorValor = gcd + y;
                    resultado = y;
                }
            }
            printf("%d\n", resultado);
        }
    }


    return 0;
}