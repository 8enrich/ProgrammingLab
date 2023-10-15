#include <stdio.h>

#define SIZE 10

unsigned long strlen_h(const char *str);

int main(){

	char string[SIZE];

	printf("Digite uma palavara: ");
	scanf("%10[^\n]", string);

	printf("Essa palavra possui %lu caracteres\n", strlen_h(string));

	return 0;
}

unsigned long strlen_h(const char *str){
	unsigned long i;
	for(i = 0; *(str + i) != '\0'; i++);
	return i;
}
