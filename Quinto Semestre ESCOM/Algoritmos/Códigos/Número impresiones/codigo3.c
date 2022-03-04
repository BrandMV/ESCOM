#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv){
    int i,j=0,n, k=0, l=0;

    if(argc != 2){
        printf("\nIntroduce el valor de n");
        exit(1);
    }

    n = atoi(argv[1]);

    for(i=0; i<n*5; i+=2){
        for(j=0; j<2*n; j++){
            for(k=j; k<n; k++)
                printf("\n%dAlgoritmos", ++l);
        }
    }
}