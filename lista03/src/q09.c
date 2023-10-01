#include <stdio.h>

#define SIZE 3

int main(){

	int matrix[SIZE][SIZE];
	int i, j;

	for(i = 0; i < SIZE; i++)
		for(j = 0; j < SIZE; j++){
			printf("Digite o %dº elemento da matriz: ", (SIZE * i) + (j + 1));
			scanf("%d", &matrix[i][j]);
		}

	puts("A sua matriz é: ");
	for(i = 0; i < SIZE; i++){
		for(j = 0; j < SIZE; j++)
			printf("%d ", matrix[i][j]);
		puts("");
	}

	puts("Os elementos da diagonal principal são: ");
	for(i = 0; i < SIZE; i++)
		printf("%d ", matrix[i][i]);
	puts("");

	return 0;
}
