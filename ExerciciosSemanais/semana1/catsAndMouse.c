#include <stdio.h>
#include <stdlib.h>

int main(){

    int q, x, y, z;
    scanf("%d", &q);

    for (int i = 0; i < q; i++){

        scanf("%d %d %d", &x, &y, &z);

        if (abs(z - x) < abs(z - y)){

            printf("%s\n","Cat A");
        }
        else if (abs(z - x) > abs(z - y)) {

            printf("%s\n","Cat B");
        } else {

            printf("%s\n","Mouse C");
        }
    }

    return 0;
}