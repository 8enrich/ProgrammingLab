#include <stdio.h>

int main(){

	int a = 0;
	int b = 0;

	printf("Digite o valor de A: ");
	scanf("%d",&a);
	printf("Digite o valor de B: ");
	scanf("%d",&b);

	a = a ^ b;
	b = a ^ b;
	a = a ^ b;

	printf("\nO novo valor de A é: %d\n",a);
	printf("O novo valor de B é: %d\n",b);

	return 0;
}
