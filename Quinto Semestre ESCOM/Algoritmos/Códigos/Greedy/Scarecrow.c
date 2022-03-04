#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *campo;
char *campoAux;

int scarecrow(){
    int i = 0;      //*Variable para loops
    int total = 0;  //*Total de esptantapájaros
    int N;          //*Tamaño del campo

    scanf("%d", &N);                    //*Leemos el tamaño del campo
    campo = malloc(N*sizeof(char)+1);   //*Le asignamos memoria al campo
    scanf("%s", campo);                 //*Leemos el campo {.  #}
    campoAux = calloc(N,sizeof(char));  //*Usamos calloc para asignar memoria iniciando en 0's
    total = 0;                          //*Inicializamos el total de espantapajaros

    //*Recorremos el campo hasta dos signos menos
    for(i=0; i<N-2; i++)
        //*Si nos encontramos con un . podemos poner un espantajaros, ademas debe estar
        //*disponible el espacio, esto lo sabemos si tenemos un 0 en el auxiliar
        if(campo[i] == '.' && campoAux[i] == 0){
            total++;            //*Ponemos el espantapajaros
            campoAux[i+1] = 1;  //*Indicamos que el espacio se ha ocupado
            campoAux[i+2] = 1;  //*Como ocupa dos lugares ocupamos otro
        }
    //*Si el campo en el tamaño N-2 tenemos otro punto y no se ha ocupado tambien colocamos uno ahi
    if(campo[N-2] == '.' && campoAux[N-2] == 0){
        total++;            //*Aumentamos la cantidad de espantapajaro
        campoAux[i+1] = 1;  //*Indicamos que se ha ocupado un espacio
    }

    //*Si en la penultima posicion hay un punto y no se ha ocupado también ponemos un espantapajaros
    if(campo[N-1] == '.' && campoAux[N-1] == 0)
        total++;

    printf("%d\n", total);      //*Imprimimos el resultado

    free(campo);                //*Liberamos memoria
    free(campoAux);             //*Liberamos memoria
}


int main(){
    int T = 0;          //*Numero de casos
    scanf("%d", &T);    //*Leemos los casos
    while(T--){ 
        scarecrow();    //*Ejecutamos la función
    }

    return 0;
}