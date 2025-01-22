#include <stdio.h>

int main(){

    int matriz[6][6];
    int max = -9*7, soma = 0;
    
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){

            scanf("%d", &matriz[i][j]);
      
        }
    }

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
             
            if (i + 2 < 6 && j + 2 < 6) {
                
                soma = matriz[i][j]+matriz[i][j+1]+matriz[i][j+2]+matriz[i+1][j+1]+matriz[i+2][j]+matriz[i+2][j+1]+matriz[i+2][j+2];
            }
    
            if (soma > max){

                max = soma;
            }
        }
    }

    printf("%d", max);

    return 0;
}