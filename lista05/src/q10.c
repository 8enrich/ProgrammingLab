#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void create_vector(int*, int, int);
void print_vector(int*, int);
void create_matrix(int**, int*, int*, int);
void print_matrix(int**, int, int);

int main(int argc, char *argv[]){

  if(argc != 3){
    printf("Uso do programa: <%s> <tamanho do vetor> <valor de n>\n", *argv);
    exit(1);
  }

  int size = atoi(*(argv + 1));
  int n = atoi(*(argv + 2));
  int *x = NULL;
  int *y = NULL;
  int **matrix = NULL;

  if(!(x = (int*) malloc(sizeof(int) * size))) exit(2);
  if(!(y = (int*) malloc(sizeof(int) * size))) exit(3);

  if(!(matrix = (int**) malloc(sizeof(int*) * n))) exit(4);

  for(int i = 0; i < n; i++)
    if(!(*(matrix + i) = (int*) calloc(sizeof(int), n))) exit(i + 5);

  srand(time(NULL));
  create_vector(x, size, n);
  create_vector(y, size, n);
  print_vector(x, size);
  print_vector(y, size);
  puts("");
  create_matrix(matrix, x, y, size);
  print_matrix(matrix, n, n);

  free(x);
  free(y);
  for(int i = 0; i < n; i++)
    free(*(matrix + i));
  free(matrix);

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

void create_matrix(int **matrix, int *vector1, int *vector2, int size){
  for(int i = 0; i < size; i++)
    (*(*(matrix + *(vector2 + i)) + *(vector1 + i)))++;
}

void print_matrix(int **matrix, int rows, int cols){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++)
      printf("%d ", *(*(matrix + i) + j));
    puts("");
  }
}
