#include <stdio.h>

int main(){

	float width = 0;
	float length = 0;
	float height = 0;
	float volume = 0;
	int value = 1;

	while(value){
		printf("Digite o comprimento da caixa: ");
		scanf("%f",&width);
		if(width <= 0){
			puts("Comprimento inválido.");
		}
		else{
			value = 0;
		}
	}
	value = 1;
	while(value){
		printf("Digite a largura da caixa: ");
		scanf("%f",&length);
		if(length <= 0){
			puts("Largura inválida.");
		}
		else{
			value = 0;
		}
	}
	value = 1;
	while(value){
		printf("Digite a altura da caixa: ");
		scanf("%f",&height);
		if(height <= 0){
			puts("ALtura inválida.");
		}
		else{
			value = 0;
		}
	}
	volume = width * length * height;

	printf("O volume da caixa é: %.2f\n",volume);

	return 0;
}
