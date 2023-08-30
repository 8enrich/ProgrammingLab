#include <stdio.h>

int main(){

	int years = 0;
	char names[2][10];
	int change = 0;
	int heights[3] = {0, 0};
	int per_year[3] = {0, 0};

	for(int i = 0; i < 2; i++){
		printf("Digite o nome da %d° pessoa: ",i+ 1);
		scanf("%s",names[i]);
		printf("Digite a altura em centímetros da %d° pessoa: ",i + 1);
		scanf("%d",&heights[i]);
		printf("Digite o crescimento por ano da %d° pessoa: ",i + 1);
		scanf("%d",&per_year[i]);
	}
	if(heights[1] > heights[0]){
		change = 1;
	}

	for(years; (heights[change] + per_year[change] * years >= heights[!change] + per_year[!change] * years);years++){}

	printf("Demorará %d anos para que %s fique maior que %s\n",years,names[!change],names[change]);
}
