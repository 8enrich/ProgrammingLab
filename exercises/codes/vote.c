#include <stdio.h>

void result(int, int*, int*, int*);

int main(){

	int vote = 1;
	int candidate1 = 0, candidate2 = 0, null = 0, total = 0;
	char plural = 's';
	char char_null = 0;
	char str[] = "ram";

	while(1){

		printf("Digite seu voto(ou 0 para terminar): ");
		scanf("%d",&vote);
		
		if(!(vote)){
			break;
		}
		result(vote, &candidate1, &candidate2, &null);

	}
	total = candidate1 + candidate2 + null;
	if(candidate1 != 1){
		plural = 's';
	}
	else{
		plural = char_null;
	}

	printf("O candidato 1 recebeu %d voto%c, representando %.2f por cento dos votos\n",candidate1,plural,((float)candidate1/total)*100);

	if(candidate2 != 1){
		plural = 's';
	}
	else{
		plural = char_null;
	}
	printf("O candidato 2 recebeu %d voto%c, representando %.2f por cento dos votos\n",candidate2, plural,((float)candidate2/total)*100);

	if(null != 1){
		plural = 's';
	}
	else{
		plural = char_null;
		str[0] = char_null;
		str[1] = char_null;
		str[2] = char_null;
	}

	printf("Houve%s %d voto%c nulo%c, representando %.2f por cento dos votos\n",str,null,plural,plural,((float)null/total)*100);
	
	printf("O total de votos é %d\n",total);
	return 0;
}

void result(int vote, int *candidate1, int *candidate2, int *null){
        switch(vote){
                case 100:
                        *candidate1 += 1;
                        break;
                case 200:
                        *candidate2 += 1;
                        break;
                default:
                        *null += 1;
        }

}

