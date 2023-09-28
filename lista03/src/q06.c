#include <stdio.h>


#define SIZE 20

int main(){

	char str[SIZE];
	int size = SIZE;

	printf("Digite uma string: ");
	scanf("%20[^\n]", str);

	for(int i = 1; i <= SIZE; i++)
		printf("%c", str[SIZE - i]);
	puts("");
	return 0;
}
