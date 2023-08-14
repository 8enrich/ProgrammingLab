#include <stdio.h>

int main(){
	float value = 0;

	printf("Digite um valor real: ");
	scanf("%f",&value);
	printf("O valor digitado com apenas uma casa decimal é: %.1f\n",value);

	return 0;
}
