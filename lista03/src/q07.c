#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define INTERVAL 19

void random_vector(int *vector, int size);
void averages(int *vector, int size, int interval, float *arithmetic, float *geometric);

int main(){

	int vector[SIZE];
	int size = SIZE;
	int interval = INTERVAL;
	float arithmetic = 0;
	float geometric = 1;

	random_vector(vector, size);

	for(int i = 0; i < SIZE; i++)
		printf("%d ", vector[i]);
	puts("");

	averages(vector, size, interval, &arithmetic, &geometric);

	printf("A média aritmética é: %.2f\nA média geométrica é: %.2f\n", arithmetic, geometric);

	return 0;
}

void random_vector(int *vector, int size){
	srand(time(NULL));
	for(int i = 0; i < size; i++)
		vector[i] = rand()%INTERVAL;
}

void averages(int *vector, int size, int interval,float *arithmetic, float *geometric){
	int i;
	for(i = 0; i < size; i++){
		*arithmetic += vector[i];
		*geometric *= vector[i];
	}
	*arithmetic /= size;
	for(i = 1; i <= interval; i++)
		if(i*i*i > *geometric)
			break;
	i--;
	*geometric = i + (*geometric - i*i*i)/(i*i*size);
}
