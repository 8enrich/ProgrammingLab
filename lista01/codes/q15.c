#include <stdio.h>

int main(){

	int days = 0;
	float payment = 0;
	int extra = 100;

	printf("Digite a quantidade de dias trabalhados: ");
	scanf("%d",&days);

	if(days > 10 && days < 20){
		extra = 20;
	}
	else if(days > 20){
		extra = 30;
	}

	payment = 50.25 * days; //50.25 é o valor da diária do vendedor
	payment += payment * extra/100;
	payment -= payment * 10/100;

	printf("O valor líquido a ser recebido é de: %.2f\n",payment);

	return 0;
}
