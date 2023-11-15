#include <stdio.h>

#define QUANTITY 2

struct student{
  float note1;
  float note2;
  float average;
};

int main(){

  struct student s1;

  printf("Digite a 1ª nota do aluno: ");
  scanf("%f", &s1.note1);
  printf("Digite a 2ª nota do aluno: ");
  scanf("%f", &s1.note2);
  
  s1.average = (s1.note1 + s1.note2)/QUANTITY;

  printf("A média do aluno é: %.2f\n", s1.average);

  return 0;
}
