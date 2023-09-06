#include <stdio.h>

int bigger_num(int x, int y){
	return (y > x) * y + (y <= x) * x;
}

int smaller_num(int x, int y){
	return (y < x) * y + (y >= x) * x;
}
int main(){

	int num = 0;
	int bigger = 0, lower = 0;
	int i = 0;

	while(1){
		printf("Digite um número inteiro(ou um par negativo para sair): ");
		scanf("%d", &num);

		if(!(num % 2) & num < 0)
                        break;

		if(!(i)){
			bigger = num;
			lower = num;
			i++;
		}

		bigger = bigger_num(num, bigger);

		lower = smaller_num(num, lower);

		printf("O produto de %d por %d é: %d\n", bigger, lower, bigger * lower);

	}

	return 0;
}
