#include <stdio.h>

int main(){

	int num = 0;
	int algarism = 0;
	int seven = 0;
	char character = '\0';
	
	printf("Digite um número: ");
	scanf("%d", &num);

	while(num){
		algarism = num % 10;
		if(algarism == 7)
			seven += 1;
		num /= 10;
	}

	if(seven != 1)
		character = 's';

	printf("Há %d sete%c nesse número\n",seven, character);

	return 0;
}
