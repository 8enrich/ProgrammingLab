#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 78

void create_matrix(int**, int, int);
void print_matrix(int**, int);
void sum_diagonal(int**, int);

int main(int argc, char *argv[]){

  if(argc != 2){
    printf("Uso do programa: <%s> <quantidade de linhas e colunas>\n", *argv);
    exit(1);
  }

  int **matrix;
  int size = atoi(*(argv + 1));

  if(!(matrix = (int**) malloc(sizeof(int*) * size))) exit(2);

  for(int i = 0; i < size; i++)
    if(!(*(matrix + i) = (int*) malloc(sizeof(int) * size))) exit(i + 3);

  srand(time(NULL));
  create_matrix(matrix, size, MAX);
  print_matrix(matrix, size);
  sum_diagonal(matrix, size);

  for(int i = 0; i < size; i++)
    free(*(matrix + i));
  free(matrix);

  return 0;
}

void create_matrix(int **matrix, int size, int max){
  for(int i = 0; i < size; i++)
    for(int j = 0; j < size; j++)
      *(*(matrix + i) + j) = rand()%max;
}

void print_matrix(int **matrix, int size){
  for(int i = 0; i < size; i++){
    for(int j = 0; j < size; j++)
      printf("%d ", *(*(matrix + i) + j));
    puts("");
  }
}

void sum_diagonal(int **matrix, int size){
  int sum = 0;
  for(int i = 0; i < size; i++)
    sum += *(*(matrix + i) + i);
  printf("A soma dos elementos da diagonal principal é: %s\n", (sum%2)?"ímpar":"par");
}
