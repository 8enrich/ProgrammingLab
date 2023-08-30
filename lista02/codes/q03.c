#include <stdio.h>

int factorial(unsigned int n){
	if(!n)
		return 1;
	return n * factorial(n-1);
}
int main(){
	unsigned int f = 0;

	printf("Digite um número para saber seu fatorial: ");
	scanf("%d",&f);

	printf("O fatorial de %d é %d\n",f,factorial(f));
}

