#include <stdio.h>

int main(){

	int x = 0;
	int n = 0;

	printf("Digite um número: ");
	scanf("%d",&x);
	printf("Digite o valor do expoente: ");
	scanf("%d",&n);
	
	printf("%d * 2**%d = ",x,n);

	x = (x<<n);
	n = (1<<n);

	printf("%d\n",x);

	return 0;
}
