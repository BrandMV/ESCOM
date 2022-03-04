//*****************************************************************
/*
	Algoritmo de Búsqueda Lineal
	Este programa muestra el algoritmo de busqueda lineal
    para hacer la medición promedio del tiempo real que toma hacer varias busquedas
	con distinto tamaño de problema
	
    Fecha: 23/09/2021
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
#include "tiempo.h"

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void llenarArreglo(int* arreglo, int n);
void imprimirArreglo(int* arreglo, int n);
int busquedaLineal(int* arreglo, int numero, int n);

//*****************************************************************
//VARIABLE GLOBAL
int encontrado = 0; //variable global para indicar si se encuentra el elemento
                        // 0 = no encontrado    1 = encontrado
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
	int *arreglo; //Variable donde se guardara el arreglo
	//Arreglo que contiene los numeros que se buscarán
	int numerosBuscar[] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 1295390003,450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852,0};
	//Obtenemos el tamaño del arreglo de los numeros a buscar:
	int tamNumerosBuscar = sizeof numerosBuscar / sizeof *numerosBuscar;

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
	// imprimirArreglo(arreglo, n);

    //******************************************************************	
	//Algoritmo de Búsqueda con un árbol binario de búsqueda (ABB)
	/*
		Este algoritmo consiste en la creación previa de un ABB y posteriormente realizar consultas sobre el
		Si el elemento a buscar coincide con un elemento de la raíz se termina la búsqueda e indicamos
		que ha sido encontrado. Si no se encuentra se va al sub árbol derecho si el elemento a buscar
		es mayor que el valor de la raíz o a la izquierda si el elemento a buscar es menor que el valor de la raíz.
		Si se llega a un árbol nulo, es decir, vacío, el elemento a buscar no esta en el árbol.
    */
	//*

	for(i=0;i<tamNumerosBuscar;i++){
		encontrado = 0;
		wtime1 = wtime0 = 0.0; //reiniciamos el tiempo en cada busqueda
		//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
		//******************************************************************	
		uswtime(&utime0, &stime0, &wtime0);
		//******************************************************************
		busquedaLineal(arreglo,numerosBuscar[i],n);
		//******************************************************************	
		//Evaluar los tiempos de ejecución 
		//******************************************************************
		uswtime(&utime1, &stime1, &wtime1);
		//vamos sumando los tiempos que hace en cada suma para al final sacar el promedio
		promedioWtime += (wtime1 - wtime0); 
		// printf("%d ",numerosBuscar[i]);
		// printf((encontrado == 1) ? "Encontrado\n" : "No encontrado\n");
	}

	//Cálculo del tiempo de ejecución del programa
	// printf("\n");
	printf("Tamaño de problema: %d\n", n);
	// printf("\n");
	printf("Promedio tiempo real %.10f s\n",  (promedioWtime/20.0));
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

/*
	Funcion para realizar la busqueda lineal, es el algoritmo de busqueda mas sencillo de todos pues
    se recorre todo el arreglo hasta que el numero en la posicion i sea igual al numero buscado.
    Recibe el arreglo donde se buscara el numero, el numero a buscar y el tamaño del arreglo.
    Retorna el indice del numero si se encontro o -1 si la busqueda falla.
*/
int busquedaLineal(int *arreglo, int numero, int n){
    int i = 0;

    //for para realizar la busqueda
    for(i=0;i<n;i++)
        if(arreglo[i] == numero) //si coinciden los numeros se encontro 
            return i;
    
    return -1; //la busqueda falla
}
