#include  <stdio.h>

#define BITS 8
#define MASK 1

int main(){

	unsigned char x = 0;
	unsigned char y = 0;
	unsigned char bit = 0;

	printf("Digite o valor de x: ");
	scanf("%hhu", &x);

	while(y < 5){
		printf("Digite um numero maior ou igual a 5 para o valor de y: ");
		scanf("%hhu", &y);
		
		if(y < 5)
			puts("Numero invalido!");
	}

	for(int i = 0; i < BITS; i++){
		bit = (x >> i) & MASK;
		printf("Com o bit escondido temos: %hhu\n",bit & ((i < 4)? y - (i + 1): y + (i - 3)));
	}
	return 0;
}
