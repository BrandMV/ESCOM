#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (a > b)? a : b;     //* Macro para encontrar el mayo de dos valores

 //*    Estrucutra para el item de la mochila con un tamaño y valor
typedef struct item{
    int tam;        //* Tamaño del articulo
    int valor;      //* Beneficio del articulo
} Item;

int knapsack(Item elementos[], int N, int S){
    int i, j;                                   //* Varibales para loops
    int mochila[N+1][S+1];                      //* Variable que guarda la longitud de los items y la capacidad, la tabla
    
    //* Ciclos para construir la tabla en la manera bottom up
    for(i=0;i<=N;i++){
        for(j=0;j<=S;j++){
            if(i == 0 || j == 0)                //* Si no hay elementos será 0 
                mochila[i][j] = 0;   
            /*
                *Si el tamaño del articulo es de volumen menor o igual al que permite la mochila
                *entonces vamos a sumar el beneficio del articulo actual mas el beneficio que ya teniamos
                *recorriendo la tabla de acuerdo al tamaño del articulo actual
                *Se almacena en la casilla actual [i,j] el que maximice el beneficio de meter el articulo anterior o el actual
            */
            else if(elementos[i-1].tam <= j){
                    mochila[i][j] = MAX(elementos[i-1].valor + mochila[i-1][j-elementos[i-1].tam], mochila[i-1][j]);
                } else{
                    //* Si no cabe en la mochila el articulo el beneficio será el mismo para las demás casillas
                    mochila[i][j] = mochila[i-1][j];
                }
        }
    }

    //* Retornamos el mayor beneficio resultante
    return mochila[N][S];
}

int main()
{
    int i;                      //* Variable para loops
    int S;                      //* Variable para la capacidad
    int N;                      //* Variable para la cantidad de items
    scanf("%d", &S);            //* Leemos la capacidad
    scanf("%d", &N);            //* Leemos la cantidad de items
    Item elementos[N];          //* Arreglo de items de longitud N
    //* Leemos los elementos
    for(i=0;i<N;i++){
        scanf("%d",&elementos[i].tam);
        scanf("%d",&elementos[i].valor);
    }

    printf("%d", knapsack(elementos, N, S));

    return 0;
}
