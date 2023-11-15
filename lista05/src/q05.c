#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000

void create_vector(float*, int, int);
void print_vector(float*, int);
void sum_elements(float*, int);

int main(int argc, char *argv[]){

  if(argc != 2){
    printf("Uso do programa <%s> <quantidade de elementos>\n", *argv);
    exit(1);
  }

  int size = atoi(*(argv + 1));
  float *vector = NULL;

  if(!(vector = (float*) malloc(sizeof(float) * size))) exit(2);

  srand(time(NULL));
  create_vector(vector, size, MAX);
  print_vector(vector, size);
  sum_elements(vector, size);

  free(vector);

  return 0;
}

void create_vector(float *vector, int size, int max){
  for(int i = 0; i < size; i++)
    *(vector + i) = ((float)rand()/RAND_MAX)* max;
}

void print_vector(float *vector, int size){
  for(int i = 0; i < size; i++)
    printf("%.2f ", *(vector + i));
  puts("");
}

void sum_elements(float *vector, int size){
  float sum = 0;
  for(int i = 0; i < size; i++)
    sum += *(vector + i);
  printf("A soma de todos os elementos do vetor é: %.2f\n", sum);
}
