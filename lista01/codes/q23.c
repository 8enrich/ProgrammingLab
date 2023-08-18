#include <stdio.h>

int main(){

	int num = 0;
	int value = 0;

	printf("Digite um número: ");
	scanf("%d",&num);

	if(num > 0){
		while(num){
			value *= 10;
			value += num%10;
			num /= 10;
		}
	printf("%d\n",value);
	}
	else{
		puts("0");
	}

	return 0;
}
