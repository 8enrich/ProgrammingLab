#include <stdio.h>

#define QUANTITY 2
#define STUDENTS 3 

struct Student{
  float note1;
  float note2;
  float average;
};

void average_total(struct Student*, int);

int main(){

  struct Student s[STUDENTS];

  for(int i = 0; i < STUDENTS; i++){
    printf("Digite a 1ª nota do aluno %d: ", i + 1);
    scanf("%f", &(s + i)->note1);
    printf("Digite a 2ª nota do aluno %d: ", i + 1);
    scanf("%f", &(s + i)->note2);
    (s + i)->average = ((s + i)->note1 + (s + i)->note2)/QUANTITY;
  }

  average_total(s, STUDENTS);

  return 0;
}

void average_total(struct Student *s, int n){
  float sum = 0;
  for(int i = 0; i < n; i++)
    sum += (s + i)->average;
  sum /= n;
  printf("A média dos alunos é: %.2f\n", sum);
}
