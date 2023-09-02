#include <stdio.h>

int main(){

	int begin = 0, end = 0;
	int sum = 0;
	int i = 0;

	printf("Digite o começo da faixa: ");
	scanf("%d", &begin);
	printf("Digite o final da faixa: ");
	scanf("%d", &end);

	i = begin;
	while(1){

		if(!(i % 2))
			sum += i;

		if(begin < end){
			i++;
			if(i > end)
				break;
		}
		else{
			i--;
			if(i < end)
				break;
		}
	}
	printf("O somatório dos números pares na faixa escolhida é: %d\n",sum);
	
	return 0;
}
