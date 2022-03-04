#include <stdio.h>
#include <stdlib.h>

void moverDisco(char dest, char aux, char fte, int N, int *cont);

int main(int argc, char *argv[]) 
{
	char fuente= 'A', auxiliar= 'B', destino= 'C';
	int N=0, contador= 0;
	printf("Ingrese la cantidad de discos: ");
	scanf("%d",&N);
	
	moverDisco(destino, auxiliar, fuente, N, &contador);
	
	return 0;
}

void moverDisco(char dest, char aux, char fte, int N, int *cont)
{
	if (N==0)
	  return;
	  
	moverDisco(aux, dest, fte, N-1, cont);
		
	printf("%d. Mover disco %d: de %c a %c\n", *cont, N, fte, dest);
	(*cont)++;
	
	moverDisco(dest, fte, aux, N-1, cont);
}



