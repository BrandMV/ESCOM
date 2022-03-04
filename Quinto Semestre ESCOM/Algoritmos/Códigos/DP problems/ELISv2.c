#include <stdio.h>
#include <stdlib.h>

int elis(int A[], int N){
    int elis[N];            	                        //* Variable apra ir guardando respuesta a subproblemas
    int i, j;
    /*
        *El siguiente for recorre la longitud del arreglo dos veces, de esta forma se va determinando
        *las soluciones
    */ 
    for(i=0; i<N;i++){
        elis[i] = 1;                                    //* Se inicializa con el caso base que es 1
        for(j=0;j<i;j++){
            if(A[i] > A[j] && elis[i] < elis[j] + 1)    //* Si el numero actual
                elis[i] = elis[j] + 1;
        }
    }

    //* Loop para obtener el maximo de los valores de elis
    int max = 0;
    for(i=0; i<N;i++)
        if(max < elis[i])
            max = elis[i];

    return max;
}


int main(int argc, char const *argv[])
{
    int N, i;                           //*  Variable para loop y N para longitud del arreglo
    scanf("%d", &N);                    //*  leemos la longitud

    int A[N];                           //* Arreglo con los numeros
    for(i=0;i<N;i++)                    //* Leemos los numeros
        scanf("%d",&A[i]);
    
    printf("%d",elis(A, N));        

    return 0;
}
