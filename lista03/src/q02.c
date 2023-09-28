#include <stdio.h>
#include <string.h>

#define SIZE 20
#define CHAR 3

int main(){

	char str[SIZE];
	char character;
	int count = 0;
	char plural[CHAR] = {0, 0,'\0'};

	printf("Digite uma string: ");
	scanf("%20[^\n]s", str);

	printf("Digite um caractere: ");
	scanf(" %c", &character);

	for(int i = 0; i < strlen(str); i++)
		if(str[i] == character)
			count++;
	if(count != 1)
		sprintf(plural ,"'s");

	printf("Há %d %c%s na string fornecida\n", count, character, plural);

	return 0;
}
