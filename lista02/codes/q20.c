#include <stdio.h>

int factorial(int num){
	if(!num)
		return 1;
	return num * factorial(num - 1);
}

int main(){

	for(int i = 0; i < 10; i++)
		if(i % 2)
			printf("%d! = %d\n", i, factorial(i));

	return 0;
}
