#include <stdio.h>
#include <stdlib.h>

#define TOTAL 100

void create_file(FILE*, int);
void print_storage(FILE*);

int main(){

  FILE *fp;

  if((fp = fopen("hardware.dat", "r")) == NULL){
    fp = fopen("hardware.dat", "w");
    create_file(fp, TOTAL);
  }

  else{
    if((fp = fopen("hardware.dat", "a+")) == NULL){
      puts("Nao foi possivel abrir o arquivo!");
      exit(2);
    }
    int num;
    while(1){
      print_storage(fp);
      puts("1 - Deletar registro");
      printf("Digite uma acao(ou 0 para sair): ");
      scanf("%d", &num);
      if(!num) break;
    }
  }

  fclose(fp);

  return 0;
}

void create_file(FILE *fp, int total){
  char *str = NULL;
  if(!(str = (char*) malloc(sizeof(char) * total))) exit(1);
  for(int i = 0; i < total; i++){
    fprintf(fp, "# %d -", i);
    printf("Digite o nome do produto %d: ", i + 1);
    scanf(" %100[^\n]", str);
    fprintf(fp, " %s -", str);
    printf("Digite a quantidade do produto %d: ", i + 1);
    scanf(" %100[^\n]", str);
    fprintf(fp, " %s -", str);
    printf("Digite o preco do produto %d: ", i + 1);
    scanf(" %100[^\n]", str);
    fprintf(fp, " %s\n", str);
    printf("Deseja continuar(S ou N)? ");
    scanf(" %100[^\n]", str);
    if(*str == 'n') break;
  }
  free(str);
}

void print_storage(FILE *fp){
  puts("# registro - ferramenta - quantidade - custo");
  int ch = getc(fp);
  while(ch != EOF){
    putchar(ch);
    ch = getc(fp);
  }
}
