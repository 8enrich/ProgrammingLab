#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MASK 1
#define BITS 8

void control(unsigned char command, unsigned char *cabinets);
unsigned char verification(unsigned char cabinets, unsigned char bit);

int main(){

	unsigned char cabinets = 0;
	unsigned char option;

	while(1){
		for(unsigned char i = 0; i < BITS; i++){
			printf("Armário %hhu ", i);
			(verification(cabinets, i))? puts("Ocupado"):puts("Desocupado");
		}
		printf("1. Ocupar armário.\n2. Liberar armário\n3. Sair\n");
		printf("Digite uma opção: ");
		scanf("%hhu", &option);
		if(option == 3)
			break;
		else
			control(option, &cabinets);
	}
	return 0;
}

void control(unsigned char command, unsigned char *cabinets){
        unsigned char bit;
        switch(command){
                case 1:
                        srand(time(NULL));
			bit = rand() % BITS;
			if(!verification(*cabinets, bit)){
				*cabinets ^= MASK << bit;
				printf("O armário %hhu foi ocupado\n", bit);
			}
			else
				printf("O armário %hhu já está ocupado\n", bit);
			break;
                case 2:
                        printf("Escolha o armário para liberar: ");
                        scanf("%hhu", &bit);
			if(verification(*cabinets, bit)){
                        	*cabinets ^= MASK << bit;
				printf("O armário %hhu foi desocupado\n", bit);
			}
			else
				puts("Esse armário já está desocupado!");
			break;
		default:
			puts("Opção inválida");
        }

}

unsigned char verification(unsigned char cabinets, unsigned char bit){
	return((cabinets >> bit) & MASK);
}
