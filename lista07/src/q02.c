#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 100

int fread_lines(FILE*,int, char*);
void print_storage(FILE*,int);
void add_register(FILE*,int);
void change_register(FILE*,int);

int main(){

  FILE *fp;

  if(!(fp = fopen("hardware.dat", "a+"))){
    puts("Nao foi possivel abrir o arquivo!");
    exit(1);
  }
  
  char ch;
  fscanf(fp, "%c", &ch);
  if(!ch) fprintf(fp, "#num - nome - qtd - custo\n");

  int num;

  while(1){
    puts("1 - Imprimir estoque\n2 - Adicionar registros\n3 - Alterar registro\n4 - Deletar registro");
    printf("Digite uma acao(ou 0 para sair): ");
    scanf("%d", &num);
    if(!num) break;
    rewind(fp);
    if(num == 1) print_storage(fp, TOTAL);
    if(num == 2) add_register(fp, TOTAL);
    if(num == 3) change_register(fp, TOTAL);
  }

  fclose(fp);

  return 0;
}

int fread_lines(FILE *fp, int total, char *str){
  char ch;
  fscanf(fp, "%[^\n]s", str);
  fseek(fp, 1, SEEK_CUR);
  ch = getc(fp);
  if(ch == EOF) return 1;
  return 0;
}

void print_storage(FILE *fp, int total){
  char *str;
  int n = 0;
  if(!(str = (char*) malloc(sizeof(char) * total))) exit(1);
  while(!n){
    n = fread_lines(fp, total, str);
    printf("%s\n", str);
  }
  free(str);
}

void add_register(FILE *fp, int total){
  char *str;
  int n;
  if(!(str = (char*) malloc(sizeof(char) * total))) exit(2);
  for(int i = 0; i <= total; i++){
    n = fread_lines(fp, total, str);
    if(n){
      fprintf(fp, " #%d", i + 1);
      printf("Digite o nome do produto: ");
      scanf("%s", str);
      fprintf(fp, " %s", str);
      printf("Digite a quantidade do produto: ");
      scanf("%s", str);
      fprintf(fp, " %s", str);
      printf("Digite o custo do produto: ");
      scanf("%s", str);
      fprintf(fp, " %s\n", str);
      while(1){
        printf("Deseja adicionar mais registros(S ou N): ");
        scanf("%s", str);
        if(*str == 's') break;
        else if(*str == 'n'){ 
          free(str);
          return;
        }
        puts("Comando desconhecido!");
      }
    }
  }
  free(str);
  puts("Nao ha mais espaco para produtos!");
}

void change_register(FILE *fp, int total){
  int num;
  char ch;
  char *str, *slice, *new;
  int spaces = 0, j;
  if(!(str = (char*) malloc(sizeof(char) * total))) exit(1);
  if(!(new = (char*) malloc(sizeof(char) * total))) exit(2);
  if(!(slice = (char*) malloc(sizeof(char) * total))) exit(3);
  while(1){
    printf("Qual registro voce quer alterar: ");
    scanf("%d", &num);
    if(num <= 0 || num > 100) puts("Esse registro nao existe!");
    else break;
  }
  int a;
  for(a = 0; a <= total; a++){
    ch = fread_lines(fp, total, str);
    if(a == num){
      printf("%s\n", str);
      puts("1 - nome | 2 - qtd | 3 - custo");
      printf("O que deseja mudar no registro: ");
      scanf("%d", &num);
      for(int i = 0; *(str + i) != '\0'; i++){
        if(*(str + i - 1) == ' ') spaces++;
        if(spaces == num){
          for(j = 0; j < i; j++) *(new + j) = *(str + j);
          printf("Digite o novo dado: ");
          scanf("%s", slice);
          j += strlen(slice);
          strcat(new, slice);
          while(*(str + i) != ' ' && *(str + i) != '\0') i++;
          spaces++;
        }
        if(spaces > num){
          *(new + j) = *(str + i);
          j++;
        }
      }
      freopen(NULL, "r+", fp);
      for(int k = 0; k < a; k++) ch = fread_lines(fp, total, str);
      fprintf(fp, "%s\n", new);
      free(new);
      free(slice);
      free(str);
      freopen(NULL, "a+", fp);
      return;
    }
    if(ch) break;
  }
  free(str);
  free(slice);
  free(new);
  puts("Registro nao encontrado!");
}
