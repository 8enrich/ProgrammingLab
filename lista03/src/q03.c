#include <stdio.h>

#define SIZE 20

unsigned long strlen_h(const char *str);

int main(){

	char str[SIZE];

	printf("Digite uma string: ");
	scanf("%20[^\n]", str);

	printf("A string possui %lu caracteres\n", strlen_h(str));

	return 0;
}

unsigned long strlen_h(const char *str){
	unsigned long i;
	for(i = 0; str[i] != '\0'; i++);
	return i;
}
