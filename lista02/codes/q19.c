#include <stdio.h>

int main(){

	int begin = 0, end = 0;
	float average = 0;
	float sum = 0;

	printf("Digite o começo da faixa: ");
	scanf("%d", &begin);
	printf("Digite o final da faixa: ");
	scanf("%d", &end);

	average = begin - end;
	average *= (average < 0)? -1 : 1;
	average++;
	sum = (average*(begin + end))/2;
	average = sum/average;

	printf("A média aritmética entre os números da faixa escolhida é: %.2f\n",average);

	return 0;
}
