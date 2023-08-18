#include <stdio.h>

int main(){
	
	int value = 0;

	printf("Digite um valor inteiro decimal:");
	scanf("%d",&value);

	printf("O valor digitado em hexadecimal é: %x\n",value);
	printf("O valor digitado em octal é: %o\n",value);

	return 0;
}
