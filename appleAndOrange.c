#include <stdio.h>

int main(){

    int s, t, a, b, m, n;
    int contadorMacas = 0, contadorLaranja = 0;
    scanf("%d %d", &s, &t);
    scanf("%d %d", &a, &b);
    scanf("%d %d", &m, &n);

    int macas[m];
    int laranjas[n]; 

    for (int i = 0; i < m; i++){
        scanf("%d", &macas[i]);
        macas[i] += a;
        
        if (macas[i] >= s && macas[i] <= t){
            contadorMacas++;
        }
    }

    for (int i = 0; i < n; i++){
        scanf("%d", &laranjas[i]);
        laranjas[i] += b;

        if (laranjas[i] <= t && laranjas[i] >= s){
            contadorLaranja++;
        }
    }
   
    printf("%d\n%d\n", contadorMacas, contadorLaranja);
    return 0;
}
