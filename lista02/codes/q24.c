#include <stdio.h>

int main(){

	for(int cathet1 = 1; cathet1 < 500; cathet1++)
		for(int cathet2 = 1; cathet2 < 500; cathet2++)
			for(int hypotenuse = 1; hypotenuse < 500; hypotenuse++)
				if(cathet1*cathet1 + cathet2*cathet2 == hypotenuse*hypotenuse)
					printf("%d**2 + %d**2 = %d**2\n", cathet1, cathet2 ,hypotenuse);

	return 0;
}
