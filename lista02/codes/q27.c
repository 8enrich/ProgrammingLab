#include <stdio.h>

int main(){

	int num = 0;
	int bigger = 0, lower = 0;

	while(1){
		printf("Digite um número inteiro(ou um par negativo para sair): ");
		scanf("%d", &num);

		if(!(bigger) & !(lower)){
			bigger = num;
			lower = num;
		}

		if(num > bigger)
			bigger = num;

		if(num < lower)
			lower = num;
		
		if(!(num % 2) & num < 0)
			break;

		printf("O produto do maior pelo menor número apresentado é: %.2f\n", (float)bigger/lower);

	}

	return 0;
}
