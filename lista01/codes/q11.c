#include <stdio.h>

int main(){

	float quotation = 0;
	float value = 0;
	int num = 1;

	while(num){
		printf("Digite a cotação do dólar: ");
		scanf("%f",&quotation);
		if(quotation > 0){
			num = 0;
		}
		else{
			puts("Cotação inválida.");
		}
	}
	num = 1;
	while(num){
		printf("Digite o valor em reais que você deseja converter: ");
		scanf("%f",&value);
		if(value > 0){
			num = 0;
		}
		else{
			puts("Valor inválido.");
		}
	}

	printf("O valor digitado corresponde a %.2f dólares\n",value/quotation);

	return 0;
}
