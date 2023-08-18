#include <stdio.h>
#include <string.h>

int main(){

	float height = 0;
	float weight = 0;
	int value = 1;
	char gender[10];
	
	while(value){
		printf("Digite a sua altura em metros: ");
		scanf("%f",&height);
		if(height > 0){
			value = 0;
		}
		else{
			puts("Altura inválida.");
		}
	}
	value = 1;

	while(value){
		printf("Digite seu sexo: ");
		scanf("%s",gender);

		if(!(strcmp(gender, "masculino"))){
			weight = 72.7 * height - 58; //Esses números são referentes ao cálculo do peso dos homens
			value = 0;
		}
		else if(!(strcmp(gender, "feminino"))){
			weight = 62.1 * height - 44.7; //Esses números são referentes ao cálculo do peso das mulheres
			value = 0;
		}
		else{
			puts("Sexo inválido, tente novamente.");
		}
	}
	
	printf("O seu peso ideal é: %.2f\n",weight);

	return 0;
}
