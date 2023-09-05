#include <stdio.h>

int main(){

	float pi = 0;
	float term = 0;

	for(int i = 0; i < 100000; i++){
		term = (float)4 / (2 * i + 1);
		term *= (i % 2)? -1: 1;
		pi += term;
		printf("Pi aproximado pelo %dº termo é: %f\n", i + 1, pi);
	}

	return 0;
}
