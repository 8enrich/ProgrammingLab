#include <stdio.h>
#include <math.h>

int main(){
	
	float x1 = 0;
	float y1 = 0;
	float x2 = 0;
	float y2 = 0;
	float distance = 0;

	printf("Digite o x1: ");
	scanf("%f",&x1);
	printf("Digite o y1: ");
	scanf("%f",&y1);
	printf("Digite o x2: ");
	scanf("%f",&x2);
	printf("Digite o y2: ");
	scanf("%f",&y2);

	distance = sqrt(pow(x2 - x1, 2)+pow(y2 - y1, 2));

	printf("A distância entre um ponto e outro é de %.2f\n",distance);

	return 0;
}
