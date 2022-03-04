//*****************************************************************
/*
	ORDENAMIENTO POR MEZCLA 2
	Este programa muestra en funcionamiento el algoritmo de Ordenamiento
	por Mezcla para hacer la medición de tiempos con distinta cantidad 
	de numeros a ordenar
	Fecha: 11/09/2021
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

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************

void llenarArreglo(int* arreglo, int n);
void imprimirArreglo(int* arreglo, int n);
void mergeSort(int* arreglo, int p, int r);
void merge(int* arreglo, int p, int q, int r);
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{	
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; 	//n determina el tamaño del algorito dado por argumento al ejecutar
	int *arreglo; //Variable donde se guardara el arreglo
	int aux; //varibale auxiliar para el algoritmo burbuja
	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del arreglo
	else
	{
		n=atoi(argv[1]);
	}

	//Establecemos el tamaño del arreglo de acuerdo al tamaño n dado por argumento al ejecutar
	arreglo = malloc(n*sizeof(int)); 
	//mandamos a llamar a la función que llena el arreglo pasando por referencia el arreglo y por valor la n
	llenarArreglo(arreglo, n);
	//lo imprimimos para verificar que se lleno correctamente
	//imprimirArreglo(arreglo, n);

	
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo de Ordenamiento por Mezclq
	/*
		Este algoritmo de Ordenamiento por Mezcla es un algoritmo que funciona de manera 
		recursiva dividendo una lista por la mitad. Si la lista no esta vacía y tiene mas 
		de un elemento, se divide la lista nuevamente y se invoca recursivamente el 
		ordenamiento por mezcla para cada mitad.
		Una vez que las mitades están ordenadas se realiza la mezcla de estas, que consiste
		en tomar 2 listas ordenadas más pequeñas y combinarlas en una nueva y ordenada. 
	*/
	//******************************************************************	
	//Se llama a la funcion  de ordenamiento, con el arreglo , el indice de inicio y el el indice final de este.
	mergeSort(arreglo, 0, n-1);

	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	/*
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	*/
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
	exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************

/*
	Esta función llena nuestro arreglo con n números tomados del archivo que contiene
	10 millones de numeros.
	Recibe el arreglo y una n, no devuelve nada pues solo llena el arreglo.
*/
void llenarArreglo(int* arreglo, int n){
	
	int i = 0;//variable para ciclo

	//llenamos el arreglo gracias al for que va de 0 hasta la n indicada por parametros al ejecutar
	for(i=0;i<n;i++){
		scanf("%d", &arreglo[i]);
	}

}
/*
	Funcion para imprimir el arreglo y verificar su correcto ordenamiento
	Recibe el arreglo a imprimir y una n, no devuelve nada, solo imprime en pantalla
	los valores que tiene almacenados el arreglo
*/
void imprimirArreglo(int* arreglo, int n){
	int i = 0, k=0; //variable para ciclo

	//for para imprimir cada elemento del arreglo mas una variable k que nos diga la posicion del elemento
	for(i=0;i<n;i++)
		printf("%d: %d\n", ++k, arreglo[i]);

}
/*
	Funcion para divdir el arreglo a la mitad de manera recursiva y 
	hace una llamada a la funcion merge. Recibe el arreglo a ordenar, 
	el indice de incio del arreglo y el indice final de este.	
*/

void mergeSort(int* A, int p, int r){

	if(p<r){
		int q=((p+r))/2;
		mergeSort(A, p, q);
		mergeSort(A, q+1, r);
		merge(A, p, q, r);
	}
}
/*
	Funcion para mezclar de manera ordenada las pequeñas listas 
	creadas en la funcion mergeSort y va ordenando en una nueva 
	lista dichos elemntos.
*/

void merge(int* A, int p, int q, int r){
	int k;
	int l=r-p+1;
	int i=p;
	int j=q+1;
	int *C;

	C = malloc(l*sizeof(int));
	
	for(k=0; k<l; k++){
		if(i<=q && j<=r){
			if(A[i]< A[j]){
				C[k] =A[i];
				i++;
			}
			else{
				C[k] =A[j];
				j++;
			}
		}
		else if(i<=q){
			C[k] =A[i];
			i++;
		}
		else{
			C[k] =A[j];
			j++;
		}
	}
	
	for(k=0; k<l; k++)
		A[p+k]=C[k];
}