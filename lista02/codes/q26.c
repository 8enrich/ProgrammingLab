#include <stdio.h>

int int_to_bin(int num){

	int digit = 0;
	int pow = 1;
	int bin = 0;

	while(num){
		digit = num % 2;
		num /= 2;
		bin += digit * pow;
		pow *= 10;
	}
	return bin;
}

int main(){

	printf("      Decimal   |   Octal   |      Binário\n");
	for(int i = 1; i <= 256; i++){
		if(i < 10)
			printf("         %d      |", i);
		else if(i < 100)
			printf("        %d      |", i);
		else
			printf("       %d      |", i);
		if(i < 8)
			printf("     %o     |", i);
		else if(i < 64)
			printf("    %o     |", i);
		else
			printf("   %o     |", i);
		if(i < 2)
			printf("         %d   \n",int_to_bin(i));
		else if(i < 4)
			printf("        %d   \n",int_to_bin(i));
		else if(i < 8)
                        printf("       %d   \n",int_to_bin(i));
		else if(i < 16)
                        printf("      %d   \n",int_to_bin(i));
		else if(i < 32)
                        printf("     %d   \n",int_to_bin(i));
		else if(i < 64)
                        printf("    %d   \n",int_to_bin(i));
		else if(i < 128)
                        printf("   %d   \n",int_to_bin(i));
		else if(i < 256)
                        printf("  %d   \n",int_to_bin(i));
		else
			printf(" %d  \n",int_to_bin(i));
	}

	return 0;
}
