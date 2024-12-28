#include <stdio.h>

int main(){

    int size, indice = 0, NtemLetra = 0, resultado = 0, resposta = 0, n = 1, m = 1;
    scanf("%d", &size);
    
    char string[size];
    char letrasDiferentes[size];

    scanf("%s", string);
    
    for (int i = 0; i < size; i++){
        
        for (int j = indice; j >= 0; j--){ 

            if (string[i] == letrasDiferentes[j]){

                NtemLetra = 0;
                break;
            } else {
                NtemLetra = 1;
            }
        }

        if (NtemLetra == 1){

            letrasDiferentes[indice] = string[i];
            indice++;
        }
    }

    for (int i = 0; i <= indice; i++){

        for(int j = i + 1; j <= indice; j++) {

            for (int l = 0; l < size; l++) {

                if(letrasDiferentes[i] == string[l] && n == 1){

                    resultado++;
                    n = 0;
                    m = 1;
                }
                else if(letrasDiferentes[i] == string[l]){

                    resultado = 0;
                    break;
                }
                else if(letrasDiferentes[j] == string[l] && m == 1){

                    resultado++;
                    m = 0;
                    n = 1;
                }
                else if(letrasDiferentes[j] == string[l]){

                    resultado = 0;
                    break;
                }
            }

            if(resultado > resposta){
                resposta = resultado;
            }

                resultado = 0;
                m = n = 1;
        }
        
    }

    if(resposta == 1)
    printf("0");
    else
    printf("%d", resposta);
    return 0;
}