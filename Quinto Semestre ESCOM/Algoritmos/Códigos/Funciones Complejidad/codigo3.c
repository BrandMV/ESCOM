#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    int i, j, k, n, nInstru=0;
    int *A, *B, *C;

    A = (int *)malloc(500000*sizeof(int));
    B = (int *)malloc(500000*sizeof(int));
    C = (int *)malloc(500000*sizeof(int));

    if(argc != 2)
        exit(1);

    n = atoi(argv[1]);

    for(i=1, nInstru++; i<=n; i++, nInstru++){
        nInstru++; //Condicional TRUE en i
        for (j=1, nInstru++; j<=n; j++, nInstru++){
            nInstru++; //Condicional TRUE en j
            C[i,j] = 0; nInstru++;
            for(k=1, nInstru++; k<=n; k++, nInstru++){
                nInstru++; //Condicional TRUE en k
                C[i,j] = C[i,j] + A[i,k] * B[k,j]; nInstru += 3;
                nInstru++; //Saltos TRUE k
            }
            nInstru++; //Salto FALSE k
            nInstru++; //Condicional FALSE k
            nInstru++; //Salto TRUE j
        }

        nInstru++; //Salto FALSE j
        nInstru++; //Condicional FALSE j
        nInstru++; //Saltos TRUE i
    }
    nInstru++; //Salto FALSE i
    nInstru++; // Comparacion FALSE i
    printf("\nInstrucciones: %d", nInstru);

    return 0;
}