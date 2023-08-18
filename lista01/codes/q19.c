#include <stdio.h>

int main(){

	char character = '*';
	int i = 0;

	for(i; i < 9; i++){
		if(i > 2){
			character = ' ';
		}
		if(!(i % 8)){
			printf("********    ***      *         *\n");
		}
		else if(i == 1 | i == 7){
			printf("*      *   *   *    %c*%C       * *\n",character,character);
		}
		else if(i == 2 | i == 6){
			printf("*      *  *     *  %c%c*%c%c     *   *\n",character,character,character,character);
		}
		else if(i == 3 | i == 5){
			printf("*      *  *     *    *      *     *\n");
		}
		else{
			printf("*      *  *     *    *     *       *\n");
		}
	}

	return 0;
}
