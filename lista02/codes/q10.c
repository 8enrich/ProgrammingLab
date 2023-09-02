#include <stdio.h>

int main(){

	for(int i = 15; i <= 90; i++)
		if(!(i % 4))
			printf("%d**2 = %d\n",i,i*i);
		
	return 0;
}
