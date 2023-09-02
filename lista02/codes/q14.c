#include <stdio.h>

int main(){

	int begin = 0, end = 0;
	int i = 0;
	int quantity = 0;

	printf("Digite o começo da faixa: ");
	scanf("%d", &begin);
	printf("Digite o final da faixa: ");
	scanf("%d", &end);

	i = begin;
	while(1){

		if(!(i % 3))
			quantity++;

		if(begin < end){
			i++;
			if(i > end)
				break;
		}
		else{
			i--;
			if(i < begin)
				break;
		}
	}
	printf("A quantidade de múltiplos de 3 na faixa escolhida é: %d\n",quantity);

	return 0;
}
