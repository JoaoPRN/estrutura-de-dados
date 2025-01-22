#include<stdio.h>
#include<math.h>

int caminho[10000]; 
int count = 0; 

int transformation(int a, int b) {
    if (a < 0 && a > b) return 0;

    if (a == b) {
        caminho[count++] = b;
        return 1;
    }

   
    if (transformation(a * 2, b) || transformation(a * 10 + 1, b)) {
        caminho[count++] = a;
        return 1;
    }

    return 0;
}


int main(){

    int a, b;
    scanf("%d %d", &a, &b);

    if (transformation(a, b)) {
        printf("YES\n");
        printf("%d\n", count);
        for (int i = count - 1; i >= 0; i--) { 
            printf("%d ", caminho[i]);
        }
        printf("\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
