#include <stdio.h>

void trocarGarrafas(int *garrafasVazias, int *n){
    
    if (*garrafasVazias >= 3){

        *n += *garrafasVazias / 3;
        *garrafasVazias = (*garrafasVazias % 3) + (*garrafasVazias / 3);

        trocarGarrafas(garrafasVazias, n);
    }
    if (*garrafasVazias == 2){
    
        *garrafasVazias = 0;
        *n += 1;
    }
}

int main(){
    int garrafasVazias;
    while (scanf("%d", &garrafasVazias) == 1 && garrafasVazias != 0){   

        int n = 0;
        trocarGarrafas(&garrafasVazias, &n);
        printf("%d\n", n);
    }
    
    return 0;
}

