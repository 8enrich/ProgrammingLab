#include <stdio.h>

int main(){
	
	int value = 0;

	printf("Digite um valor inteiro: ");
	scanf("%d",&value);

	printf("O triplo do valor digitado é: %d\n",value*3);
	printf("O quadrado do valor digitado é: %d\n",value*value);
	printf("A metade do valor digitado é: %.2f\n",value/2.0);

	return 0;
}
