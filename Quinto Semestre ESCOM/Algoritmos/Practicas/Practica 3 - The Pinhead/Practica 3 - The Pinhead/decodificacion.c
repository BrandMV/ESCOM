/*****************************************************************
	Decodificación mediante el algoritmo de Huffman 
	Este programa se encarga de decodificar un archivo de binario en un 
    archivo de cualquier tipo usando el algoritmo de Huffman, este pre-
    viamente codificado con otro programa.
	
    Fecha: 04/11/2021
	Version: 1.0 
	Autores:
			-Martinez Ruiz Alfredo
			-Mendez Castañeda Aurora
			-Mendez Hipolito Emilio
			-Meza Vargas Brandon David

*****************************************************************/

/*****************************************************************
    DECLARACIÓN DE LIBREREÍAS
*****************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/stat.h>
#include "definiciones.h"
#include <unistd.h>
#include "tiempo.h"

/*****************************************************************
    FUNCIÓN PRINCIPAL
*****************************************************************/
int main(int argc, char const *argv[])
{   
    // ----------------------- DECLARACIÓN DE VAIRABLES USADAS EN MAIN -----------------------
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medici�n de tiempos
    lista *l = NULL;                                    //variable para la lista
    arbol *ar;                                          //variable para el arbol
    unsigned char caracter = 0;                         //variabel caracter del archivo de frecuencias
    char *nombreArchivoFrecuencias = "frecuencias.txt"; //almacena el nombre del archivo
    char nombreArchivoCodificado[40];                   //almacena el nombre del archivo codificado
    FILE *tablaFrecuencias = NULL;                      //variable para el archivo de frecuencas
    unsigned long tam;                                  //varibale que almacena el tamaño del archivo
    long i = 0;                                         //variable para loops
    

    
    
    //******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
    
    // ------------------------------ LECTURA DEL DE FRECUENCIAS ------------------------------
    tablaFrecuencias = fopen(nombreArchivoFrecuencias, "rt");
    //comprobamos que exista el archivo
    if (tablaFrecuencias == NULL)
    { 
        perror("\nNombre incorrecto o no existe el archivo");
        exit(1); //salimos del programa
    }

    //obtenemos los detalles del archivo, en este caso el tamaño
    tam = detallesArchivo(tablaFrecuencias);


    // ----------------------------- CREAMOS LA LISTA DE FRECUENCIAS -----------------------------
    unsigned char *datos = (char *)malloc(sizeof(unsigned char) * tam);
    // leemos el archivo de frecuencias
    while (i < tam)
    {
        fread(&caracter, sizeof(unsigned char), 1, tablaFrecuencias); // Guardamos los distintos bytes
        fread(&frecuencias[caracter], sizeof(unsigned long), 1, tablaFrecuencias); //Guardamos frecuencias

        // Agregamos cada nodo a la lista
        ar = (arbol *)malloc(sizeof(arbol));
        ar->dato = caracter;              //se iguala al byte actual
        ar->frec = frecuencias[caracter]; //asignamos la frecuencia del caracter

        agregarLista(&l, ar); //agregamos al final de la lista
        frecuenciasTotal += frecuencias[caracter];
        i += 9; // Aumentamos el contador de bytes leidos
    }
    fclose(tablaFrecuencias); //cerramos el archivo


    // ------------------------- CREAMOS EL ÁRBOL Y OBETENEMOS LA ALTURA----------------------------
    l = crearArbol(l);           //se juntan los arboles de la lista en uno solo
    altura = alturaArbol(l->ar); //obtenemos la altura del arbol


    // ------------ CODIFICAMOS CADA CARACTER Y LO GUARDAMOS CADA CÓDIGO EN UN ARREGLO -------------
    // Inicializamos el arreglo temporal que guardará los códigos
    arregloBitsTemp = (unsigned char *)malloc(sizeof(unsigned char) * (altura + 1)); 
    codificarHojas(l->ar, 0, arregloBitsTemp); // Mandamos a almacenar todos los códidos de las hojas


    // ----------------------------- LECTURA DEL ARCHIVO DECODIFICADO -------------------------------
    FILE *decodificar = NULL; //variable para el archivo a decodificar
    // Leemos el nombre del archivo original y le agregamos el .dat
    printf("\nArchivo binario a decodificar: ");
    scanf("%s", nombreArchivoCodificado);

    decodificar = fopen(nombreArchivoCodificado, "rb");
    if (decodificar == NULL) //comprobamos que exista el archivo
    {                        //si el archivo es nulo
        perror("\nNombre incorrecto o no existe el archivo");
        exit(1); //salimos del programa
    }

    //obtenemos los detalles del archivo, en este caso el tamaño
    tam = detallesArchivo(decodificar);


    // -------- DECODIFICAMOS LOS ELEMENTOS DEL ARCHIVO RESPECTO A EL ARREGLO DE CÓDIGOS ----------
    //Establecemos el arreglo que guardara los bytes del archivo codificado
    unsigned char *datosCod = (char *)malloc(sizeof(char) * tam);
    fread(datosCod, sizeof(unsigned char), tam, decodificar); // Leemos el arreglo de bytes del archivo

    //Quitamos la extensión .bit para volver a generar el archivo original
    nombreArchivoCodificado[strlen(nombreArchivoCodificado) - 4] = 0;

    //mandamos a llamar a la función que hace la decodificacion, pasándole el arreglo de bytes codificados, 
    // tamaño de archivo .dat, árbol y el nombre nuevo
    decodificarArchivo(datosCod, tam, l->ar, nombreArchivoCodificado);

    fclose(decodificar); //cerramos el archivo
    
    //******************************************************************	
	//Evaluar los tiempos de ejecuci�n 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//C�lculo del tiempo de ejecuci�n del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("\n");

    return 0;
}

/*****************************************************************
    IMPLEMENTACIÓN DE FUNCIONES
*****************************************************************/
/*
    Esta función se encarga de realizar la decodificacion del archivo.
    Recibe los datos codificados, el tamaño de los datos, el primer arbol de la lista 
    y el nombre del archivo para quitarle la extension .dat

*/
void decodificarArchivo(unsigned char *datos, unsigned long tam, arbol *raiz, char *nombre)
{
    FILE *decodificado = NULL; // Variable que apuntará al archivo original
    // Variable que almacenará el número de bytes escritos en el archivo original
    long unsigned bytesEscritos = 0;    

    int bit;                   // Para ir recorriendo los bits de cada byte
    unsigned char bitCaracter; //almacena si el bit es 1 o 0 para ir recorriendo el arbol

    // Abrimos el archivo para escribir los bytes
    decodificado = fopen(nombre, "wb");


    //arbol donde almacenamos la raiz para regresar
    arbol *a = raiz;

    /*
        Este while realizará la decodificación, se itera las veces del tamaño del archivo codificado
    */
    unsigned long i = 0; //variable para recorrer todos los bytes del archivo decodificado
    while (i < tam)
    {   
        // recorremos cada bit de cada byte
        bit = 7;
        while (bit >= 0 && bytesEscritos < frecuenciasTotal)
        {

            //hacemos un corrimiento a la derecha para ir viendo cada bit del caracter y saber
            //por donde bajar en el arbol
            bitCaracter = (datos[i] & (1 << bit)) >> bit;

            // Nos desplazamos dependiendo del bit que leemos
            if (bitCaracter == 1)
                a = a->der;
            else
                a = a->izq;


            //Si encontramos el byte lo escribimos en el archivo decodificado
            if (a->der == NULL && a->izq == NULL)
            {
                unsigned char dato = a->dato;
                fwrite(&dato, sizeof(char), 1, decodificado); // Escribimos el byte
                a = raiz; //Reiniciamos el arbol a la raíz para comenzar con otro caracter
                bytesEscritos++; // Aumentamos la cantidad de bytes escritos del original    
            }
            bit--;
        }

        i++; //aumentamos i
    }

    fclose(decodificado); //Cerramos el archivo
}

int codificarHojas(arbol *nodo, int nivel, unsigned char *arregloBitsTemp)
{
    // Si el nodo actual no está vacío
    if (nodo != NULL)
    {
        // En caso de que ya haya encontrado la hoja que contiene al caracter
        if (nodo->der == NULL && nodo->izq == NULL)
        {
            // Guardamos todo el codigo del caracter
            for (int i = 0; i < nivel; i++)
            {
                // copiamos el arreglo de bits en el arreglo de bits de la hoja
                codigosHojas[nodo->dato][i] = arregloBitsTemp[i];
            }
            // Copiamos la longitud del codigo
            nivelHojas[nodo->dato] = nivel;

            return 0;
        }
        arregloBitsTemp[nivel] = 1;
        codificarHojas(nodo->der, nivel + 1, arregloBitsTemp);

        arregloBitsTemp[nivel] = 0;
        codificarHojas(nodo->izq, nivel + 1, arregloBitsTemp);
    }
}

/*
    Función para obtener los detalles del archivo, en este caso nos interesa el tamaño.
    Se hizo uso de la libreria sys/stat.h.
    REcibe el archivo del que deseamos saber su tamaño
    Retorna el tamaño del archivo

*/
unsigned long detallesArchivo(FILE *cod)
{
    struct stat buffer; //estructura para recuperar atributos del archivo

    unsigned long descriptor = fileno(cod); //regresa el descriptor de archivo
    //con la llamada a la funcion fstat obtenemos detalles del archivo
    if (fstat(descriptor, &buffer) == -1)
    { //si regresa -1 hubo un error
        perror("Error en fstat");
        exit(1); //Salimos del programa
    }

    return buffer.st_size; //Retornamos el tamaño del archivo
}

/*
    Función que agrega un elemento al final de la lista
    Recibe la lista donde se insertará el elemento y el elemento a insertar
    en este caso el arbol con el dato y la frecuencia
    Retorna el nuevo elemento 
*/
void agregarLista(lista **l, arbol *a)
{
    lista *nuevoArbol, *aux;                     //creamos una variable para alamacenar el dato
    nuevoArbol = (lista *)malloc(sizeof(lista)); //le asignamos espacio al dato
    nuevoArbol->ar = a;                          //guardamos el arbol en el nuevo nodo
    nuevoArbol->siguiente = NULL;                //el siguiente nodo será igual a la lista que teniamos

    if (*l == NULL)
    {                    //verificamos si la lsita esta vacía
        *l = nuevoArbol; //agregar primer elemento
    }
    else
    {
        aux = *l;
        while (aux->siguiente != NULL)
        {                         //cuando ya hay por lo menos un elemento en la lista
            aux = aux->siguiente; //apuntamos al siguiente nodo
        }
        aux->siguiente = nuevoArbol; //agregamos un nuevo nodo al final de la lista
    }
}

/*
    Funcion que crea el arbol a partir de ir uniendo dos arboles de la lista 
    y sumando sus frecuencias.
    Recibe la lista que contiene los arboles que se juntarán.
    Regresa la lista con un solo arbol que fue unido
*/
lista *crearArbol(lista *l)
{
    //vamos recorriendo  la lista mientras el siguiente nodo no sea nulo
    while (l->siguiente != NULL)
    {
        //Establecemos dos listas, una ira almacenando el arbol unido y otra que servira como auxilair
        lista *arbolUnido = l;
        lista *aux = l;
        //Como iremos comparando de dos en dos los arboles, recorremos la lista en dos elementos
        l = l->siguiente->siguiente;

        //mandamos a llamar la función que une los arboles
        arbolUnido->ar = unirArboles(arbolUnido->siguiente->ar, arbolUnido->ar);

        /*
            SI la lista es nula o si la frecuencia del arbol unido anteriormente es menor
            a la frecuencia del arbol, haremos que el nuevo elemento de la lista sea el elemento
            desde el cual se recorrio la lista y la lista será el elemento unido
        */
        if (l == NULL || arbolUnido->ar->frec <= l->ar->frec)
        {
            arbolUnido->siguiente = l; //el siguiente elemento será al que apunto al recorrer
            l = arbolUnido;            //la lista tserá el arbol unido
        }
        /*
            Si la lista no es nula y la frecuencia del arbol unido es mayor a la del arbol
            haremos uso del auxiliar guardando ahi la lista y avanzando hasta que se encuentre
            la posicion correcta del nuevo nodo que es el arbol unido.
        */
        if (l != NULL && arbolUnido->ar->frec > l->ar->frec)
        {
            aux = l;
            //Recorremos el auxiliar hasta que sea nulo o se encuentre un elemento mayor al arbol unido
            while (aux->siguiente != NULL && arbolUnido->ar->frec > aux->ar->frec)
            {
                aux = aux->siguiente; //avanzamos en el auxiliar
            }
            arbolUnido->siguiente = aux->siguiente; //asigna la posicion donde se guardara el nuevo arbol
            aux->siguiente = arbolUnido;            //almacenamos el nuevo arbol en la posicion
        }
    }

    return l; //retornamos la lista unida
}

/*
    Esta función une los arboles, para hacer esto se crea un nuevo arbol y se almacena en el
    la frecuencia del arbol mayor y menor para asi formar un solo arbol
    Recibe el arbol con el caracter con mayor frecuencia y un arbol con el caracter de menor frecuencia
    Retorna el nuevo arbol que se almacenara en la lista
*/
arbol *unirArboles(arbol *aMayor, arbol *aMenor)
{
    arbol *nuevo = (arbol *)malloc(sizeof(arbol)); //Creamos el nuevo arbol

    nuevo->frec = aMayor->frec + aMenor->frec; //Sumamos las frecuencias del arbol
    nuevo->izq = aMenor;                       //se le asigna a la izquierda el arbol con menor frecuencia
    nuevo->der = aMayor;                       //se le asigna a la derecha el arbol con mayor frecuencia

    return nuevo; //Retornamos el nuevo arbol
}

/*
    FUnción para calcular la altura del arbol.
    Recibe la altura del arbol del que se desea saber la altura
    Devuelve la ltura del arbol
*/
int alturaArbol(arbol *a)
{
    //Si no hay elemntos la altura sera 0
    if (!a)
    {
        return 0;
    }
    int alt = 0; //para almacenar la altura

    //calculamos la altura de la derecha
    int alturaDerecha = alturaArbol(a->der);
    //calculamos la altura de la izquierda
    int alturaIzquierda = alturaArbol(a->izq);

    //la altura mayor se guardará como la altura del arbol
    alt = alturaIzquierda > alturaDerecha ? alturaIzquierda + 1 : alturaDerecha + 1;

    return alt; //Retornamos la altura
}
