#include <stdio.h>

int main(){

	float bill = 0;

	printf("Digite o valor da conta: ");
	scanf("%f", &bill);

	bill = bill * 10/100 + bill;

	printf("O valor total a ser pago é R$%.2f\n",bill);

	return 0;
}
