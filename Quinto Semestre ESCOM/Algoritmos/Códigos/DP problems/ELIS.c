#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a > b)? a : b;     //* Macro para encontrar el mayo de dos valores

//* Funcion para qsort
int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int elis(int A[], int N, int auxNums[]){
    qsort(A,N,sizeof(int),cmpfunc);         //* Ordenamos nuestro arreglo original
    int m = N;                              //* m será la longitud del arreglo original
    int longitud[N+1][m+1];                 //* Arreglo bidimensional para guardar las longitudes
    int i,j;                                //* Variables para loops
    /*
        *Ordenando el arreglo original podemos pasar este problema comparandolo con el mismo arreglo pero sin ordenar
    */
    /*
        *El siguiente for es para la solución bottom up, recorre la longitud del arreglo
    */
    for(i=0; i<=N; i++){
        for(j=0;j<=m;j++){
            if(i == 0 || j == 0)                                                //* En caso de que las longitudes sean 0 las cadenas no tendran lcs
                longitud[i][j] = 0;
            else if(A[i-1] == auxNums[j-1])                                           //* Si los ultimos caracteres de las cadenas son iguales, se encuentra lcs de
                    longitud[i][j] = longitud[i-1][j-1] + 1;                    //* las cadenas anteriores de A y B
                else
                    longitud[i][j] = MAX(longitud[i-1][j], longitud[i][j-1]);   //* Retornamos el mayor de las subcadenas de los elementos de A o de los elementos de B
        }
    }
    return longitud[N][m];   
}
int main()
{
    int N, i;                               //*  Variable para loop y N para longitud del arreglo
    scanf("%d", &N);                        //*  leemos la longitud

    int A[N];                               //* Arreglo con los numeros
    int auxNums[N];                         //* Auxiliar para resolver el problema    
    for(i=0;i<N;i++){                       //* Leemos los numeros
        scanf("%d",&A[i]);                  
        auxNums[i] = A[i];                  //* Se va copiando en el auxiliar
    }
    printf("%d",elis(A, N, auxNums));
    return 0;
}
