#include <stdio.h>

int square(int, int, int);

int main(){

	int num = 0;
	int i = 0;
	int value = 0;

	printf("Digite um valor inteiro: ");
	scanf("%d",&num);

	num = num * num;
	num = square(i,value,num);

	printf("O módulo do valor digitado é: %d\n",num);

	return 0;
}

int square(int i, int value, int num){
	while(num){
		for(i; value < num;){
			i++;
			value = i*i;
		}
		return i;
	}
	return num;
}
