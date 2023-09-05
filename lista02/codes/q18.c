#include <stdio.h>

int main(){
	
	unsigned long long int sum = 1;

	sum = (sum << 63);
	
	printf("O somatório da quantidade de grãos de trigo é: %llu\n",sum);
	return 0;
}
