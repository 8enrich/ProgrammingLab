#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 236

struct Vector{
  int *pointer;
  int quantity;
  float average;
};

void create_vector(int*, int, int);
void print_vector(int*, int);
void average(int*, int, float*);

int main(int argc, char *argv[]){

  if(argc != 2){
    printf("Uso do programa: <%s> <tamanho do vetor>\n", *argv);
    exit(1);
  }

  int size = atoi(*(argv + 1));
  int *vector = NULL;
  float sum = 0;

  if(!(vector = (int*) malloc(sizeof(int) * size))) exit(2);

  srand(time(NULL));
  create_vector(vector, size, MAX);
  print_vector(vector, size);
  average(vector, size, &sum);

  struct Vector v1;

  v1.pointer = (vector);
  v1.quantity = size;
  v1.average = sum;

  puts("");
  printf("\tVetor\nEndereço: %p\nElementos: %d\nMédia: %.2f\n", v1.pointer, v1.quantity, v1.average);

  free(vector);

  return 0;
}

void create_vector(int *vector, int size, int max){
  for(int i = 0; i < size; i++)
    *(vector + i) = rand()%max;
}

void print_vector(int *vector, int size){
  for(int i = 0; i < size; i++)
    printf("%d ", *(vector + i));
  puts("");
}

void average(int *vector, int size, float *sum){
  for(int i = 0; i < size; i++)
    *sum += *(vector + i);
  *sum /= size;
}
