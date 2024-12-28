#include <stdio.h>
#include <string.h>

int main(){

    int m, n, i, j, k, encontrou = 0;

    scanf("%d %d\n", &m, &n);

    char magazine[m][6];
    char note[6];

    for (i = 0; i < m; i++){

        scanf("%s", magazine[i]);
    }

    for (i = 0; i < n; i++){

        scanf("%s", note);

        if (i != encontrou && encontrou > 0){
            break;
        }

        for (j = 0; j < m; j++){

            if (strcmp(note, magazine[j]) == 0){

                magazine[j][0] = '-';
                encontrou++;
                break;
            }

        }
    }

    if(encontrou == n){
        printf("Yes");
    } else printf("No");

    return 0;
}