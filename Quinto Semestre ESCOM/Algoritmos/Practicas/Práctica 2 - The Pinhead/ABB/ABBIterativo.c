//*****************************************************************
/*
	Algoritmo de Búsqueda con un árbol binario de búsqueda (ABB)
	Este programa muestra el algoritmo de busqueda con un árbol binario 
    de búsqueda para hacer la medición promedio del tiempo real que toma hacer varias busquedas
	con distinto tamaño de problema
	
    Fecha: 23/09/2021
	Version: 2.0 ciclo para realizar busquedas y sacar promedio
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
//DEFINIENDO LA ESTRUCTURA DEL ARBOL
//*****************************************************************

struct abb{
    int dato; //guarda los números del arbol
    struct abb *derecha, *izquierda; //para los subarboles der e izq
};

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void llenarArreglo(int* arreglo, int n);
void imprimirArreglo(int* arreglo, int n);
struct abb* nuevoNodo(int dato);
struct abb* insertar(struct abb* nodo, int dato);
void busqueda(struct abb* root, int dato);
void inorder(struct abb* root);

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
	struct abb *arbol = NULL; //variable que apunta a la estructura Arbol y lo inicia con NULL
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

	//con ayuda de un for insertamos los elementos del arreglo en el arbol
	for(i=0; i<n; i++)
        arbol = insertar(arbol, arreglo[i]);

	//función inorder solo para verificar que el arbol se lleno correctamente
	// inorder(arbol);

	//******************************************************************	
	
	
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
		busqueda(arbol,numerosBuscar[i]);
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
	Funcion que crea los nodos del arbol, asigna memoria al nuevo nodo, ademas de asignar el dato
	a ese nodo e indicar que el nodo de la derecha e izquierda serán nulos.
	Esta función solo recibe el dato que se colocara en ese nodo y retorna el nuevo nodo creado.
*/
struct abb* nuevoNodo(int dato){
	//Asignamos memoria al nuevo nodo
    struct abb* nuevo = (struct abb*)malloc(sizeof(struct abb));
    nuevo->dato = dato; //Asignamos el nodo
    nuevo->derecha = nuevo->izquierda = NULL; //Apuntamos a nulo el sub arbol derecho e izquierdo
    return nuevo; //Retornamos el nuevo nodo
}

/*
	Función insertar del ABB iterativa.
	Para hacer iterativa esta función se hace uso de un auxiliar para recorrer los nodos del arbol.
	Para este recorrido se usa un while que termina cuando un nuevo nodo es insertado en el arbol.
	Recibe el arbol donde se insertaran los nodos, y el dato a insertar en cada nodo del arbol.
*/
struct abb* insertar(struct abb* nodo, int dato){

    struct abb *aux = nodo; //variable auxiliar para ir recorriendo el abb
	int i=1; //variable pde control para el while
	/*
		Si el nodo es nulo, significa que el arbol esta vacio, por lo tanto se crea un nuevo nodo, este será
		la raíz de nuestro arbol
	*/
    if(aux == NULL)
        return nuevoNodo(dato); //Creamos el nodo

	//Ciclo while para hacer iterativo el algoritmo
    while(i){

		/*
			Si el dato es menor al dato de la raiz del arbol, se crea un nodo a la izquierda, para esto
			primero se verifica si el nodo de la izquierda es nulo. Si el nodo de la izquierda no es nulo
			creamos un subarbol a partir de este nodo.
			Lo mismo pasa cuando el dato es mayor que el dato de la raiz del arbol, solo que en lugar de
			crear nodos a la izquierda, se hace a la derecha
		*/
        if(dato < aux->dato)
            if(aux->izquierda == NULL){
                aux->izquierda = nuevoNodo(dato);
				i = 0; //para terminar el while
			} else aux = aux->izquierda;
        else
			if(dato > aux->dato)
                if(aux->derecha == NULL){
                    aux->derecha = nuevoNodo(dato);
					i = 0; //para terminar el while
				} else aux = aux->derecha;
		
    }


    return nodo; //Retornamos el nodo para construir el arbol
}

/*
	Función iterativa de busqueda para el ABB, esta función recibe la estrucutra donde vamos a buscar
	en este caso, el arbol ya creado, para hacerlo iterativo se hace un while que se acaba cuando
	ya no hay más nodos por recorrer en el arbol.
	Recibe el arbol donde se hará la busqueda y el dato a buscar.
	No regresa nada, pues solo indica cuando el dato es encontrado
*/
void busqueda(struct abb* root, int dato){

	//while que acaba cuando no hay más por buscar
    while(root != NULL){
		/*
			si el dato a buscar es mayor que el dato de la raíz del arbol, nos desplazamos hacia
			el sub arbol derecho.
			Si el dato es menor, nos desplazamos hacia el sub arbol izquierdo.
			Lo anterior de forma sucesiva, cuando no se cumple ninguna de las condiciones anteriores
			significa que el dato es igual al dato de la raiz del arbol o sub arbol, por lo tanto, es encontrado
		*/
        if(root->dato < dato)
            root = root->derecha;
		else if(root->dato > dato)
            root = root->izquierda;   
			else{
				encontrado = 1; //el dato es encontrado
				break;
			}
    }

}

/*  
	Esta funcion realiza un recorrido ascendente en el árbol, primero recorremos a la 
    izquierda, luego la raíz, y finalmente la derecha. Solo se hace uso de esta función para
	verficar que los datos del arreglo esten en el arbol y no haya problemas en la busqueda.
	Recibe la estructura de arbol a recorrer y no regresa nada
*/
void inorder(struct abb* root){
	if(root != NULL){
		inorder(root->izquierda);
		printf("%d \n", root->dato);
		inorder(root->derecha);
	}
}