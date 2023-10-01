#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 5
#define CHARACTERS 3

void random_matrix(int size, int matrix[size][size]);
void print_count(int size, int matrix[size][size], int *count, int value);

int main(){

	int matrix[SIZE][SIZE];
	int size = SIZE;
	int value;
	int count = 0;
	char plural[CHARACTERS] = {0, 0, '\0'};

	random_matrix(size, matrix);

	while(1){
		printf("Digite um valor entre 0 e %d: ", SIZE);
		scanf("%d", &value);
		if(value > SIZE)
			puts("Valor inválido");
		else
			break;
	}

	puts("A sua matriz é: ");
	print_count(size, matrix, &count, value);
	if(count != 1)
		sprintf(plural, "es");
	printf("O valor digitado aparece %d vez%s na matriz\n", count, plural);

	return 0;
}

void random_matrix(int size, int matrix[size][size]){
	srand(time(NULL));
	for(int i = 0; i < size; i++)
		for(int j = 0; j < size; j++)
			matrix[i][j] = rand()%(size + 1);
}

void print_count(int size, int matrix[size][size], int *count, int value){
	for(int i = 0; i < SIZE; i++){
        	for(int j = 0; j < SIZE; j++){
                        if(matrix[i][j] == value)
                                ++*count;
                        printf("%d ", matrix[i][j]);
                }
                puts("");
        }
}
