#include <stdio.h>
#include <stdlib.h>


int potencia(int a, int b);
int main(int argc, char *argv[]) 
{
	int a=0, b=0, res=0, resp=1;

	while(resp==1)
	{
		printf("Ingrese la base: \n");
		scanf("%d",&a);
		printf("Ingrese el exponente: ");
		scanf("%d", &b);
		res=potencia(a,b);
		printf("%d ^ %d = %d\n",a,b,res);
		printf("\nIngrese 1 para calcular una potencia, 0 para cerrar: ");
		scanf("%d",&resp);
		system("cls");
	}
	
	return 0;
}


int potencia(int a, int b)
{
	if(b==0)
		return 1;
	else
		return a*(potencia(a,b-1));
}
