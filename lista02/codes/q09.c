#include <stdio.h>

int fibonacci(int n){
	if(n <= 2)
		return 1;
	return fibonacci(n - 2) + fibonacci(n - 1);
}

int main(){
	
	int n = 0;
	int result = 0;

	printf("Digite até qual N termo você deseja da série Fibonacci: ");
	scanf("%d",&n);
	
	for(int i = 1; i <= n; i++){
		result = fibonacci(i);
		printf("%d ", result);
	}
	puts("");

	return 0;
}
