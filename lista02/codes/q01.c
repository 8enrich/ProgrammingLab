#include <stdio.h>

void day(int num);

int main(){

	unsigned int num = 0;

	while(1){
		printf("Digite um número(ou 0 para sair): ");
		scanf("%d",&num);

		if(!num)
			break;

		day(num);

	}
	return 0;
}

void day(int num){
        switch(num){
                case 1:
                        puts("Domingo");
                        break;
                case 2:
                        puts("Segunda");
                        break;
                case 3:
                        puts("Terça");
                        break;
                case 4:
                        puts("Quarta");
                        break;
                case 5:
                        puts("Quinta");
                        break;
                case 6:
                        puts("Sexta");
                        break;
                case 7:
                        puts("Sábado");
                        break;
                default:
                        puts("Número de dia não válido");
                        break;
        }
}
