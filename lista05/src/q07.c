#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 200

void create_vector(int*, int, int);
void print_vector(int*, int);
void mse(int*, int*, int);

int main(int argc, char *argv[]){

  if(argc != 2){
    printf("Uso do programa: <%s> <tamanho dos vetores>\n", *argv);
    exit(1);
  } 

  int n = atoi(*(argv + 1));
  int *a = NULL;
  int *b = NULL;

  if(!(a = (int*) malloc(sizeof(int) * n))) exit(2);
  if(!(b = (int*) malloc(sizeof(int) * n))) exit(3);

  srand(time(NULL));
  create_vector(a, n, MAX);
  create_vector(b, n, MAX);
  print_vector(a, n);
  print_vector(b, n);
  mse(a, b, n);

  free(a);
  free(b);

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

void mse(int *predicted, int *observed, int size){
  float sum = 0;
  for(int i = 0; i < size; i++)
    sum += ((*(observed + i) - *(predicted + i)) * (*(observed + i) - *(predicted + i)));
  sum /= (float)size;
  printf("O erro médio quadrático absoluto entre A e B é: %.2f\n", sum);
}
