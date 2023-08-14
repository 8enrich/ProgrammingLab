#include <stdio.h>

int main(){

	int x = 0;

	printf("Digite um valor inteiro: ");
	scanf("%d",&x);

	printf("O triplo do valor digitado é: %d\n",x*3);
	printf("O quadrado do valor digitado é: %d\n",x*x);
	printf("A metade do valor digitado é: %.2f\n",x/2.0);

	return 0;
}
