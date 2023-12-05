#include <stdio.h>
#include <stdlib.h>

#define SIZE 80

int main(){

  FILE *fp;
  char str[SIZE];

  if((fp = fopen("dates.csv", "a+")) == NULL){ 
    puts("Não foi possível abrir o arquivo");
    exit(1);
  }

  puts("Digite $ a qualquer momento para sair!");
  while(1){
    printf("Digite seu nome: ");
    scanf(" %80[^\n]", str);
    if(*str == '$') break;
    fprintf(fp, "%s,", str);
    printf("Digite sua idade: ");
    scanf(" %80[^\n]", str);
    if(*str == '$') break;
    fprintf(fp, "%s,", str);
    printf("Digite sua altura: ");
    scanf(" %80[^\n]", str);
    if(*str == '$') break;
    fprintf(fp, "%s\n", str);
  }

  fclose(fp);

  return 0;
}
