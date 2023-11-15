#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50

void create_matrix(int**, int, int, int);
void print_matrix(int**, int, int);
void binary_matrix(int**, int, int, int);

int main(int argc, char *argv[]){

  if(argc != 4){
    printf("Uso do programa: <%s> <quantidade de linhas> <quantidade de colunas> <valor do limiar t>\n", *argv);
    exit(1);
  }

  int rows = atoi(*(argv + 1));
  int cols = atoi(*(argv + 2));
  int t = atoi(*(argv + 3));
  
  int **matrix = NULL;

  if(!(matrix = (int**) malloc(sizeof(int*) * rows))) exit(2);

  for(int i = 0; i < rows; i++)
    if(!(*(matrix + i) = (int*) malloc(sizeof(int) * cols))) exit(i + 3);

  srand(time(NULL));
  create_matrix(matrix, rows, cols, MAX);
  print_matrix(matrix, rows, cols);
  binary_matrix(matrix, rows, cols, t);

  for(int i = 0; i < rows; i++)
    free(*(matrix + i));

  free(matrix);

  return 0;
}

void create_matrix(int **matrix, int n, int m, int max){
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      *(*(matrix + i) + j) = rand()%max;
}

void print_matrix(int **matrix, int n, int m){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++)
      printf("%d ", *(*(matrix + i) + j));
    puts("");
  }
  puts("");
}

void binary_matrix(int **matrix, int n, int m, int t){
  int **s = NULL;

  if(!(s = (int**) malloc(sizeof(int*) * n))) exit(n + m);

  for(int i = 0; i < n; i++)
    if(!(*(s + i) = (int*) malloc(sizeof(int) * m))) exit(n + m + i);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      *(*(s + i) + j) = (*(*(matrix + i) + j) > t)? 1 : 0;

  print_matrix(s, n, m);

  for(int i = 0; i < n; i++)
    free(*(s + i));

  free(s);
}
