#include <stdio.h>

#define QUANTITY 10

struct Storage{
  char name[QUANTITY];
  int code;
  float price;
  int number;
};


int main(){

  struct Storage p1;

  printf("Digite o produto: ");
  scanf("%10[^\n]", p1.name);
  printf("Digite o código do produto: ");
  scanf("%d", &p1.code);
  printf("Digite o preço do produto: ");
  scanf("%f", &p1.price);
  printf("Digite o número do pedido: ");
  scanf("%d", &p1.number);

  printf("Nome:\t%s\nCódigo:\t%d\nPreço:\t%.2f\nPedido:\t%d\n", p1.name, p1.code, p1.price, p1.number);

  return 0;
}
