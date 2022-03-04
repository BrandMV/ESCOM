#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) (a > b)? a : b;     //* Macro para encontrar el mayo de dos valores
//*Función para revertir una cadena usando punteros
char *rev(char *str)
{
    char *p1, *p2;

    if (! str || ! *str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2){
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
    }
    return str;
}

int lcs(int longA, int longB, char A[], char B[]){
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

    return longA - longitud[longA][longB];                                              //* Retornamos el valor final que es el valor de la subsecuencia comun mas larga
}

int main(int argc, char const *argv[])
{
    int i;                                          //* Variable para loop
    int t;                                          //* Variable para los casos de prueba
    scanf("%d", &t);                                //* Leemos los casos de prueba  
    char S[6099];                                   //* Variable para la cadena
    char saux[6099];                                //* Variable para cadena auxiliar

    //* Ciclo que va leyendo las cadenas de acuerdo al número de casos de prueba
    for(i=0;i<t;i++){
        scanf("%s", S);                             //* Leemos la cadena
        strcpy(saux,S);                             //* Copiamos la cadena leida en un auxiliar
        rev(saux);                                  //* Revertimos la cadena auxiliar
        int longS = strlen(S);                      //* Obtenemos la longitud de la cadena S
        int longSaux = strlen(saux);                //* Obtenemos la longitud de la cadena S

        printf("%d\n", lcs(longS,longSaux,saux,S));
    }

    return 0;
}
