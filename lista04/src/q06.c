#include <stdio.h>

#define SIZE 10

char *strcpy_h(char*, const char*);

int main(){

	char string1[SIZE];
	char string2[SIZE];

	printf("Digite a string 1: ");
	scanf("%10[^\n]", string1);

	strcpy_h(string2, string1);

	printf("A string 2 contém o texto: %s\n", string2);

	return 0;
}

char *strcpy_h(char* source, const char *destination){
	for(int i = 0; *(destination + i) != '\0'; i++)
		*(source + i) = *(destination + i);
	return source;
}

