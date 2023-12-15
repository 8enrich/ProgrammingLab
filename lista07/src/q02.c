#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TOTAL 100
#define QUANTITY 4

int fread_lines(FILE*,char*);
void print_storage(FILE*,int);
void add_register(FILE*,int);
void change_register(FILE*,int);
void change_data(char*,int);
void change_lines(FILE*,char**,int);
void del_register(FILE*, int);

int main(){

  FILE *fp;

  if(!(fp = fopen("../dataset/hardware.dat", "a+"))){
    puts("Não foi possível abrir o arquivo!");
    exit(1);
  }
  
  char ch;
  fscanf(fp, "%c", &ch);
  if(!ch) fprintf(fp, "#num - nome - qtd - custo\n");

  int num;
  void (*Func[QUANTITY])(FILE*, int) = {print_storage, add_register, change_register, del_register};

  while(1){
    puts("1 - Imprimir estoque\n2 - Adicionar registros\n3 - Alterar registro\n4 - Deletar registro");
    printf("Digite uma ação(ou 0 para sair): ");
    scanf("%d", &num);
    if(!num) break;
    rewind(fp);
    if(num > 0 && num <= QUANTITY) Func[num - 1](fp, TOTAL);
    else puts("Essa ação não existe!");
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
        if(*str == 's' || *str == 'S') break;
        else if(*str == 'n' || *str == 'N'){
          free(str);
          return;
        }
        puts("Comando desconhecido!");
      }
    }
  }
  free(str);
  puts("Não há mais espaço para produtos!");
}

void change_register(FILE *fp, int total){
  int num, a;
  char ch, *str;
  if(!(str = (char*) malloc(sizeof(char) * total))) exit(1);
  while(1){
    printf("Qual registro você quer alterar: ");
    scanf("%d", &num);
    if(num <= 0 || num > 100) puts("Esse registro não existe!");
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
  change_lines(fp, matrix, a);
  free(matrix);
  free(str);
  if(a < num) puts("Registro não encontrado!");
}

void change_data(char *str, int total){
  char *slice = NULL, *backup = NULL;
  int j, num, spaces = 0;
  if(!(slice = (char*) malloc(sizeof(char) * total))) exit(1);
  if(!(backup = (char*) calloc(sizeof(char), total))) exit(2);
  strcpy(backup, str);
  for(int k = 0; k  < total; k++) *(str + k) = '\0';
  printf("%s\n", backup);
  while(1){
    puts("1 - nome | 2 - qtd | 3 - custo");
    printf("O que deseja mudar no registro: ");
    scanf("%d", &num);
    if(num <= 0 || num > 3) puts("Esse dado não existe!");
    else break;
  }
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

void change_lines(FILE *fp, char **matrix, int size){
  freopen(NULL,"w",fp);
  for(int i = 0; i <= size; i++){
    fprintf(fp, "%s\n", matrix[i]);
    free(*(matrix + i));
  }
  freopen(NULL, "a+", fp);
}

void del_register(FILE *fp, int total){
  int num, a, value = 0;
  char ch, *str, *number;
  if(!(str = (char*) malloc(sizeof(char) * total))) exit(1);
  if(!(number = (char*) malloc(sizeof(char) * total))) exit(2);
  while(1){
    printf("Qual registro você quer deletar: ");
    scanf("%d", &num);
    if(num <= 0 || num > 100) puts("Esse registro não existe!");
    else break;
  }
  char **matrix = NULL;
  for(a = 0; a <= total; a++){
    ch = fread_lines(fp, str);
    if(a >= num){
      value = 1;
      sprintf(number,"%d", (a - value));
      int i;
      for(i = 0; *(number + i) != '\0'; i++) *(str + i + 1) = *(number + i);
      if(*(str + (++i)) != ' ') for(i; *(str + i) != '\0'; i++) *(str + i) = *(str + i + 1);
    }
    if(a != num){
      if(!(matrix = (char**) realloc(matrix, sizeof(char*) * a + 1 - value))) exit(3);
      if(!(*(matrix + (a - value)) = (char*) malloc(sizeof(char) * total))) exit(4);
      strcpy(*(matrix + (a - value)), str);
    }
    if(ch) break;
  }
  change_lines(fp, matrix, (a - value));
  free(matrix);
  free(str);
  free(number);
  if(a < num) puts("Registro não encontrado!");
}
