// ---------------------------- DEFINICIÓN DE ESTRUCTURAS ------------------------------
/*Estructura de árgol que contendrá cada nodo de los mismos*/
typedef struct arbol
{
    unsigned long frec;     //frecuencia de aparición sobre el archivo
    unsigned char dato;     //byte en específico sobre el archivo
    struct arbol *izq;      //puntero al hijo izquierdo
    struct arbol *der;      //puntero al hijo derecho 
} arbol;

/*Estructura de lista que contendrá los nodos de árboles (raíces) para su posterior creación del árbol final*/
typedef struct lista
{
    arbol *ar;
    struct lista *siguiente;
} lista;


// ------------------------- DEFINICIÓN DE VARIABLES GLOBALES ---------------------------
char archivo[50];  //variable que almacena el nombre del archivo a leer
unsigned char *arregloBitsTemp;                 //variable para guardar los códios de bits de cada byte del archivo (temporalmente)
unsigned char caracter;                         //variable para cada caracter (byte) a codificar en el árbol
int altura = 0;                                 //variable para la altura del arbol
unsigned char codigosHojas[256][256] = {0};     //variable para el código de cada caracter
char nivelHojas[256] = {0};                     //variable para la longitud del código de cada caracter
unsigned long frecuencias[256] = {0};           //arreglo de 256 posiciones, donde cada posicion representa un caracter, inicializamos todos en 0 para decodificador
unsigned long frecuenciasTotal = 0;             //acumula el total de las frecuencias de los caracteres (bytes)


// ------------------------------ DEFINICIÓN DE FUNCIONES --------------------------------
/*Funciones para el manejo de archivo original y de frecuencias*/
unsigned long detallesArchivo(FILE *cod);
void escribirArchivoFrecuencias(lista *l);
void decodificarArchivo(unsigned char *datos, unsigned long tam, arbol *raiz, char *nombre);

/*Funciones para el manejo de la lista*/
void agregarLista(lista **l, arbol *a);
void mergeSort(lista **l);

/*Funciones para el manejo del árbol*/
lista *mezcla(lista *a, lista *b);
void sublistas(lista *l, lista **delante, lista **atras);
lista *crearArbol(lista *l);
arbol *unirArboles(arbol *aMayor, arbol *aMenor);
int alturaArbol(arbol *a);
int codificarHojas(arbol *nodo, int nivel, unsigned char *arregloBitsTemp);