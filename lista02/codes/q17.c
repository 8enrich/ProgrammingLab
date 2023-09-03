#include <stdio.h>

int main(){

	for(int i = 10; i <= 100; i+= 10)
		printf("%d graus Celsius | %d graus Fahrenheit\n", i,(int)(i * 1.8 + 32));

	return 0;
}
