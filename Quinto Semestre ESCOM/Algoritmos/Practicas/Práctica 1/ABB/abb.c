//*****************************************************************
/*
	ORDENAMIENTO CON UN ÁRBOL BINARIO DE BÚSQUEDA (ABB)
	Este programa muestra el algoritmo de ordenación con un árbol binario 
    de búsqueda para hacer la medición de tiempos con distinta cantidad 
    de numeros a ordenar.
	
    Fecha: 08/09/2021
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
//DEFINIENDO LA ESTRUCTURA DEL ARBOL
//*****************************************************************
struct Arbol{
    int dato;
    struct Arbol *izquierda;
    struct Arbol *derecha;
};

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void llenarArreglo(int* arreglo, int n);
void imprimirArreglo(int* arreglo, int n);
struct Arbol *insertar(struct Arbol *nodo, int n);
void guardarRecorridoInOrden(struct Arbol *nodo, int *arreglo);

//*****************************************************************
int aux = 0; //variable auxiliar
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
	int i, j; //Variables para loops
	int *arreglo; //Variable donde se guardara el arreglo
	struct Arbol *arbol = NULL; //variable que apunta a la estructura Arbol
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
	//Algoritmo Ordenamiento con un árbol binario de búsqueda (ABB)
	/*
        Este algortimo requiere de dos pasos:
        1. Insertar cada uno de los número de un arreglo en el árbol binario de búsqueda.
        2. Reemplazar los elementos en desorden del arreglo por el arreglo resultante de un 
            recorrido InOrden del ABB, el cual entrega los números ya ordenados.
    */
	//******************************************************************	
	
    for(i=0; i<n; i++){
        arbol = insertar(arbol, arreglo[i]);
    }

    guardarRecorridoInOrden(arbol,arreglo);
    
    //******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
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
	//imprimirArreglo(arreglo, n); 
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

/*  Esta función inserta nodos en el árbol, recibe una variable que apunta a la estructura
    Arbol y un entero, devuelve el nodo creado */
struct Arbol *insertar(struct Arbol *nodo, int n){
    if(nodo == NULL){ //caso base: nodo raíz
        struct Arbol *nuevo = NULL;
        nuevo = (struct Arbol*)malloc(sizeof(struct Arbol)); //solicita memoria
        nuevo -> dato = n; //asigna el dato 
        nuevo -> izquierda = NULL; //inicializa los nodos izq y der
        nuevo -> derecha = NULL;
        return nuevo;
    }

    if(n < nodo -> dato){ //si n es menor, se guarda en el nodo izquierdo
        nodo -> izquierda = insertar(nodo->izquierda, n);
    } else{//si es mayor, se guarda en el nodo derecho
        nodo -> derecha = insertar(nodo->derecha, n);
    }

    return nodo;
}

/*  Esta funcion realiza un recorrido ascendente en el árbol, primero recorremos a la 
    izquierda, luego la raíz, y finalmente la derecha. Además lo va guardando en nuestro 
    arreglo reemplazando los elementos desordenados por los elementos ya ordenados. */
void guardarRecorridoInOrden(struct Arbol *nodo, int *arreglo){
    if(nodo != NULL){
        guardarRecorridoInOrden(nodo->izquierda,arreglo);
        arreglo[aux++] = nodo->dato; 
        guardarRecorridoInOrden(nodo->derecha,arreglo);
    }
}
