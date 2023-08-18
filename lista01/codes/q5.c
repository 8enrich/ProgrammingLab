#include <stdio.h>

int main(){

	float value = 0;
	float total = 0;
	int num = 1;

	while(num){
		printf("Digite o valor da conta: ");
		scanf("%f",&value);
		if(value > 0){
			num = 0;
		}
		else{
			puts("Valor da conta inválido.");
		}
	}
	total = value + value*10/100;

	printf("O valor total a ser pago é: %.2f\n",total);

	return 0;
}
