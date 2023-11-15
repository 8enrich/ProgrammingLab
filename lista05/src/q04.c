#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

void create_vector(int*, int);
void print_vector(int*, int);
void lowest_biggest(int*, int, int*);
void normalize(int*, int, float*, int*);

int main(int argc, char *argv[]){
  
  if(argc != 2){
    printf("Uso do programa: <%s> <tamanho do vetor>\n", argv[0]);
    exit(1);
  }
  
  int size = atoi(argv[1]);
  int *vector = NULL;
  float *final = NULL;

  if(!(vector = (int*) malloc(sizeof(int) * size))) exit(2);
  if(!(final = (float*) malloc(sizeof(float) * size))) exit(3);

  srand(time(NULL));
  create_vector(vector, size);
  print_vector(vector, size);
  int low_big[] = {*vector, *vector};
  lowest_biggest(vector, size, low_big);
  normalize(vector, size, final, low_big);
  for(int i = 0; i < size; i++)
    printf("%.2f ", *(final + i));
  puts("");

  free(vector);
  free(final);

  return 0;
}

void create_vector(int *vector, int size){
  for(int i = 0; i < size; i++)
    *(vector + i) = rand()%MAX;
}

void print_vector(int *vector, int size){
  for(int i = 0; i < size; i++)
    printf("%d ", *(vector + i));
  puts("");
}

void lowest_biggest(int *vector, int size, int *low_big){
  for(int i = 0; i < size; i++){
    if(*(vector + i) < (*low_big))
      *low_big = *(vector + i);
    if(*(vector + i) > *(low_big + 1))
      *(low_big + 1) = *(vector + i);
  }
}

void normalize(int *vector, int size, float *final, int *low_big){
  for(int i = 0; i < size; i++)
    *(final + i) = (float)(*(vector + i) - *low_big)/(*(low_big + 1) - *low_big);
}
