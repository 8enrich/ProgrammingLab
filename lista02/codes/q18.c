#include <stdio.h>

int main(){
	
	unsigned long long int sum = 0;
	unsigned long long int i = 0;

	for(i; i < 64; i++)
		sum += (2 << i);
	
	printf("O somatório da quantidade de grãos de trigo é: %llu\n",sum);
	return 0;
}
