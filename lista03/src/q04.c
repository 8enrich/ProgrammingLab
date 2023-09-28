#include <stdio.h>
#include <string.h>

#define SIZE 20

int strcmp_h(const char *str1, const char *str2);

int main(){

	char str1[SIZE];
	char str2[SIZE];

	printf("Digite uma string: ");
	scanf("%20[^\n]", str1);
	printf("Digite outra string: ");
	scanf(" %20[^\n]", str2);

	printf("Utilizando a função strcmp: Essas strings são %s\n", (!strcmp(str1, str2))?"iguais":"diferentes");
	printf("Utilizando a minha função: Essas strings são %s\n", (!strcmp_h(str1, str2))?"iguais":"diferentes");

	return 0;
}

int strcmp_h(const char *str1, const char *str2){
	int cmp = 0;
	for(int i = 0; str1[i] != '\0'; i++){
		if(str1[i] != str2[i])
			cmp = str1[i] - str2[i];
	}
	return cmp;
}
