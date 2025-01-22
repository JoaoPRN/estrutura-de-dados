#include <stdio.h>

int main(){

	int quantidade, positivos = 0, negativos = 0;
	scanf("%d", &quantidade);

	int vetor[quantidade];


	for(int i = 0; i < quantidade; i++){

		scanf("%d", &vetor[i]);

		if(vetor[i] > 0){
			positivos++;
		} 
		else if(vetor[i] < 0){
			negativos++;
		}
	}

	double razao_positivos =  (double) positivos/ (double) quantidade;
	double razao_negativos =  (double) negativos/ (double) quantidade;
	double razao_zeros =  (double) (quantidade - negativos - positivos)/ (double) quantidade;
	printf("%.6f\n%.6f\n%.6f\n", razao_positivos, razao_negativos, razao_zeros);
	

	return 0;
}