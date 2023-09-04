#include <stdio.h>

int main(){

	int begin = 0;
	int end = 0;
	int i = 0;

	printf("Digite o começo da faixa: ");
	scanf("%d", &begin);
	printf("Digite o fim da faixa: ");
	scanf("%d", &end);

	i = (begin < end)? begin: end;
	for(i;((i <= end)* (begin < end) + (i <= begin)* (begin > end));i++){
		if(!(i % 4))
			printf("%d**2 = %d\n",i, i*i);
	}

	return 0;
}
