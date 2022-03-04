//*****************************************************************
/*
	ORDENAMIENTO SHELL
	Este programa muestra el algoritmo de ordenación por shell y hace la medición de tiempos
	con distinta cantidad de numeros a ordenar
	Fecha: 10/09/2021
	Version: 1.0
	Autores:
			-Martinez Ruiz Alfredo
			-Mendez Castañeda Aurora
			-Mendez Hipolito Emilio
			-Meza Vargas Brandon David
*/
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
#include <math.h>

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void llenarArreglo(int *arreglo, int n);
void imprimirArreglo(int *arreglo, int n);
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char *argv[])
{
	//******************************************************************
	//Variables del main
	//******************************************************************
	double utime0, stime0, wtime0, utime1, stime1, wtime1; //Variables para medición de tiempos
	int n;												   //n determina el tamaño del algorito dado por argumento al ejecutar
	int i;												   //Variable para el loop
	int k;												   // Variable para representar una fracción (posición) del arreglo
	int *arreglo;										   //Variable donde se guardará el arreglo de números
	int b;												   // Bandera que representa si hubo cambios o no dentro de alguna serie de comparaciones
	int temp;											   // Variable que ayuda a hacer la conmutaicón de números

	//******************************************************************
	//Recepción y decodificación de argumentos
	//******************************************************************
	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc != 2)
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n", argv[0]);
		exit(1);
	}
	// Si se introduce un número mayor a 10 millones
	else if (atoi(argv[1]) > 10000000)
	{
		printf("\nIngrese un número menor a 10,000,000\n");
		exit(1);
	}
	//Tomar el segundo argumento como tamaño del arreglo
	else
	{
		n = atoi(argv[1]);
	}

	//Establecemos el tamaño del arreglo de acuerdo al tamaño n dado por argumento al ejecutar
	arreglo = malloc(n * sizeof(int));

	//mandamos a llamar a la función que llena el arreglo pasando por referencia el arreglo y por valor la n
	llenarArreglo(arreglo, n);

	//lo imprimimos para verificar que se lleno correctamente
	//imprimirArreglo(arreglo, n);

	//******************************************************************
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************

	//Algoritmo de ordenamiento por shell
	/*
		Este algoritmo se basa en tomar fracciones del código en cada
		ocasión más pequeñas, empieza por la mitad (haciendo función piso
		a la mitad). 
		Compara los elementos del principio con la mitad y va aumentando
		hasta que el índice del principio llegue a la mitad y el que
		empezó en la mitad llegue al final. Esto lo repite hasta que ya 
		no haya cambios en esa fracción, tratando de llevar los más grandes
		hasta el final del arreglo.
		
		Más tarde parte a un cuarto y de nuevo compara con otro del principio
		hasta que que empezó en un cuarto del tamaño llega al final. También
		repite las comparaciones hasta que no haya cambios.

		Al final termina tomando las posiciones 0 y 1 del arreglo y compara 
		hasta que el segundo índice llegue al final (algo parecido a lo que
		pasa con el algoritmo de selección).

		Después de estas últimas series de comparaciones el algoritmo termina
		puesto que ya no puede tomar una fraccion igual o menor a 0.
	*/
	//******************************************************************
	k = trunc(n / 2);
	while (k >= 1)
	{
		do
		{
			b = 0;
			for (int i = k; i <= n - 1; i++)
			{
				if (arreglo[i - k] > arreglo[i])
				{
					temp = arreglo[i];
					arreglo[i] = arreglo[i - k];
					arreglo[i - k] = temp;
					b++;
				}
			}

		} while (b != 0);
		k = trunc(k/2);
	}

	//******************************************************************

	//******************************************************************
	//Evaluar los tiempos de ejecución
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);

	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	//Mostrar los tiempos en formato exponecial
	// printf("\n");
	// printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	// printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	// printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	// printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	// printf("\n");
	//******************************************************************

	//mandamos a llamar la funcion para imprimir solo para verificar que este el arreglo ordenado
	imprimirArreglo(arreglo, n);

	//Terminar programa normalmente
	exit(0);
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES
//************************************************************************

/*
	Esta función llena nuestro arreglo con n números tomados del archivo que contiene 10 millones de numeros o de la terminal en su defecto. 
	Recibe el arreglo y una n, no devuelve nada pues solo llena el arreglo.
*/
void llenarArreglo(int *arreglo, int n)
{

	int i = 0; // Variable para ciclo

	// Llenamos el arreglo gracias al for que va de 0 hasta antes de la n indicada por parametros al ejecutar
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arreglo[i]);
	}
}

/*
	Funcion para imprimir el arreglo y verificar su correcto ordenamiento
	Recibe el arreglo a imprimir y una n, no devuelve nada, solo imprime en pantalla
	los valores que tiene almacenados el arreglo
*/
void imprimirArreglo(int *arreglo, int n)
{
	int i = 0; //variable para ciclo

	// for para imprimir cada elemento del arreglo mas una variable k que nos diga la posicion del elemento
	for (i = 0; i < n; i++)
		printf("%d: %d\n", i + 1, arreglo[i]);
}