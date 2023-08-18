#include <stdio.h>

int main(){

	int num = 0;
	int value = 1;

	printf("Digite um número: ");
	scanf("%d",&num);

	while(!(num%2)*value){
		printf("O número digitado é par\n");
		value = 0;
	}
	while(value){
		printf("O número digitado é ímpar\n");
		value = 0;
	}

	return 0;
}
