#include <stdio.h>
#include <stdlib.h>

#define QUANTITY 2

void do_operation(int*, char*, int);

int main(int argc, char *argv[]){

  if(argc != 4){
    printf("Uso do programa: <%s> <número1> <número2> <operação>\n", argv[0]);
    exit(1);
  }

  int num[QUANTITY];
  char *operation = argv[3];

  for(int i = 0; i < QUANTITY; i++)
    *(num + i) = atoi(*(argv + i + 1));

  do_operation(num, operation, QUANTITY);

  return 0;
}

void do_operation(int *nums, char *operation, int quantity){
  int result;
  switch(operation[0]){
    case '+':
      result = 0;
      for(int i = 0; i < quantity; i++)
         result += *(nums + i);
      printf("O resultado é: %d\n", result);
      break;
    case 'x':
      result = 1;
      for(int i = 0; i < quantity; i++)
        result *= *(nums + i);
      printf("O resultado é: %d\n", result);
      break;
    default:
      puts("Operação inválida!");
      break;
  }
}
