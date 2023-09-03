#include <stdio.h>

int main(){

	int begin = 0, end = 0;
	int i = 0;
	int quantity = 0;

	printf("Digite o começo da faixa: ");
	scanf("%d", &begin);
	printf("Digite o final da faixa: ");
	scanf("%d", &end);

	i = (begin < end)? begin : end;
	for(i;((i <= end) * (begin < end) + (i <= begin) * (end < begin));i++)
		if(!(i % 3))
			quantity++;
	
	printf("A quantidade de múltiplos de 3 na faixa escolhida é: %d\n",quantity);

	return 0;
}
