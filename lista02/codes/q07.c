#include <stdio.h>

int main(){

	int num1 = 0;
	int num2 = 0;
	float result = 0;

	printf("Digite o dividendo: ");
	scanf("%d", &num1);

	while(!num2){
		printf("Digite o divisor: ");
		scanf("%d", &num2);

		if(!num2)
			puts("Impossível dividir por 0");
	}

	result = (float)num1/num2;
	printf("%d dividido por %d é igual a %.2f\n",num1,num2,result);

	return 0;
}
