#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    int n, nInstru = 0, i, j, temp;
    int *lista = (int *)malloc(500000*sizeof(int));


    if(argc != 2)
        exit(1);

    n = atoi(argv[1]);

    for(i=1,nInstru++;i<n;i++,nInstru++){
        nInstru++; //Condicional TRUE i
        for(j=0,nInstru++; j<n-1; j++, nInstru++){
            nInstru++; //Condicional TRUE j
            if(lista[j]>lista[j+1], nInstru+=2){
                
                nInstru++; // Condicional TRUE IF
                temp = lista[j];nInstru++;
                lista[j] = lista[j+1];nInstru+=2;
                lista[j+1] = temp; nInstru+=2;
                nInstru++; // Salto TRUE IF
            }

            nInstru++; // Saltos TRUE j
        }
        nInstru++; //Saltos FALSE de j
        nInstru++; //Condicional FALSE en j
        nInstru++; //Saltos TRUE en i 
    }
    nInstru++; //Salto FALSE en i
    nInstru++; //Comparacion FALSE en i 

    printf("\nInstrucciones: %d", nInstru);


    return 0;
}