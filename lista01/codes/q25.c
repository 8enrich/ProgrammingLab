#include <stdio.h>

int main(){

	int hours = 0;
	int minutes = 0;
	int seconds = 0;
	char plural[4] = "s,";
	char x = plural[2];

	printf("Digite um tempo em segundos: ");
	scanf("%d",&seconds);

	minutes = seconds/60;
	hours = minutes/60;
	seconds -= minutes*60;
	minutes -= hours*60;

	plural[2] = ' ';
	if(hours == 1){
		plural[0] = ',';
		plural[1] = ' ';
		plural[2] = x;
	}
	printf("Nesse tempo há %d hora%s",hours,plural);
	plural[0] = 's';
	plural[1] = ' ';
	plural[2] = 'e';
	if(minutes == 1){
		plural[0] = ' ';
		plural[1] = 'e';
		plural[2] = x;
	}
	printf("%d minuto%s",minutes,plural);
	plural[0] = 's';
	plural[1] = ' ';
	plural[2] = x;
	if(seconds == 1){
		plural[0] = ' ';
		plural[1] = x;
	}
	printf(" %d segundo%s\n",seconds,plural);

	return 0;

}
