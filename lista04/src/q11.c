#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void random_vector(int*, int, int);
void print_vector(int*, int);
void matrix_m(int**, int*, int*, int, int);
void print_matrix(int**, int, int);

int main(){

  int x[SIZE];
  int y[SIZE];
  int n;
  int **m = NULL;

  printf("Digite o fim da faixa: ");
  scanf("%d", &n);

  srand(time(NULL));
  random_vector(x, SIZE, n);
  puts("Vetor X:");
  print_vector(x, SIZE);
  random_vector(y, SIZE, n);
  puts("Vetor Y: ");
  print_vector(y, SIZE);

  if(!(m = (int**) malloc(sizeof(int*) * n))) exit(1);
  for(int i = 0; i < n; i++)
    if(!(*(m + i) = (int*) malloc(sizeof(int) * n))) exit(i + 2);

  matrix_m(m, x, y, SIZE, n);
  puts("Matriz M: ");
  print_matrix(m, n, n);

  for(int i = 0; i < n; i++)
    free(*(m + i));
  
  free(m);

  return 0;
}

void random_vector(int *vector, int size, int max){
  for(int i = 0; i < size; i++)
    *(vector + i) = rand()%max;
}

void print_vector(int *vector, int size){
  for(int i = 0; i < size; i++)
    printf("%d ", *(vector + i));
  puts("");
}

void matrix_m(int **matrix, int *vector1, int *vector2, int size, int n){
  for(int i = 0; i < n; i++)
    matrix[i][i] = 0;
  for(int i = 0; i < size; i++)
    matrix[*(vector2 + i)][*(vector1 + i)]++;
}

void print_matrix(int **matrix, int rows, int cols){
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++)
      printf("%d ", matrix[i][j]);
    puts("");
  }
}
