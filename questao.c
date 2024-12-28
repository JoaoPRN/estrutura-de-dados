#include <stdio.h>
#include <math.h>

int main() {
    int size, contador = 0, somaBytes = 0, tempo = 0;
    int bytes;  

    scanf("%d", &size);
    getchar();
    printf("Data size of %d bytes:\n", size);

    while (scanf("%d", &bytes) == 1) {

        contador++;         
        somaBytes += bytes;         

        if (contador % 5 == 0 && somaBytes != 0) {
            
            double restante = (double)(size - somaBytes); 
            double taxa = (double) somaBytes / 5;   
            double resultado = restante / taxa;   
            tempo = (int) ceil(resultado); 

            size -= somaBytes;
            somaBytes = 0;
            printf("Time remaining: %d seconds\n", tempo);
        } 
        else if(contador % 5 == 0 && somaBytes == 0){
            printf("Time remaining: stalled\n");
        }
        

        if (somaBytes >= size) {
            printf("Total time: %d seconds\n", contador);
        }
    }

    return 0;
}
