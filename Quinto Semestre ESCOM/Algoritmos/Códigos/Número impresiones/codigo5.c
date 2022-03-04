#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv){
    int i,j=0,n, k=0;

    if(argc != 2){
        printf("\nIntroduce el valor de n");
        exit(1);
    }

    n = atoi(argv[1]);

    for(i=1;i<4*n; i*=2)
        for(j=i; j<5*n; j+=3)
            printf("\n%dAlgoritmos", ++k);

}