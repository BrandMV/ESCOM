#include <stdio.h>
#include <stdlib.h>

typedef struct fracc{
	int nume;
	int den;
}fraccion;

fraccion crearFraccion();
void numerador(fraccion f1, fraccion f2);
void denominador(fraccion f1, fraccion f2);
fraccion sumar(fraccion f1, fraccion f2);
fraccion resta(fraccion f1, fraccion f2);
fraccion multi(fraccion f1, fraccion f2);
fraccion divi(fraccion f1, fraccion f2);
void simpli(fraccion f);
void imprimir(fraccion f);

int main(int argc, char *argv[]) 
{
	int opc=0, res=0;
	
	fraccion f1,f2, f3;
	
	f1=crearFraccion();
	f2=crearFraccion();
	
	
	while(opc!=6)
	{
	
		printf("\nOperaciones con el TAD fraccion: \n");
		printf("0. Saber el numerador de las fracciones\n");
		printf("1. Saber el denominador de las fracciones\n");
		printf("2. Sumar fracciones\n");
		printf("3. Restar fracciones\n");
		printf("4. Multiplicar fracciones\n");
		printf("5. Dividir fracciones\n");
		printf("6. Salir\n");
		printf("¿Quer desea realizar?: ");
		scanf("%d", &opc);
		if(opc>6)
			printf("\nOpcion no valida\n");
		
		switch(opc)
		{
			case 0:
				numerador(f1,f2);
				break;
			case 1:
				denominador(f1,f2);
				break;
			case 2:
				f3=sumar(f1,f2);
				imprimir(f3);
				simpli(f3);
			
				break;
			case 3:
				f3=resta(f1,f2);
				imprimir(f3);
				simpli(f3);
				break;
			case 4:
				f3=multi(f1,f2);
				imprimir(f3);
				simpli(f3);
				break;
			case 5:
				f3=divi(f1,f2);
				imprimir(f3);
				simpli(f3);
				break;
			case 6:
				break;
				
		}
	}	
	return 0;
}

fraccion crearFraccion()
{
	int aux=1;
	fraccion f;
	printf("Ingrese el numerador de la fraccion: ");
	scanf("%d",&(f.nume));
	while(aux)
	{
		aux=0;
		printf("Ingrese el denominador de la fraccion (distinto a 0): ");
		scanf("%d", &(f.den));
		if((f.den)==0){
			printf("El denominador debe ser distinto a 0");
			aux=1;
		}
	}
	return f;
}


void numerador(fraccion f1, fraccion f2)
{
	printf("El numerador de las fracciones f1 y f2 son: %d y %d\n", f1.nume, f2.nume);
}

void denominador(fraccion f1, fraccion f2)
{
	printf("El denominador de las fracciones f1 y f2 son: %d y %d\n", f1.den, f2.den);
}

fraccion sumar(fraccion f1, fraccion f2)
{
	fraccion f;
	f.nume=(f1.nume*f2.den)+(f1.den*f2.nume);
	f.den=f1.den*f2.den;
	return f;
}

fraccion resta(fraccion f1, fraccion f2)
{
	fraccion f;
	f.nume=(f1.nume*f2.den)-(f1.den*f2.nume);
	f.den=f1.den*f2.den;
	return f;
}

fraccion multi(fraccion f1, fraccion f2)
{
	fraccion f;
	f.nume=f1.nume*f2.nume;
	f.den=f1.den*f2.den;
	return f;
}

fraccion divi(fraccion f1, fraccion f2)
{
	fraccion f;
	f.nume=f1.nume*f2.den;
	f.den=f1.den*f2.nume;
	return f;
}

void simpli(fraccion f)
{
	int res=0, aux=0;
	printf("¿Simplificar el resultado? (1=si / 0=no)\n");
	scanf("%d",&res);
	
	if(res==0)
		return;
	else
	{
		if(f.den==1)
			printf("No se puede simplificar mas: %d/%d", f.nume, f.den);
		else
		{
			aux=2;
			while(aux<=f.nume)
			{
				if(f.den%aux==0 && f.nume%aux==0)
				{
					f.den/=aux;
					f.nume/=aux;
				}else
					aux++;
			}
		}
	}
	printf("Resultado simplificado es: %d/%d\n", f.nume, f.den);
}
	


void imprimir(fraccion f)
{
	printf("El resultado es: %d/%d\n", f.nume, f.den);
}
