#include <stdio.h>
#include <string.h>

int main(){

	float height = 0, weight = 0;
	char gender[10];
	int value = 1;

	printf("Qual a sua altura: ");
	scanf("%f",&height);
	while (value){
		printf("Qual o seu sexo: ");
		scanf("%s",gender);

		if (!(strcmp(gender,"masculino"))){
			weight = 72.7 * height - 58; //Valores informados pela questão
			value = 0;
		}
		else if(!(strcmp(gender,"feminino"))){
			weight = 62.1 * height - 44.7; //Valores informados pela questão
			value = 0;
		}
		else{
			puts("Sexo inválido, tente novamente");
		}
	printf("O seu peso ideal é %.2f\n",weight);
	}

	return 0;
}
