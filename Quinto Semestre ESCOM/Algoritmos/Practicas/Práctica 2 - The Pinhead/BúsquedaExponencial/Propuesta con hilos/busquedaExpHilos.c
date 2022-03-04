//*****************************************************************
/*
	Algoritmo de Búsqueda Exponencial
	Este programa muestra el algoritmo de busqueda exponencial para 
    hacer la medición promedio del tiempo real que toma hacer varias 
    busquedas con distinto tamaño de problema
	
    Fecha: 24/09/2021
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
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tiempo.h"

typedef struct parte{
    int l;
    int r;
    int x;
}Parte;

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void *busquedaBinaria(void *arg);
void busquedaExponencial(int arr[], int n, int x);
void llenarArreglo(int* arreglo, int n);
void imprimirArreglo(int* arreglo, int n);
int min(int x, int y);

//*****************************************************************
//VARIABLE GLOBAL
int encontrado = 0; //variable global para indicar si se encuentra el elemento
                        // 0 = no encontrado    1 = encontrado
int *arr; //Variable donde se guardara el arreglo

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main(int argc, char* argv[]){
    //******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	double promedioWtime = 0; //variable para calcular el tiempo promedio de todas las busquedas
    
    int n; 	//n determina el tamaño del problema del algoritmo dado por argumento al ejecutar
    int i; //Variable para loops
    
    //Arreglo que contiene los numeros que se buscarán
	int numerosBuscar[] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 
    1295390003,450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 
    1360839354, 2109248666, 2147470852,0};
	//Obtenemos el tamaño del arreglo de los numeros a buscar:
	int tamNumerosBuscar = sizeof numerosBuscar / sizeof *numerosBuscar;
    
    //******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

    //Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2) {
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} else{ //Tomar el segundo argumento como tamaño del arreglo
		n=atoi(argv[1]);
	}

    //Establecemos el tamaño del arreglo de acuerdo al tamaño n dado por argumento al ejecutar
	arr = malloc(n*sizeof(int)); 
	//se llama a la función que llena el arreglo pasando por referencia el arreglo y por valor la n
	llenarArreglo(arr, n);
	//lo imprimimos para verificar que se lleno correctamente
	// imprimirArreglo(arreglo, n);

    //******************************************************************	
	//Algoritmo de Búsqueda exponencial
	/*
		La búsqueda exponencial consta de dos pasos:  
            1. Encuentra el rango donde el elemento está presente
            2. Realice una búsqueda binaria en el rango encontrado arriba.
        Para encontrar el rango la idea es comenzar con un subarreglo de tamaño 1, 
        comparar su último elemento con x, luego probar el tamaño 2, luego 4 y así 
        sucesivamente hasta que el último elemento de un subarreglo no sea mayor. 
        Una vez que encontramos un índice i (después de repetidas duplicación de i), 
        sabemos que el elemento debe estar presente entre i/2 e i.
        (¿Por qué i / 2? Porque no pudimos encontrar un valor mayor en la iteración anterior)
    */
	//*

    for(i=0;i<tamNumerosBuscar;i++){
		wtime1 = wtime0 = 0.0; //reiniciamos el tiempo en cada busqueda
		//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
		//******************************************************************	
		uswtime(&utime0, &stime0, &wtime0);
		//******************************************************************
        busquedaExponencial(arr, n, numerosBuscar[i]);
		//******************************************************************	
		//Evaluar los tiempos de ejecución 
		//******************************************************************
		uswtime(&utime1, &stime1, &wtime1);
		//vamos sumando los tiempos que hace en cada suma para al final sacar el promedio
		promedioWtime += (wtime1 - wtime0); 
		
		//printf((encontrado == 1) ? "Encontrado\n" : "No encontrado\n");
	}

	//Cálculo del tiempo de ejecución del programa
	// printf("\n");
	printf("\nTamaño de problema: %d", n);
	// printf("\n");
	printf("\nPromedio tiempo real %.10f s\n",  (promedioWtime/20.0));
	// printf("\n");

    return 0;
}

/*
	Esta función llena nuestro arreglo con n números tomados del archivo que contiene
	10 millones de numeros.
	Recibe el arreglo y una n, no devuelve nada pues solo llena el arreglo.
*/
void llenarArreglo(int* arreglo, int n){
	
	int i = 0;//variable para ciclo

	//llenamos el arreglo por parametros al ejecutar
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

	//imprime cada elemento del arreglo 
	for(i=0;i<n;i++)
		printf("%d\n", arreglo[i]);

}

/*
  Función que realiza la búsqueda exponencial
  Recibe el arreglo (arr), el tamaño del arreglo (n) y el número a buscar (x)
  No regresa nada 
*/
void busquedaExponencial(int arr[], int n, int x){
    pthread_t hilo1, hilo2; //variables para los hilos
    Parte parte1, parte2;
    // Si x se encuentra en la primera posición
	if (arr[0] == x)
		encontrado = 1;

	/* Se encuentra el rango para la búsqueda binaria
	   por duplicación repetida */
	int i = 1;
	while (i < n && arr[i] <= x){
		i = i*2;
	}

	// Se manda a llamar a la búsqueda binaria para realizar la búsqueda dentro del rango
	//return busquedaBinaria(arr, i/2, min(i, n-1), x);
    int tam, mitad,lim;
    lim = i/2;
    tam = min(i,n-1)-lim+1;
    mitad = tam / 2;

	parte1.l = lim;
	parte1.r = mitad + lim - 1;
	parte1.x = x;

	parte2.l = mitad +lim;
	parte2.r = min(i,n-1);
	parte2.x = x;
	
    pthread_create(&hilo1, NULL, busquedaBinaria, (void *)&parte1);
    pthread_create(&hilo2, NULL, busquedaBinaria, (void *)&parte2);

    pthread_join(hilo1,NULL);
    pthread_join(hilo2,NULL);
}

/* Búsqueda iterativa binaria
   Recibe el arreglo, , el indice inferior del rango, el indice superior del rango y el
   número a buscar  
   Retorna la posición del elemento que se busca si lo encuentra, sino retorna -1 */
void *busquedaBinaria(void *arg){
	Parte *p;
	p = (Parte *)arg;

    while (p->l <= p->r) {
        int m = p->l + (p->r - p->l) / 2;
        // Comprueba si x se encuentra en la mitad del arreglo
        if (arr[m] == p->x)
            encontrado = 1;
  
        // Si x es mayor, se ignora la mitad izquierda
        if (arr[m] < p->x)
            p->l = m + 1;
  
        // Si x es menor, se ignora la mitad derecha
        else
            p->r = m - 1;
    }

    encontrado = 0; //retorna -1 si no se encuentra
}

/*Función que recibe dos números y retorna el menor*/
int min(int x, int y){
	if(x > y)
		return y;
	else
		return x;
}

