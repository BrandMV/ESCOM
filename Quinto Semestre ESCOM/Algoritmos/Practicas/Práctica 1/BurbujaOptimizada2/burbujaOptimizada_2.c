//*****************************************************************
/*
	BURBUJA OPTIMIZADA 2
	Este programa muestra el algoritmo de ordenaci�n burbuja optimizada 2 para hacer la medici�n de tiempos
	con distinta cantidad de numeros a ordenar
	Fecha: 11/09/2021
	Version: 1.0
	Autores:
			-Martinez Ruiz Alfredo
			-Mendez Casta�eda Aurora
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
//DECLARACI�N DE FUNCIONES
//*****************************************************************
void llenarArreglo(int* arreglo, int n);
void imprimirArreglo(int* arreglo, int n);
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{	
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medici�n de tiempos
	int n; 	//n determina el tama�o del algorito dado por argumento al ejecutar
	int i, j; //Variables para loops
	int *arreglo; //Variable donde se guardara el arreglo
	int aux; //varibale auxiliar para el algoritmo burbuja
	int cambios; //Variable que nos servira como bandera
	//******************************************************************	
	//Recepci�n y decodificaci�n de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecuci�n y cadena=n)
	if (argc!=2) 
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tama�o del arreglo
	else
	{
		n=atoi(argv[1]);
	}

	//Establecemos el tama�o del arreglo de acuerdo al tama�o n dado por argumento al ejecutar
	arreglo = malloc(n*sizeof(int)); 
	//mandamos a llamar a la funci�n que llena el arreglo pasando por referencia el arreglo y por valor la n
	llenarArreglo(arreglo, n);
	//lo imprimimos para verificar que se lleno correctamente
	// imprimirArreglo(arreglo, n);

	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo Burbuja Optimizada 2
	/*
		Este algoritmo trabaja de manera similar que el algoritmo Burbuja, 
		sin embargo, se hace uso de una variable flag o bandera que nos 
		indica si se realizaron o no cambios al hacer una interacci�n con 
		lo que podemos evitar realizar iteraciones de m�s una vez que el 
		arreglo ya ha sido ordenado.
	*/
	//******************************************************************	
	cambios = 1; 
	i=0;
	while(i<=n-2 && cambios!=0 ){
		cambios = 0;
		for(j=0;j<=(n-2)-i;j++){
			if(arreglo[j] < arreglo[j+1]){
				aux = arreglo[j];
				arreglo[j] = arreglo[j+1];
				arreglo[j+1] = aux;
				cambios = 1;
			}
		}
		i++; 
	}
	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecuci�n 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//C�lculo del tiempo de ejecuci�n del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acci�nes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	// printf("\n");
	// printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	// printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	// printf("sys (Tiempo en acci�nes de E/S)  %.10e s\n",  stime1 - stime0);
	// printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	// printf("\n");
	//******************************************************************
	//mandamos a llamar la funcion para imprimir solo para verificar que este el arreglo ordenado
	// imprimirArreglo(arreglo, n);
	//Terminar programa normalmente	
	exit (0);	
}

//************************************************************************
//DEFINICI�N DE FUNCIONES 
//************************************************************************

/*
	Esta funci�n llena nuestro arreglo con n n�meros tomados del archivo que contiene
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
