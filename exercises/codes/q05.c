#include <stdio.h>

int bigger_num(int n, int bigger){
	return (bigger > n)* bigger + (bigger < n)* n;
}

int smaller_num(int n, int smaller){
	return (smaller < n)* smaller + (smaller > n)* n;
}

int main(){

	int n = 0;
	int bigger = 0;
	int smaller = 0;

	while(1){
		printf("Digite um valor: ");
		scanf("%d",&n);

		if(!n)
			break;

		if(!(bigger)){
			bigger = n;
			smaller = n;
		}
		else{
			bigger = bigger_num(n, bigger);
			smaller = smaller_num(n, smaller);
		}

		printf("%d é o maior número digitado\n%d é o menor número digitado\n",bigger,smaller);
	}

	return 0;
}
