#include <stdio.h>
#include <string.h>

#define SIZE 20
#define DOUBLE_SIZE 40

const char *strcat_h(char *str1, const char *str2);

int main(){

	char str1[DOUBLE_SIZE];
	char str2[SIZE];
	char str3[DOUBLE_SIZE];

	printf("Digite uma string: ");
	scanf("%20[^\n]", str1);

	printf("Digite outra string: ");
	scanf(" %20[^\n]", str2);

	sprintf(str3, "%s", str1);

	printf("A string concatenada pela função strcat fica: %s\n", strcat(str1, str2));
	printf("A string concatenada pela minha função fica: %s\n", strcat_h(str3, str2));
	
	return 0;
}

const char *strcat_h(char *str1, const char *str2){
	int i;
	for(i = 0; str1[i] != '\0'; i++);
	for(int j = 0; str2[j] != '\0'; j++)
		str1[i++] = str2[j];
	return str1;
}
