#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define QUANTITY 3

void random_vector(int*, int);
void print_vector(int*, int);
void bubble_sort(int*, int);

int main(){

  int *vector = NULL;
  int size;
  void (*pFunc[QUANTITY])(int*, int) = {random_vector, print_vector, bubble_sort};

  printf("Digite o tamanho do vetor: ");
  scanf("%d", &size);

  if(!(vector = (int *) malloc(sizeof(int) * size))) exit(1);

  for(int i = 0; i < QUANTITY; i++)
    pFunc[i](vector, size);

  pFunc[1](vector, size);

  return 0;
}

void random_vector(int *vector, int size){
  srand(time(NULL));
  for(int i = 0; i < size; i++)
    *(vector + i) = rand()%MAX;
}

void print_vector(int *vector, int size){
  for(int i = 0; i < size; i++)
    printf("%d ", *(vector + i));
  puts("");
}

void bubble_sort(int *vector, int size){
  unsigned char change = 0;
  while(!change){
    change++;
    size--;
    for(int i = 0; i < size; i++)
      if(*(vector + i) > *(vector + i + 1)){
        *(vector + i) = *(vector + i) ^ *(vector + i + 1);
        *(vector + i + 1) = *(vector + i) ^ *(vector + i + 1);
        *(vector + i) = *(vector + i) ^ *(vector + i + 1);
        change = 0;
      }
  }
}
