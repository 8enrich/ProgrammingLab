#include <stdio.h>


#define SIZE 20

const char *reverse(char *str, int size);

int main(){

	char str[SIZE];
	int size = SIZE;

	printf("Digite uma string: ");
	scanf("%20[^\n]", str);

	reverse(str, size);

	for(int i = 0; i < SIZE; i++)
		printf("%c", str[i]);
	puts("");
	return 0;
}

const char *reverse(char *str, int size){
	for(int i = 0; i < size/2; i++){
		str[i] = str[(size - 1) - i] ^ str[i];
		str[(size - 1) - i] = str[(size - 1) - i] ^ str[i];
		str[i] = str[(size - 1) - i] ^ str[i];
	}
	return str;
}
