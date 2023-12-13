#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 100

int fread_lines(FILE*,char*);
void print_storage(FILE*,int);
void add_register(FILE*,int);
void change_register(FILE*,int);
void change_data(char*,int);

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

int fread_lines(FILE *fp, char *str){
  char ch;
  fseek(fp, -1, SEEK_CUR);
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
    n = fread_lines(fp, str);
    printf("%s\n", str);
  }
  free(str);
}

void add_register(FILE *fp, int total){
  char *str;
  int n;
  if(!(str = (char*) malloc(sizeof(char) * total))) exit(2);
  for(int i = 0; i <= total; i++){
    n = fread_lines(fp, str);
    if(n){
      fprintf(fp, "#%d", i + 1);
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
  int num, a;
  char ch;
  char *str;
  if(!(str = (char*) malloc(sizeof(char) * total))) exit(1);
  while(1){
    printf("Qual registro voce quer alterar: ");
    scanf("%d", &num);
    if(num <= 0 || num > 100) puts("Esse registro nao existe!");
    else break;
  }
  char **matrix = NULL;
  for(a = 0; a <= total; a++){
    ch = fread_lines(fp, str);
    if(a == num) change_data(str, total);
    if(!(matrix = (char**) realloc(matrix, sizeof(char*) * a + 1))) exit(3);
    if(!(*(matrix + a) = (char*) malloc(sizeof(char) * total))) exit(4);
    strcpy(*(matrix + a), str);
    if(ch) break;
  }
  freopen(NULL,"w",fp);
  for(int i = 0; i <= a; i++){
    fprintf(fp, "%s\n", matrix[i]);
    free(*(matrix + i));
  }
  freopen(NULL, "a+", fp);
  free(matrix);
  free(str);
  if(a < num) puts("Registro nao encontrado!");
}

void change_data(char *str, int total){
  char *slice = NULL, *backup = NULL;
  int j, num, spaces = 0;
  if(!(slice = (char*) malloc(sizeof(char) * total))) exit(1);
  if(!(backup = (char*) calloc(sizeof(char), total))) exit(2);
  strcpy(backup, str);
  for(int k = 0; k  < total; k++) *(str + k) = '\0';
  printf("%s\n", backup);
  puts("1 - nome | 2 - qtd | 3 - custo");
  printf("O que deseja mudar no registro: ");
  scanf("%d", &num);
  for(int i = 0; *(backup + i) != '\0'; i++){
    if(*(backup + i - 1) == ' ') spaces++;
    if(spaces == num){
      for(j = 0; j < i; j++) *(str + j) = *(backup + j);
      printf("Digite o novo dado: ");
      scanf("%s", slice);
      j += strlen(slice);
      strcat(str, slice);
      while(*(backup + i) != ' ' && *(backup + i) != '\0') i++;
      spaces++;
    }
    if(spaces > num){
      *(str + j) = *(backup + i);
      j++;
    }
  }
  free(slice);
  free(backup);
}
