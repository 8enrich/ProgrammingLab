#include <stdio.h>

int main(){

	float num = 0;
	float sum = 0;
	float product = 1;
	float difference = 0;
	float quotient = 1;
	int remainder = 1;

	for(int i = 1; i <= 2; i++){
		printf("Digite o %d° número: ",i);
		scanf("%f",&num);
		sum += num;
		product *= num;
		if(i == 1){
			difference = num;
			quotient = num;
			remainder = (int)num;
		}
		else{
			difference -= num;
			quotient /= num;
			remainder %= (int)num;
		}
	}
	printf("A soma dos números escolhidos é: %.2f\n",sum);
	printf("O produto dos números escolhidos é: %.2f\n",product);
	printf("A diferença dos números escolhidos é: %.2f\n",difference);
	printf("O quociente dos números escolhidos é: %.2f\n",quotient);
	printf("O resto da divisão dos números escolhidos é %d\n",remainder);

	return 0;
}
