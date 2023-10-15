#include <stdio.h>

int main(){

	int num1, num2;
	int *pv1 = &num1;
	int *pv2 = &num2;

	printf("Digite o primeiro número: ");
	scanf("%d", &num1);
	printf("Digite o segundo número: ");
	scanf("%d", &num2);

	*pv1 = *pv1 ^ *pv2;
	*pv2 = *pv1 ^ *pv2;
	*pv1 = *pv1 ^ *pv2;

	printf("O valor do primeiro número é %d\nO valor do segundo número é %d\n", num1, num2);

	return 0;
}
