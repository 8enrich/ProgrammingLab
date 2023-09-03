#include <stdio.h>

int main(){
	
	unsigned long long int sum = 0;
	unsigned long long int num = 1;

	for(int i = 0; i < 64; i++){
		num *= 2;
		sum += num;
	}
	
	printf("O somatório da quantidade de grãos de trigo é: %llu\n",sum);
	return 0;
}
