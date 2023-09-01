#include <stdio.h>

void value(float *price, float *first, int *rest){
	*rest = ((int)*price/3)* 2;
	*first = *price - *rest;
}

int main(){

	float price = 0;
	float first = 0;
	int rest = 0;

	printf("Digite o valor da mercadoria: ");
	scanf("%f", &price);

	value(&price, &first, &rest);

	printf("A entrada custa %.2f e cada prestação custa %d\n",first,rest/2);
	return 0;
}
