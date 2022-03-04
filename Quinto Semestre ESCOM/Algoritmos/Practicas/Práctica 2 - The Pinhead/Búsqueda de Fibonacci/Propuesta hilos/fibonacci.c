//*****************************************************************
/*
	Algoritmo de Búsqueda de Fibonacci con hilos
	Este programa muestra el algoritmo de busqueda de Fibonacci implementando hilos para hacer la medición promedio del tiempo real que toma hacer varias busquedas
	con distinto tamaño de problema
	
    Fecha: 02/10/2021
	Version: 3.0 ciclo para realizar busquedas y sacar promedio usando hilos
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
#include <pthread.h>
#include <stdlib.h>
#include "tiempo.h"


//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void llenarArreglo(int* arreglo, int n);
void imprimirArreglo(int* arreglo, int n);
void *busquedaFibonacci(void *arg);
void declararIndices(int *indices, int tam);
int min(int x, int y);

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************
int encontrado = 0; //variable global para indicar si se encuentra el elemento
// -1 = no encontrado    [0, n] = encontrado
int NumThreads;			//Número de hilos
int n;  //n determina el tamaño del problema del algoritmo dado por argumento al ejecutar
int x; // Determina el valor que se va buscar en el momento
int *arreglo; //Variable donde se guardará el arreglo principal de números


//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main(int argc, char* argv[]){
    //******************************************************************
	//Variables del main
	//******************************************************************
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	double promedioWtime = 0; //variable para calcular el tiempo promedio de todas las busquedas
    int i, j; //Variables para los loops que recorren el arreglo de números e hilos
    int tam; // Variable para saber el tamaño del arreglo de cada hilo    
    int limites[2];// Variable auxiliar para almacenar los límites del arreglo de cada hilo 
    int numerosBuscar[] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 1295390003,450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852,0}; //Arreglo que contiene los numeros que se buscarán
	int tamNumerosBuscar = sizeof numerosBuscar / sizeof *numerosBuscar; //Obtenemos el tamaño del arreglo de los numeros a buscar
    pthread_t *threads; // Variable que almacenará el arreglo de hilos

	//******************************************************************
	//Recepción y decodificación de argumentos
	//******************************************************************
    //Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=3){
		printf("\nIndique el tamanio del algoritmo y de hilos - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	}
	else{
        // Tomamos el segundo argumento como el tamaño y el tercero como el número de hilos
		n = atoi(argv[1]);
	    NumThreads = atoi(argv[2]); // Obtenemos el numero de hilos
        tam = n/NumThreads; // Calculamos el tamaño de dada arreglo de cada hilo
	}

	//Establecemos el tamaño del arreglo de acuerdo al tamaño n dado por argumento al ejecutar
	arreglo = malloc(n * sizeof(int));

	// Mandamos a llamar a la función que llena el arreglo pasando por referencia el arreglo y por valor la n
	llenarArreglo(arreglo, n);

    //Algoritmo de Búsqueda de Fibonacci con hilos
	/*
		Este algoritmo funciona de modo que, genera las posiciones sobre la serie de fibonacci en los primeros valores (0, 1, 1). Después va recorriendo los valores hasta que encuentra un número sobre la serie que sea igual o mayor al tamanio del arreglo.
        El mismo tiempo guardamos los dos valores previos a ese número sobre la serie.

        Después entramos a un ciclo de comparación que se ejecuta mientras el número de fibonacci (el más grande) sea mayor a uno.

        En este ciclo de comparación checamos si el número a buscar es menor, mayor o igual al valor en i (dicho valor se obtiene de sumar una variable inicial en -1 más el valor del número más pequeño de los 3 escogidos en ese momento de la serie, o la última posición).

        - En caso se que el valor de x sea mayor a lo que hay en i, se procederá a disminuir en 1 posición los 3 números escogidos de fibonacci, y volvemos a iterar ahora con el inicio en i.
        - En caso de que el valor de x sea menor a lo que hay en i, se procederá a disminuir en 2 posiciones los 3 números escogidos de fibonacci, y volvemos a iterar.
        - En caso de que sea igual, entonces encontramos la posición del número que buscamos.

        Finalmente, si los números tomados de fibonacci llegan a ser los primeros de la serie, decimos que ya no hay más valores para comparar y sale del ciclo.

        Por último, hacemos una última comprobación comparando el último elemento del arreglo con el valor de x.

        Si no se encuentra en el último, entonces sí decimos que el número no está en el arreglo y devolvemos -1.
        
        NOTA: Esta modificación de hilos funciona que le envía al algoritmo de búsqueda solo una parte del arreglo, de modo que cada hilo tendrá un arreglo más pequeño y del mismo tamaño que del resto de los hilos, el tamaño de los subarreglos dependen del tamaño del arreglo y del número de hilos implementados (que son ingresados también en la ejecución)
    */
	//*
    
    //******************************************************************
    // COMENZAMOS LA BÚSQUEDA DE CADA UNO DE LOS NÚMEROS
    //******************************************************************
	for(i = 0; i < tamNumerosBuscar; i++){
        threads = malloc(NumThreads*sizeof(pthread_t)); // Asignamos espacio para los hilos
        int indices[2 * NumThreads]; // Declaramos el arreglo para los índices del subarreglo para cada hilo        
        declararIndices(indices, tam); // Declaramos los índices del arreglo de cada hilo
        x = numerosBuscar[i]; // Asignamos el valor que vamos a buscar en los arreglos 

		encontrado = -1; // Declaramos en cada iteración que no se ha encontrado
		wtime1 = wtime0 = 0.0; // Reiniciamos el tiempo en cada busqueda

		//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
		//******************************************************************	
		uswtime(&utime0, &stime0, &wtime0); // Iniciamos el contador
		//******************************************************************  

        // Creamos cada hilo y le mandamos al algoritmo los índices  
        for (j = 1; j < NumThreads; j++){
            // Establecemos los límites del subarreglo
            limites[0] = indices[j*2];
            limites[1] = indices[j*2 + 1];

            if (pthread_create (&threads[j], NULL, busquedaFibonacci, (void *)limites) != 0 ){
                perror("El thread no  pudo crearse");
                exit(-1);
            }
        }
        // Establecemos los limites del subarreglo 0 (el principal en caso de que solo haya 1)
        limites[0] = indices[0];
        limites[1] = indices[1];
	    busquedaFibonacci((void *)limites);

        //Esperar a que terminen los threads (busquedaFibonacci)
	    for (j=1; j<NumThreads; j++) pthread_join (threads[j], NULL);

		//******************************************************************	
		//Evaluar los tiempos de ejecución 
		//******************************************************************
		uswtime(&utime1, &stime1, &wtime1);
		//vamos sumando los tiempos que hace en cada suma para al final sacar el promedio
		promedioWtime += (wtime1 - wtime0); 
		// printf("%d ",numerosBuscar[i]);
		// printf((encontrado == 1) ? "Encontrado\n" : "No encontrado\n");
		//printf((encontrado != -1) ? "Encontrado\n" : "No encontrado\n");
	}
    //Cálculo del tiempo de ejecución del programa
	printf("Tamaño de problema: %d\n", n);
	printf("Promedio tiempo real %.10f s\n",  (promedioWtime/20.0));

	return 0;
}

/*
    Esta función asigna las posiciones de los limites de cada arreglo de cada hilo sobre el arreglo mayor
    Los ordena de modo que, el inicio de cada subarreglo está en las posiciones pares del arreglo "indices"
    Y el final de cada subarreglo está en las posiciones impares del arreglo "indices"
    Recibe el arreglo de índices y el tamaño de los subarreglos.
    No devuelve nada.
*/
void declararIndices(int *indices, int tam){
    int hilo = 0;
    
    for(int i = 0; i < 2*NumThreads; i+=2){
        indices[i] = 0 + tam * hilo; 
        indices[i+1] = (hilo == NumThreads -1) ? n-1 : indices[i] + tam - 1; //
        hilo++;   
    }
}

/*
    Esta función encuentra un número dentro de un arreglo que obtiene a partir de los índices ingresados sobre otro arreglo más trande
    Recibe el arreglo de limites donde está la posición de inicio y final del subarreglo
    No devuelve nada.
*/
void *busquedaFibonacci(void* arg){  
    // Obtenemos los índices y el tamaño del arreglo reducido
    int *limites = (int *) arg;
    int *arr = malloc((limites[1] - limites[0]+1)* sizeof(int));
    int n = limites[1] - limites[0]+1;
    
    // Asignamos las celdas del nuevo arreglo reducido
    int p = 0;
    for(int i = limites[0]; i <= limites[1]; i++){
        arr[p] = arreglo[i]; 
    }

    // Inicializamos los terminos de fibonacci
    int fibMNum2 = 0; // El primer término de la serie (termino m -2)
    int fibMNum1 = 1; // El segundo término de la serie (termino con m-1)
    int fibM = fibMNum2 + fibMNum1; // El término de la serie (o el termino m)

    /*
        Empezamos buscando el primer termino que es mayor o igual que el 
        tamanio del arreglo
    */
    while(fibM < n){
        fibMNum2 = fibMNum1; // Pasamos el término m-2 = m-1
        fibMNum1 = fibM; // Pasamos el término m-1 = m
        fibM = fibMNum2 + fibMNum1; // Sacamos el siguiente término
    }

    // Indicamos una posición inicial (ya que mínimo fibMNum2 será igual a 0 o 1)
    int inicio = -1;

    /*
        Mientras haya elementos para comparar, comparamos la posición del arreglo
         fibMnum2 con x. 
    */
    while(fibM > 1){
        // Comprobamos si existe la posición de fibMnum2 en el arreglo
        int i = min(inicio + fibMNum2, n-1);

        // En caso de que x sea mayor que el valor del arreglo en i, entonces partiremos
        // el arreglo desde la posición inicial a i
        if(arr[i] < x){
            // Retrocedemos los términos de la serie
            fibM = fibMNum1; // Pasamos el término m = m-1
            fibMNum1 = fibMNum2; // Pasamos el término m-1 = m-2
            fibMNum2 = fibM - fibMNum1;  // Encontramos el término previo m2 = m - m1
            inicio = i;
        }

        // En el caso de que x sea mayor que el valor del arreglo en i, entonces partiremos
        //  el arreglo desde i+1
        else if(arr[i] > x){
            // Retrocedemos los términos de la serie
            fibM = fibMNum2; // Pasamos el término m = m-2
            fibMNum1 = fibMNum1 - fibMNum2; // Pasamos el término m-1 = m-1 - m-2
            fibMNum2 = fibM - fibMNum1;  // Encontramos el término previo m2 = m - m1
        }

        // Si no es mayor ni menor, entonces es el número buscando
        else{
            encontrado = 0;
            return 0;
        }
    }

    // Cuando ya no haya más elementos que el último
    if(fibMNum1 && arr[inicio + 1] == x){
        encontrado = inicio + 1;
        return 0;
    }

    // Si no lo encontró siquiera en última posición entonces no existe
    encontrado = -1;
    return 0;
}

/*
    Esta función obtiene el menor de dos números
    Recibe los dos números
    Devuelve el número menor de ambos
*/
int min(int x, int y) { 
    return (x <= y) ? x : y; 
}

/*
	Esta función llena nuestro arreglo con n números tomados del archivo que contiene 10 millones de numeros o de la terminal en su defecto. 
	Recibe el arreglo y una n, no devuelve nada pues solo llena el arreglo.
*/
void llenarArreglo(int *arreglo, int n){
	int i = 0; // Variable para ciclo

	// Llenamos el arreglo gracias al for que va de 0 hasta antes de la n indicada por parametros al ejecutar
	for (i = 0; i < n; i++){
		scanf("%d", &arreglo[i]);
	}
}

/* Imrpime un arreglo de tamanio n
	Recibe: el tamanio del arreglo y el arreglo
	No devuelve nada
*/
void imprimirArreglo(int *A, int n){
	for(int i = 0; i < n; i++){
		printf("%d\n", A[i]);
	}
}