#include <stdio.h>

int main(){

	int begin = 0;
	int end = 0;
	int i = 0;
	
	printf("Digite o começo da faixa: ");
	scanf("%d", &begin);
	printf("Digite o fim da faixa: ");
	scanf("%d", &end);

	i = begin;
	while(1){
		if(!(i % 4))
			printf("%d**2 = %d\n",i, i*i);
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

	return 0;
}
