#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    int i, k, nInstru=0, n, j;
    int *s, *s2;
    s = (int *)malloc(500000*sizeof(int));
    s2 = (int *)malloc(500000*sizeof(int));

    if(argc != 2)
        exit(1);

    n = atoi(argv[1]);

    for(i=n-1,j=0,nInstru+=2;i>=0;i--,j++,nInstru+=2){
        nInstru++; //Condicional TRUE
        s2[j] = s[i]; nInstru++;
        nInstru++; //Salto TRUE
    }
    nInstru++; //Salto FALSE
    nInstru++; //Comparacion FALSE


    for(k=0,nInstru++;k<n;k++,nInstru++){
        nInstru++; //Condicional TRUE
        s[i] = s2[i]; nInstru++;
        nInstru++; //Saltos TRUE

    }
    nInstru++; //Salto FALSE
    nInstru++; //Comparacion FALSE

    printf("\nInstrucciones: %d", nInstru);


    return 0;
}