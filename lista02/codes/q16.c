#include <stdio.h>

int main(){

	int sum = 0;
	int num = 3;

	for(int i = 0; i < 200; i++){

		if((i < 100) && (!(i % 3))){
			sum += i;
		}
		else if((i >= 100) && (!(i % 5))){
			sum += i;
		}
		if(!((i + 1) % 100)){
			printf("O somatório dos números divisíveis por %d na faixa de %d à %d é igual a %d\n",num,i - 99,i + 1, sum);
			sum = 0;
			num = 5;
		}
			
	}

	return 0;
}
