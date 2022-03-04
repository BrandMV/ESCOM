#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv){
    int i,j=0,n, k=0;

    if(argc != 2){
        printf("\nIntroduce el valor de n");
        exit(1);
    }

    n = atoi(argv[1]);

    for(j=n; j>1; j/=2){
        if(j<(n/2)){
            for(i=0; i<n; i+=2)
                printf("\n%dAlgoritmos", ++k);
        }
    }
}