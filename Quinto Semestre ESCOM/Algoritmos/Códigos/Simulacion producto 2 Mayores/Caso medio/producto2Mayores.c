#include <stdlib.h>
#include <stdio.h>

#define N_VECES 10000 //numero de iteraciones para encontrar el promedio

/*
    En este caso medio se va a iterar el algoritmo para encontrar los numeros mayores del arreglo.
    Se creara un arreglo con numeros al azar por cada iteracion
*/

int main(int argc, char **argv){
    int n=0, i=0, mayor2, mayor1, res=0, j, aux;
    int cont = 0; //variable para contar numero de operaciones
    int *A;
    float promedio = 0;

    if(argc != 2 || A == NULL)
        exit(0);
    n = atoi(argv[1]); //recibimos los n numeros del arreglo por consola
    A = malloc(n*sizeof(int)); //arreglo dinamico

    for(j=0;j<N_VECES;j++){
        i = 0; cont = 0;
        //creamos un arreglo con numeros al azar
        for(i=0;i<n;i++){
            A[i] = rand() % 30000 + 1;
        }

        if(A[0] > A[1]){
            cont++; // comparacion if
            mayor1 = A[0]; cont++; //Asignacion
            mayor2 = A[1]; cont++; //Asignacion
        }else{
            cont++; // comparacion if
            mayor1 = A[1]; cont++; //Asignacion
            mayor2 = A[0]; cont++; //Asignacion
        }
        i = 2;
        while(i < n){
            cont++; // comparacion if
            if(A[i] > mayor1 || A[i] == mayor1 ){
                mayor2 = mayor1; cont++; //Asignacion
                mayor1 = A[i]; cont++; //Asignacion
            }else{
                cont++; //comparacion else if
                if(A[i] > mayor2 || A[i] > mayor2){
                    mayor2 = A[i]; cont++; //Asignacion
                }
            }
            i = i + 1;
        }
        promedio = promedio + (float)cont; //sumamos el promedio
    }
    promedio = promedio / N_VECES; //calculamos el promedio
    printf("\nPromedio: %f operaciones", promedio);
    printf("\nNumero de operaciones: %d", cont);

    res = mayor1 * mayor2;

    return 0;
}
