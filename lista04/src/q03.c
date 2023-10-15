#include <stdio.h>

int main(){

	int num;
	int lowest = 0;
	int *pn = &num;
	int *pl = &lowest;

	while(1){
		printf("Digite um número(ou 0 para sair): ");
		scanf("%d", &num);
		if(!*pl)
			*pl = *pn;
		if(!*pn)
			break;
		if(*pl > *pn)
			*pl = *pn;

		printf("O menor número fornecido é %d\n", *pl);
	}

	return 0;
}
