#include <stdio.h>

int main(){

	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	int total_seconds;
	int value = 1;

	printf("Digite uma quantidade de horas: ");
	scanf("%d",&hours);

	while(value){
		printf("Digite uma quantidade de minutos: ");
		scanf("%d",&minutes);
		if(minutes >= 60){
			puts("Quantidade de minutos inválida.");
		}
		else{
			value = 0;
		}
	}
	value = 1;
	while(value){
		printf("Digite uma quantidade de segundos: ");
		scanf("%d",&seconds);
		if(seconds >= 60){
			puts("Quantidade de segundos inválida.");
		}
		else{
			value = 0;
		}
	 }
	total_seconds = (hours * 60 + minutes)*60 + seconds;

	printf("A quantidade de horas digitada possui %d segundos\n",total_seconds);

	return 0;
}
