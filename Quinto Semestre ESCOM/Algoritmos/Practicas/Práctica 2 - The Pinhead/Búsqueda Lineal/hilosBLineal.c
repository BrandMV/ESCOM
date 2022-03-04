//*****************************************************************
/*
	Algoritmo de Búsqueda Lineal Con HIlos
	Este programa muestra el algoritmo de busqueda lineal
    para hacer la medición promedio del tiempo real que toma hacer varias busquedas
	con distinto tamaño de problema usando hilos
	
    Fecha: 26/09/2021
	Version: 1.0 
	Autores:
			-Martinez Ruiz Alfredo
			-Mendez Castañeda Aurora
			-Mendez Hipolito Emilio
			-Meza Vargas Brandon David
	Compilación: ""gcc -lm -lpthread -o hilosBLineal hilosBLineal.c"
	Ejecución: "./hilosBLineal 2 100000"

*/
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void llenarArreglo(int* arreglo, int n);
void imprimirArreglo(int* arreglo, int n);
void* busquedaLineal(void* id);
//*****************************************************************
//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int NumThreads;			//Número de threads
int N;
int encontrado = 0; //variable global para indicar si se encuentra el elemento
                        // 0 = no encontrado    1 = encontrado
int *arreglo; //Variable donde se guardara el arreglo
//Arreglo que contiene los numeros que se buscarán
int numerosBuscar[] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 1295390003,450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852,0};
//Obtenemos el tamaño del arreglo de los numeros a buscar:
int tamNumerosBuscar = sizeof numerosBuscar / sizeof *numerosBuscar;
int numero; //es el numero a buscar
//********************************************************************************
//COMPORTAMIENTO DE LOS THREADS
//********************************************************************************

/*
	ESta función es para realizar la busqueda lineal con hilos, recibe como parametro el id del hilo
	que se procesara en ese momento.
	ESta funcion asigna rangos a los hilos para realizar la busqueda, de esta forma se mejoran los tiempos
	de busqueda.
*/
void* busquedaLineal(void* id)
{	
	int n_thread=(int)id; //para saber el numero de hilo
	int inicio,fin,i,a;

	//Revisar la parte de los datos a procesar	
	inicio=(n_thread*N)/NumThreads; //el inicio donde inciara el hilo
	if(n_thread==NumThreads-1)	//si el hilo es el ultimo, su final sera n
		fin=N;
	else
		fin=((n_thread+1)*N)/NumThreads-1; //si no es el ultimo se le asigna un rango para trabajar

	// printf("\nHola desde la busqueda\tSoy el thread %d\tInicio %d\tTermino %d",n_thread,inicio,fin);

	//Busqueda
	 //for para realizar la busqueda
    for(i=inicio;i<fin;i++)
        if(arreglo[i] == numero) //si coinciden los numeros se encontro 
            encontrado = 1;

	// printf("\nBye desde la busqueda\tSoy el thread %d\tHe terminado",n_thread);
	pthread_exit(NULL);

}

void llenarArreglo(int* arreglo, int n){
	
	int i = 0;//variable para ciclo

	//llenamos el arreglo gracias al for que va de 0 hasta la n indicada por parametros al ejecutar
	for(i=0;i<n;i++){
		scanf("%d", &arreglo[i]);
	}

}

/*
	Funcion para imprimir el arreglo y verificar su correcto llenado
	Recibe el arreglo a imprimir y una n, no devuelve nada, solo imprime en pantalla
	los valores que tiene almacenados el arreglo
*/
void imprimirArreglo(int* arreglo, int n){
	int i = 0; //variable para ciclo

	//for para imprimir cada elemento del arreglo mas una variable k que nos diga la posicion del elemento
	for(i=0;i<n;i++)
		printf("%d\n", arreglo[i]);

}

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char *argv[])
{	
	int i,j,k; 	//Variables auxiliares para loops
	double promedioWtime = 0; //variable para calcular el tiempo promedio de todas las busquedas
	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1;

	//******************************************************************	
	
	//********************************************************************************
	//Obtener el número de threads a usar y el arreglo para la identificacion de los mismos
	//********************************************************************************
	pthread_t *thread;
	if (argc<2) 
	{
		printf("Indique el número de threads - \tEjemplo: [user@equipo]$ %s 4\n\n",argv[0]);
		exit(-1);
	}  
	NumThreads=atoi(argv[1]);
	thread = malloc(NumThreads*sizeof(pthread_t));

	//***************************************************************************************************************************
	//Saber cuál es el tamaño del problema N
	//***************************************************************************************************************************	
	//Si no se introduce correctamente N
	if (argc!=3) 
	{
		printf("\nIndique el tamaño de N - \nEjemplo: [user@equipo]$ %s %s 1000\n",argv[0],argv[1]);
		exit(-1);
	}
	N=atoi(argv[2]);

  	//Establecemos el tamaño del arreglo de acuerdo al tamaño n dado por argumento al ejecutar
	arreglo = malloc(N*sizeof(int)); 
	//mandamos a llamar a la función que llena el arreglo pasando por referencia el arreglo y por valor la n
	llenarArreglo(arreglo, N);
	//lo imprimimos para verificar que se lleno correctamente
	// imprimirArreglo(arreglo, n);
				
	//***************************************************************************************************************************
	//Procesar desde cada hilo "busquedaLineal"
	//***************************************************************************************************************************
	//Crear los threads con el comportamiento "segmentar"
	for(i=1;i<tamNumerosBuscar;i++){
		encontrado = 0;
		wtime1 = wtime0 = 0.0; //reiniciamos el tiempo en cada busqueda
		numero = numerosBuscar[i];
		//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
		//******************************************************************	
		uswtime(&utime0, &stime0, &wtime0);
		//******************************************************************
		for (j=0; j<NumThreads; j++) 
		{
			if (pthread_create (&thread[j], NULL, busquedaLineal,(void*)j) != 0 ) 
			{
				perror("El thread no  pudo crearse");
				exit(-1);
			}
		}
		//******************************************************************	
		//Evaluar los tiempos de ejecución 
		//******************************************************************
		uswtime(&utime1, &stime1, &wtime1);
		//vamos sumando los tiempos que hace en cada suma para al final sacar el promedio
		promedioWtime += (wtime1 - wtime0); 
		// printf("%d ",numero);
		// printf((encontrado == 1) ? "Encontrado\n" : "No encontrado\n");
	}
	
	//Esperar a que terminen los threads (busquedaLineal)
	for (i=1; i<NumThreads; i++) pthread_join (thread[i], NULL);

	//Cálculo del tiempo de ejecución del programa
	// printf("\n");
	printf("Tamaño de problema: %d\n", N);
	// printf("\n");
	printf("Promedio tiempo real usando Hilos %.10f s\n",  (promedioWtime/20.0));
	// printf("\n");
	
	//Terminar programa normalmente	
	exit (0);	
}
