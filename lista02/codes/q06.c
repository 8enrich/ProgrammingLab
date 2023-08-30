#include <stdio.h>
#include <string.h>

void result(int, int*, int*, int*, int*);

int main(){

	int vote = 1;
	int candidate1 = 0, candidate2 = 0, white = 0, null = 0, total = 0;
	char accept[2];
	char plural = 's';
	char char_null = '\0';
	char plural_str[4] = "\0\0\0";

	while(1){

		printf("Digite seu voto(ou um número negativo para terminar): ");
		scanf("%d",&vote);

		if(vote < 0)
			break;

		printf("Deseja confirmar o seu voto(s ou n): ");
		scanf(" %c", accept);

		if(accept[0] == 's')
			result(vote, &candidate1, &candidate2, &white, &null);

	}
	total = candidate1 + candidate2 + null + white;
	if(candidate1 != 1){
		plural = 's';
	}
	else{
		plural = char_null;
	}

	printf("Paulo recebeu %d voto%c, representando %.2f por cento dos votos\n",candidate1,plural,((float)candidate1/total)*100);

	if(candidate2 != 1){
		plural = 's';
	}
	else{
		plural = char_null;
	}
	printf("Renata recebeu %d voto%c, representando %.2f por cento dos votos\n",candidate2, plural,((float)candidate2/total)*100);

	if(null != 1){
		plural = 's';
		strcpy(plural_str, "ram");
	}
	else{
		plural = char_null;
	}

	printf("Houve%s %d voto%c nulo%c, representando %.2f por cento dos votos\n",plural_str,null,plural,plural,((float)null/total)*100);

	if(white != 1){
		plural = 's';
		strcpy(plural_str, "ram");
	}
	else{
		plural = char_null;
		sprintf(plural_str, "%c", char_null);
	}

	printf("Houve%s %d voto%c branco%c, representando %.2f por cento dos votos\n",plural_str,white,plural,plural,((float)white/total)*100);
	printf("O total de votos é %d\n",total);
	return 0;
}

void result(int vote, int *candidate1, int *candidate2,int *white, int *null){
        switch(vote){
                case 5:
                        *candidate1 += 1;
                        break;
                case 7:
                        *candidate2 += 1;
                        break;
		case 0:
			*white += 1;
			break;
                default:
                        *null += 1;
        }

}
