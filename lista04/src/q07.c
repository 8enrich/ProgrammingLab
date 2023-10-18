#include <stdio.h>

#define SIZE 10

char *strcat_h(char*, const char*);

int main(){

  char string_1[SIZE * 2]; 
  char string_2[SIZE];

  printf("Digite uma palavra: ");
  scanf("%10[^\n]", string_1);

  printf("Digite outra palavra: ");
  scanf(" %10[^\n]", string_2);

  strcat_h(string_1, string_2);

  printf("A nova string 1 é: %s\n", string_1);

  return 0;
}

char *strcat_h(char *destination, const char *source){
  int j = 0;
  for(int i = 0; *(source + j) != '\0'; i++)
      if(*(destination + i) == '\0'){
        *(destination + i) = *(source + j);
        j++;
      }
  return destination;
}
