#include <stdio.h>

int main(){

	int num1, num2;
	int *pv1 = &num1;
	int *pv2 = &num2;
	int result;

	printf("Digite o primeiro número: ");
	scanf("%d", &num1);
	printf("Digite o segundo número: ");
	scanf("%d", &num2);

	result = *pv1 + *pv2;

	printf("[%p] %d\n", &result, result);

	return 0;
}
