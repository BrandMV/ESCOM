#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a > b)? a : b;     //* Macro para encontrar el mayo de dos valores

int longestSub(int longA, int longB, char A[], char B[]){
    int i, j;                                                                   //* Variable para loops
    int longitud[longA+1][longB+1];                                             //* Arreglo bidimensional que guarda las longitudes de ambas cadenas
    /*
        *El siguiente for es para la solución bottom up, recorre las longitudes de ambas cadenas
        *de la cadena A y la cadena B
    */
    for(i=0; i<=longA; i++){
        for(j=0;j<=longB;j++){
            if(i == 0 || j == 0)                                                //* En caso de que las longitudes sean 0 las cadenas no tendran lcs
                longitud[i][j] = 0;
            else if(A[i-1] == B[j-1])                                           //* Si los ultimos caracteres de las cadenas son iguales, se encuentra lcs de
                    longitud[i][j] = longitud[i-1][j-1] + 1;                    //* las cadenas anteriores de A y B
                else
                    longitud[i][j] = MAX(longitud[i-1][j], longitud[i][j-1]);   //* Retornamos el mayor de las subcadenas de los elementos de A o de los elementos de B
        }
    }

    return longitud[longA][longB];                                              //* Retornamos el valor final que es el valor de la subsecuencia comun mas larga
}
int main()
{
    char A[10000];              //*  Primer cadena
    char B[10000];              //*  Segunda cadena 

    scanf("%s",A);              //* Leemos la primera cadena
    scanf("%s",B);              //* Leemos la segunda cadena

    int longA = strlen(A);      //* Obtenemos la longitud de la cadena A
    int longB = strlen(B);      //* Obtenemos la longitud de la cadena B

    printf("%d", longestSub(longA, longB, A, B));

    return 0;
}
