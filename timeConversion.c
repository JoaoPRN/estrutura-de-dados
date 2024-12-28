#include <stdio.h>

int main(){

	char horario[10];
	scanf("%s", horario);

	int hh = (10 * (horario[0] - '0')) + (horario[1] - '0');
	char periodo = horario[8];

	if (periodo == 'P' && hh < 12){

		hh += 12;
	} 
	else if(periodo == 'A' && hh == 12){

		hh = 0;
	}
	horario[0] = (char)((hh / 10) + '0');
    horario[1] = (char)((hh % 10) + '0');
    horario[8] = '\0';

	printf("%s", horario);
	return 0;
}