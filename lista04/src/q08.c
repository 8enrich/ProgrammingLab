#include <stdio.h>

#define SIZE 10

void character_count(const char*, char, int*);

int main(){

  char string[SIZE];
  char character;
  int count = 0;

  printf("Digite uma palavra: ");
  scanf("%10[^\n]", string);

  printf("Digite um caractere: ");
  scanf(" %c", &character);

  character_count(string, character, &count);

  printf("Há %d desse caracter\n", count);

  return 0;
}

void character_count(const char *string, char character, int *count){
  for(int i = 0; *(string + i) != '\0'; i++)
    if(*(string + i) == character) (*count)++;
}
