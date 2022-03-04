#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complejo 
{ 
	float real; 
	float imag; 
	float magnitud;
	float angulo;
	
} Complejo; 

Complejo crearComplejo();
void convertirPolar(float *r, float *p, float x, float y);
void real(Complejo c1, Complejo c2);
void imag(Complejo c1, Complejo c2);
Complejo sumar(Complejo c1, Complejo c2);
Complejo resta(Complejo c1, Complejo c2);
Complejo multi(Complejo c1, Complejo c2);
Complejo divi(Complejo c1, Complejo c2);
void imprimir(Complejo c);

int main(int argc, char *argv[]) 
{
	
	int opc=0, res=0; 
	
	Complejo c1,c2,c3;
	
	c1=crearComplejo();
	c2=crearComplejo();

	while(opc!=7)
	{
	
		printf("\nOperaciones con el TAD complejo: \n");
		printf("0. Saber parte real\n");
		printf("1. Saber parte imaginaria\n");
		printf("2. Sumar complejos\n");
		printf("3. Restar complejos\n");
		printf("4. Multiplicar complejos\n");
		printf("5. Dividir complejos\n");
		printf("6. Salir\n");
		printf("¿Quer desea realizar?: ");
		scanf("%d", &opc);
		
		switch(opc)
		{
			case 0:
				real(c1,c2);
				break;
			case 1:
				imag(c1,c2);
				break;
			case 2:
				c3=sumar(c1,c2);
				imprimir(c3);
			
				break;
			case 3:
				c3=resta(c1,c2);
				imprimir(c3);
				break;
			case 4:
				c3=multi(c1,c2);
				imprimir(c3);
				break;
			case 5:
				c3=divi(c1,c2);
				imprimir(c3);
				break;
			case 6:
				return 0;
				break;		
		}
		
	}
		
	return 0;
}



Complejo crearComplejo()
{
	Complejo c;
	float mag=0.0, ang=0.0;
	
	printf("Ingrese la parte real: ");
	scanf("%f",&c.real);
	printf("Ingrese la parte imaginaria: ");
	scanf("%f",&c.imag);
	c.magnitud=mag;
	c.angulo=ang;
	return c;
}

void convertirPolar(float *r, float *p, float x, float y)
{
	*r= sqrt(x*x + y*y);
	*p= atan2(y,x);	
}

void real(Complejo c1, Complejo c2)
{
	printf("La parte real de los numeros complejos son: %0.2fi y %0.2fi", c1.real, c2.real);
}
void imag(Complejo c1, Complejo c2)
{
	printf("La parte imaginaria de los numeros complejos son: %0.2f y %0.2f", c1.imag, c2.imag);
}

Complejo sumar(Complejo c1, Complejo c2)
{
	Complejo c;
	
	c.real=c1.real+c2.real;
	c.imag=c1.imag+c2.imag;
	
	return c;	
}

Complejo resta(Complejo c1, Complejo c2)
{
	Complejo c;
	
	c.real=c1.real-c2.real;
	c.imag=c1.imag-c2.imag;
	
	return c;
}
Complejo multi(Complejo c1, Complejo c2)
{
	Complejo c;
	
	c.real= (c1.real*c2.real) - (c1.imag*c2.imag);
	c.imag= (c1.real*c2.imag) + (c1.imag*c2.real);
	
	return c;
}

Complejo divi(Complejo c1, Complejo c2)
{
	Complejo c;
	
	c.real= ((c1.real*c2.real) + (c1.imag*c2.imag)) / ((c2.real*c2.real) + (c2.imag*c2.imag));
	c.imag= ((c1.imag*c2.real) - (c1.real*c2.imag)) / ((c2.real*c2.real) + (c2.imag*c2.imag));
	
	return c;
}

void imprimir(Complejo c)
{
	printf("El resultado es: %0.2f", c.real);
	if(c.imag<0)	
		printf("%0.2fi\n", c.imag);
	else
		printf(" + %0.2fi\n", c.imag);
}
