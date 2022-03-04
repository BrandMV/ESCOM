#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    int i, temp, k, j, n, nInstru=0;
    int *A;

    if(argc != 2)
        exit(1);

    n = atoi(argv[1]);

    A = (int *)malloc(40000*sizeof(int));

    for(i=1, nInstru++;i<n;i++, nInstru++) {
        nInstru++; //Condicional TRUE en i
        for(j=n, nInstru++;j>1;j/=2, nInstru++){    
            nInstru++, //Condicional TRUE en j  
            temp = A[j]; nInstru++;        
            A[j] = A[j+1]; nInstru+=2;     
            A[j+1] = temp; nInstru+=2;    
            nInstru++; //saltos TRUE j                   
        }           

        nInstru++; //Saltos FALSE de j
        nInstru++; //Condicional FALSE en j
        nInstru++; //Saltos TRUE en i     
    }

    nInstru++; //Salto FALSE en i
    nInstru++; //Comparacion FALSE en i           

    printf("\nInstrucciones: %d", nInstru);
                                

    free(A);

    return 0;
}