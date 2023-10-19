#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void random_vector(int*, int, int);
void print_vector(int*, int);
void f_vector(int*, int*, int);

int main(){
	
	int x[SIZE];
	int *f = NULL;
	int size;
	int n;
		
	printf("Digite o final da faixa: ");
	scanf("%d", &n);
	
	if(!(f = (int*) malloc(sizeof(int) * n))) exit(1);
	
	random_vector(x, SIZE, n);
	puts("Vetor X: ");
	print_vector(x, SIZE);
	f_vector(x, f, SIZE);
	puts("Vetor F: ");
	print_vector(f, n);
	
	free(f);
	
	return 0;
}

void random_vector(int *vector, int size, int max){
	srand(time(NULL));
	for(int i = 0; i < size; i++)
		*(vector + i) = rand()%max;
}

void print_vector(int *vector, int size){
	for(int i = 0; i < size; i++)
		printf("%d ", *(vector + i));
	puts("");
}

void f_vector(int *vector1, int *vector2, int size){
  for(int i = 0; i < size; i++)
    *(vector2 + i) = 0;
	for(int i = 0; i < size; i++)
		(*(vector2 + *(vector1 + i)))++;
}
