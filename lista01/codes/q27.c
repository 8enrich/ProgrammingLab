#include <stdio.h>
#include <math.h>

int main(){

	float num = 0;
	float geometric = 1;
	float arithmetic = 0;

	for(int i = 1; i <= 3; i++){
		printf("Digite o %dº número: ",i);
		scanf("%f",&num);

		arithmetic += num;
		geometric *= num;
	}
	
	arithmetic /= 3;
	geometric = pow(geometric, (float)1/3);

	printf("A média aritmética dos números escolhidos é: %.2f\n",arithmetic);
	printf("A média geométrica dos números escolhidos é: %.2f\n",geometric);

	return 0;
}
