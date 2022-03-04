#include <stdio.h>
#include <stdlib.h>

int factorial(int n);
int rep(int n, int k);

int main(int argc, char *argv[]) {
	
	int n=0, k=0, comb=0, resp=1;
	
	while(resp==1)
	{
	
	printf("Combinaciones sin repeticion de n elementos tomnados de k en k\n");
	printf("Ingrese el total n: ");
	scanf("%d",&n);
	printf("\nIngrese k: ");
	scanf("%d",&k);
	
	comb=rep(n,k);
	printf("\nLas combinaciones de %d en %d de un total de %d sin repeticiones son: %d",k,k,n,comb);
	
	printf("\nIngrese 1 para calcular otras combinaciones, 0 para cerrar: ");
	scanf("%d",&resp);
	system("cls");
	}
	
	return 0;
}

int factorial(int n){
	if(n < 1)
		return 0;
	else if(n==1)
		return 1;
		else
			return n*factorial(n-1);
}

int rep(int n, int k)
{
	return factorial(n) / (factorial(k) * factorial(n-k));
}
