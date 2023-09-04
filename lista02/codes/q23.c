#include <stdio.h>

int main(){

	int num = 0;

	printf("Digite um número: ");
	scanf("%d", &num);

	printf("Se a gente pré-incrementar ele fica: %d\n", --num);
	num++;
	printf("Se a gente pós-incrementar ele fica: %d\n", num--);
	puts("É isso :)");

	return 0;
}
