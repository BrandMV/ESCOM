#include <stdlib.h>
#include <stdio.h>

/*
    En este mejor caso recibimos los numeros de un archivo cuyos dos nmeros mayores estan al inciio de tal archivo
*/
int main(int argc, char **argv){
    int n=0, i=0, mayor2, mayor1, res=0, j, aux;
    int *A;int cont = 0; //variable para contar numero de operaciones

    if(argc != 2 || A == NULL)
        exit(0);

    n = atoi(argv[1]); //recibimos los n numeros del arreglo por consola
    A = malloc(n*sizeof(int)); //arreglo dinamico

    //leemos los n numeros de un archivo
    for(i=0;i<n;i++){
        scanf("%d", &A[i]);
    }

    if(A[0] > A[1]){
        cont++; //comparacion if
        mayor1 = A[0]; cont++; //Asignacion
        mayor2 = A[1]; cont++; //Asignacion
    }else{
        cont++;
        mayor1 = A[1]; cont++; //Asignacion
        mayor2 = A[0]; cont++; //Asignacion
    }
    i = 2;

    while(i < n){
        cont++; // comparacion if
        if(A[i] > mayor1){
            mayor2 = mayor1; cont++; //Asignacion
            mayor1 = A[i]; cont++; //Asignacion
        }else{
            cont++; //comparacion else if
            if(A[i] > mayor2){
                mayor2 = A[i]; cont++; //Asignacion
            }
        }
        i = i + 1;
    }
    printf("\nNumero de operaciones: %d", cont);
    res = mayor1 * mayor2;

    return 0;
}
