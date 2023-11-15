#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 20

void create_vector(int*, int, int);
void print_vector(int*, int);
void bubble_sort(int*, int);
void arithmetic_finder(int*, int);

int main(int argc, char *argv[]){
  
  if(argc != 2){
    printf("Uso do programa: <%s> <tamanho do vetor>\n", *argv);
    exit(1);
  }

  int size = atoi(*(argv + 1));
  int *vector = NULL;

  if(!(vector = (int*) malloc(sizeof(int) * size))) exit(2);

  srand(time(NULL));
  create_vector(vector, size, MAX);
  print_vector(vector, size);
  bubble_sort(vector, size);
  arithmetic_finder(vector, size);

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

void bubble_sort(int *vector, int size){
  unsigned char change = 0;
  while(!change){
    change++;
    for(int i = 0; i < size; i++)
      if(*(vector + i) > *(vector + i + 1)){
        *(vector + i) = *(vector + i) ^ *(vector + i + 1);
        *(vector + i + 1) = *(vector + i) ^ *(vector + i + 1);
        *(vector + i) = *(vector + i) ^ *(vector + i + 1);
        change = 0;
      }
  }
}

void arithmetic_finder(int *vector, int size){
  float average = 0;
  for(int i = 0; i < size; i++)
    average += *(vector + i);
  average /= size;
  float median = 0;
  if(size%2)
    median = *(vector + size/2);
  else 
    median = (float)(*(vector + size/2) + *(vector + ((size/2) - 1)))/2;

  int *vector_quantity = NULL;

  if(!(vector_quantity = (int*) malloc(sizeof(int) * size))) exit(3);

  int quantity;

  for(int i = 0; i < size; i += quantity){
    quantity = 0;
    for(int j = i; j < size; j++)
      if(*(vector + i) == *(vector + j))
        quantity++;
      else
        break;
    *(vector_quantity + i) = quantity;
  }

  int biggest = *vector_quantity;
  int mode = -1;

  for(int i = 1; i < size; i++)
    if(*(vector_quantity + i) > biggest){
      biggest = *(vector_quantity + i);
      if(biggest != 1){
        mode = *(vector + i);
      }
    }

  printf("A média é: %.2f\n", average);
  printf("A mediana é: %.2f\n", median);
  (mode > 0)? printf("A moda é: %.d\n", mode):puts("Não há moda");
}
