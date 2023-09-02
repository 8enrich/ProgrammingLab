#include <stdio.h>

int main(){

	int n = 1;

	for(int i = 0; i <= 7; i++){
		printf("3**%d = %d\n",i, n);
		n *= 3;
	}

	return 0;
}
