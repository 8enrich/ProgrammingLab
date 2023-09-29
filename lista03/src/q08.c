#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void random_vector(int *vector, int size, int begin, int end);
void print_vector(int *vector, int size);
void selection(int *vector, int size);
void bubble(int *vector, int size);

int main(){
	
	int vector[SIZE];
	int vector_copy[SIZE];
	int size = SIZE;
	int begin;
	int end;

	printf("Digite o início do intervalo: ");
	scanf("%d", &begin);

	end = begin - 1;
	while(begin > end){
		printf("Digite o final do intervalo: ");
		scanf("%d", &end);
	}

	random_vector(vector, size, begin, end);

	puts("O vetor é:");
	print_vector(vector, size);
	for(int i = 0; i < size; i++)
		vector_copy[i] = vector[i];
	selection(vector_copy, size);
	puts("O vetor organizado pelo método de seleção é:");
	print_vector(vector_copy, size);
	bubble(vector, size);
	puts("O vetor organizado pelo método de bolha é: ");
	print_vector(vector, size);

	return 0;
}

void random_vector(int *vector, int size, int begin, int end){
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		vector[i] = rand()%end;
		if(vector[i] <= begin)
			vector[i] = vector[i] % begin + begin;
	}
}

void print_vector(int *vector, int size){
	for(int i = 0; i < size; i++){
                printf("%d ", vector[i]);
                if(!((i + 1) % 10))
                        puts("");
        }
}

void selection(int *vector, int size){
	for(int i = 0; i < size; i++)
		for(int j = i; j < size; j++)
			if(vector[i] > vector[j]){
				vector[i] = vector[i] ^ vector[j];
				vector[j] = vector[i] ^ vector[j];
				vector[i] = vector[i] ^ vector[j];
			}
}

void bubble(int *vector, int size){
	int change = 1;
	while(change){
		change = 0;
		size--;
		for(int i = 0; i < size; i++)
			if(vector[i] > vector[i + 1]){
				vector[i] = vector[i] ^ vector[i + 1];
				vector[i + 1] = vector[i] ^ vector[i + 1];
				vector[i] = vector[i] ^ vector[i + 1];
				change = 1;
			}
	}
}
