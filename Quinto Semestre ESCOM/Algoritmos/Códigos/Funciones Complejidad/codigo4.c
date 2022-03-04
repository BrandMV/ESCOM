#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){

    int n, anterior, actual, aux, nInstru=0;

    if(argc != 2)
        exit(0);

    n = atoi(argv[1]);    

    anterior = 0; nInstru++; 
    actual = 0; nInstru++;
    while(n > 2){
        nInstru++; //Condicion TRUE
        aux = anterior + actual; nInstru+=2;
        anterior = actual; nInstru++;
        actual = aux; nInstru++;
        n = n - 1; nInstru+=2;
        nInstru++; //Saltos TRUE
    }
    nInstru++; //Comparaciòn FALSE;
    nInstru++; //Salto False

    printf("\nInstrucciones: %d", nInstru);

    return 0;
}