#include <stdio.h>

#define QUANTITY 20

struct Teacher{
  char name[QUANTITY];
  int next_test;
};

struct Subject{
  char name[QUANTITY];
  float note;
  struct Teacher t;
};

int main(){

  struct Subject s;

  printf("Digite a disciplina: ");
  scanf("%20[^\n]", s.name);
  printf("Digite a sua nota: ");
  scanf("%f", &s.note);
  printf("Digite o nome do seu professor: ");
  scanf(" %20[^\n]", s.t.name);
  printf("Digite o dia da próxima prova do professor: ");
  scanf("%d", &s.t.next_test);

  puts("");
  printf("\t%s\nNota: %.2f\nProfessor: %s\nProva: %d\n", s.name, s.note, s.t.name, s.t.next_test);
}
