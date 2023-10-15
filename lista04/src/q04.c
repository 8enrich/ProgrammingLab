#include <stdio.h>
#include <stdlib.h>

#define SIZE 10
#define QUANTITY 2

void type_vector(void*, int);

int main(){

	void *vector = NULL;
	int type;
	
	for(int i = 0; i < QUANTITY; i++)
		type_vector(vector, i);
	return 0;
}

void type_vector(void* vector, int type){
	int i;
	switch(type){
		case 0:
			if(!(vector = (int*) realloc(vector, sizeof(int) * SIZE))) exit(1);
			for(i = 0; i < SIZE; i++){
                		printf("Digite o %dº inteiro: ", i +  1);
                		scanf("%d", (int*)vector + i);
        		}
			for(i = 0; i < SIZE; i++)
                		printf("[%p] %d\n", (int*)(vector + i * sizeof(int)), *(int*)(vector + i * sizeof(int)));
			break;
		case 1:
			if(!(vector = (char*) realloc(vector, sizeof(char) * SIZE))) exit(1);
                        for(i = 0; i < SIZE; i++){
                                printf("Digite o %dº caractere: ", i +  1);
                                scanf(" %c", (char*)vector + i);
                        }
                        for(i = 0; i < SIZE; i++)
                                printf("[%p] %c\n", (char*)(vector + i * sizeof(char)), *(char*)(vector + i * sizeof(char)));
                        break;
		default:
			break;
	}
}  
