//Programa1a.c
#include <stdio.h>
#include <stdlib.h>

void main()
{
	
	const char* s = getenv("HOME");
	printf("\nImpresion de la variable home\n");
		if(s!=NULL)
		{
				printf("\n PATH: %s\n\n", s);
		}
		else
		{
			
			printf("getenv es nullo");
		}
}
