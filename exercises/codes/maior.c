#include <stdio.h>

int bigger(int x, int y){
	if((~y > x)* y){
		return ~y;
	}
	else{
		return x;
	}
}
int main(){
	int x = 0;
	int y = 0;

	while(1){
		printf("Digite um número: ");
		scanf("%d",&x);

		x = bigger(x, y); 
	
		printf("%d é o maior número digitado e ele é %s\n",x,(x % 2)?"ímpar":"par");
		y = ~x;

	}

	return 0;
}
