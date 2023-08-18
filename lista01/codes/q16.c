#include <stdio.h>

int main(){

	float value = 0;
	float hours = 0;
	int discount = 0;
	float salary = 0;

	printf("Digite o valor da hora aula: ");
	scanf("%f",&value);
	printf("Digite a quantidade de horas trabalhadas: ");
	scanf("%f",&hours);
	printf("Digite o percentual de desconto do INSS: ");
	scanf("%d",&discount);

	salary = value * hours;

	printf("O sálario bruto é de: %.2f\n",salary);

	salary -= salary * (float)discount/100;

	printf("O salário líquido é de: %.2f\n",salary);

	return 0;
}
