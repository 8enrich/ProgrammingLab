#include <stdio.h>

int main(){

	int num = 0;
	int reverse = 0;

	while(!num){
		printf("Digite um número de 5 dígitos: ");
		scanf("%d", &num);

		if(num < 10000 | num > 99999){
			printf("Número inválido!\n");
			num = 0;
		}
	}

	for(int i = num; i > 0;){
		reverse = reverse * 10 + i % 10;
		i = i / 10;
	}
	(num == reverse)? puts("É palíndromo"): puts("Não é palíndromo");

	return 0;
}
