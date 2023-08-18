#include <stdio.h>

int main(){

	float celsius = 0;
	float fahrenheit = 0;

	printf("Digite uma temperatura em Celsius: ");
	scanf("%f",&celsius);

	fahrenheit = (9 * celsius + 160)/5;

	printf("A temperatura digita em Fahrenheit é: %.2f\n",fahrenheit);

	return 0;
}
