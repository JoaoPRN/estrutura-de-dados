#include <stdio.h>

int main(){

    int i, j;
    char s[101]={0};

    scanf("%s", s);

    for (i = 0; i < 100; i+=2){

        for (j = i + 2; i < 100; j+=2){

            if (s[j] == '\0'){
                break;
            }

            if (s[i] > s[j]){

                int valor = s[i];
                s[i] = s[j];
                s[j] = valor;
            } 
        } 
    }

    printf("%s\n",s);


    return 0;
}