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
void* busquedaBinaria(void* id);

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
int dato; //Es el numero a buscar
//********************************************************************************
//COMPORTAMIENTO DE LOS THREADS
//********************************************************************************

/*
	Esta función es para realizar la busqueda binaria iterativa con hilos, recibe como parametro el id del hilo
	que se procesara en ese momento.
	La funcion asigna rangos a los hilos para realizar la busqueda, para analizar si mejoran los tiempos de busqueda.
*/
void* busquedaBinaria(void* id)
{	
	int n_thread=(int)id;  //Numero del hilo
	int inicio,fin;		//Variables para indicar los elementos en los que se realizara la busqueda
	
	///Revisar la parte de los datos a procesar	
	inicio=(n_thread*N)/NumThreads; //el inicio donde inciara el hilo
	if(n_thread==NumThreads-1)	//si el hilo es el ultimo, su final sera n
		fin=N;
	else
		fin=((n_thread+1)*N)/NumThreads-1; //si no es el ultimo se le asigna un rango para trabajar
	
	
	int m, der, izq;		// Variables para el 
	der = inicio;
	izq = fin;
	
       while (izq <= der) {
        m = izq + (der - izq) / 2; //Obtenemos el numero del elemento a la mitad del arreglo
  
        // Comprobamos si el elemto esta en la mitad del arreglo
        if (arreglo[m] == dato)
            return 1;
  
        // Si x es mayor, ignoramos la mitad izquierda
        if (arreglo[m] < dato)
            izq = m + 1;
  
        //Si x es menor, ignoramos la mitad derecha
        else
            der = m - 1;
    }
  
   //Regresamos 0, en caso de llegar aqui es porque el elemento no se encuentra en el arreglo
    encontrado = 0;
	//Salimos del hilo
	pthread_exit(NULL);
}

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
	//Mandamos a llamar a la función que llena el arreglo pasando por referencia el arreglo y por valor la n
	llenarArreglo(arreglo, N);
	//lo imprimimos para verificar que se lleno correctamente
	// imprimirArreglo(arreglo, n);
				
	//***************************************************************************************************************************
	//Procesar desde cada hilo "busquedaLineal"
	//***************************************************************************************************************************
	//Ciclo for para buscar cada numero en el arreglo
	for(i=1;i<tamNumerosBuscar;i++){
		encontrado = 0;
		wtime1 = wtime0 = 0.0; //reiniciamos el tiempo en cada busqueda
		dato = numerosBuscar[i];
		//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
		//******************************************************************	
		uswtime(&utime0, &stime0, &wtime0);
		//******************************************************************
		for (j=0; j<NumThreads; j++) 
		{
			if (pthread_create (&thread[j], NULL, busquedaBinaria,(void*)j) != 0 ) 
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
	
	//Esperar a que terminen los threads (busquedaBinaria)
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



