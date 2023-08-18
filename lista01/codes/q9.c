#include <stdio.h>

int main(){

	int value = 0;

	printf("Digite um valor inteiro: ");
	scanf("%d",&value);

	printf("O sucessor do valor digitado é: %d\n",value+1);
	printf("O antecessor do valor digitado é: %d\n",value-1);

	return 0;
}
