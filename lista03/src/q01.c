#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void random_vector(float *vector, int size);
void bigger_lower(float *vector, int size, float *bigger, float *lower);

int main(){
	
	float vector[SIZE];
	float bigger;
	float lower;
	int size = SIZE;

	random_vector(vector, size);
	for(int i = 0; i < SIZE; i++)
		printf("%.2f ", vector[i]);
	puts("");

	bigger_lower(vector, size, &bigger, &lower);
	printf("A soma do maior e do menor valor é %.2f\n", bigger + lower);

	return 0;
}

void random_vector(float *vector, int size){
	srand(time(NULL));
	for(int i = 0; i < size; i++)
		vector[i] = ((float)rand()/RAND_MAX) * size; 
}

void bigger_lower(float *vector, int size, float *bigger, float *lower){
	for(int i = 0; i < size; i++){
		if(!i){
			*bigger = vector[i];
			*lower = vector[i];
		}
		if(vector[i] > *bigger)
			*bigger = vector[i];
		else if(vector[i] < *lower)
			*lower = vector[i];
	}		
}
