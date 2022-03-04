#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    int i, n, nInstru=0;
    int *A, z;
    if(argc != 2)
        exit(1);

    n = atoi(argv[1]);
    A = (int *)malloc(40000*sizeof(int));

    int polinomio = 0; nInstru++;
    for(i=0, nInstru++;i<=n;i++, nInstru++) {
        nInstru++; //Condicional TRUE en i
        polinomio = polinomio*z+A[n-i]; nInstru+=4;
        nInstru++; //Saltos TRUE en i     
    }

    nInstru++; //Salto FALSE en i
    nInstru++; //Comparacion FALSE en i           

    printf("\nInstrucciones: %d", nInstru);
                                
    return 0;
}