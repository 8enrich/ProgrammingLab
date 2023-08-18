#include <stdio.h>

int main(){
	
	float radius = 0;
	float pi = 3.14159;

	printf("Digite o raio da circunferência: ");
	scanf("%f",&radius);

	printf("O diâmetro da circunferência de raio %.2f é: %.2f\n",radius,radius*radius);
	printf("O valor da circunferência de raio %.2f é: %.2f\n",radius,2*pi*radius);
	printf("A área da circunferência de raio %.2f é: %.2f\n",radius,pi*radius*radius);

	return 0;
}
