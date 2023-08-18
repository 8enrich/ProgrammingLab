#include <stdio.h>

int main(){

	int num1 = 0;
	int num2 = 0;
	int value = 0;

	printf("Digite o primeiro número: ");
	scanf("%d",&num1);
	while(!num2){
		printf("Digite o segundo número: ");
		scanf("%d",&num2);
		value = num2;
		while(!value){
			puts("Impossível dividir por 0");
			value = 1;
		}
	}

	while(!(num1%num2)*value){
		printf("%d é múltiplo de %d\n",num1,num2);
		value = 0;
	}
	while(value){
		printf("%d não é múltiplo de %d\n",num1,num2);
		value = 0;
	}
	
	return 0;
}
