#include <stdio.h>

int main(){

    int n, k, i, max = 0;
    scanf("%d", &n);
    int freq[100]={0};
    int arr[n];

    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &k);
    int brr[k];

    for (i = 0; i < k; i++){

        scanf("%d", &brr[i]);
        if(brr[i] > max){
            max = brr[i];
        }
    }

    for (i = 0; i < k; i++){

        ++freq[max - brr[i]];

        if (i < n){
            --freq[max - arr[i]];
        }
    }
 
    for (i = 99; i >= 0; i--){

        if (freq[i] != 0){

            int valor = max - i; 
            printf("%d ", valor);
        }
        
    }
    
    return 0;
}