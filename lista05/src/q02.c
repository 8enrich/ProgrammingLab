#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void create_vector(int*, int);
void print_vector(int*, int);
void lowest_element(int*, int);

int main(int argc, char *argv[]){
  
  if(argc != 2){
    printf("Uso do programa: <%s> <tamanho do vetor>\n", argv[0]);
    exit(1);
  }
  
  int size = atoi(argv[1]);
  int *vector = NULL;

  if(!(vector = (int*) malloc(sizeof(int) * size))) exit(2);

  srand(time(NULL));
  create_vector(vector, size);
  print_vector(vector, size);
  lowest_element(vector, size);

  return 0;
}

void create_vector(int *vector, int size){
  for(int i = 0; i < size; i++)
    *(vector + i) = rand()%MAX;
}

void print_vector(int *vector, int size){
  for(int i = 0; i < size; i++)
    printf("[%p] %d\n", (vector + i), *(vector + i));
  puts("");
}

void lowest_element(int *vector, int size){
  int *lowest = vector;
  for(int i = 0; i < size; i++){
    if(*(vector + i) < *lowest)
      lowest = (vector + i);
  }
  printf("O menor endereço é: %p\n", lowest);
}
