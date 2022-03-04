#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv){
    int i,j=0,n, k=0;

    if(argc != 2){
        printf("\nIntroduce el valor de n");
        exit(1);
    }

    n = atoi(argv[1]);

    i = n;
    while(i >= 0){
        for(j=n; i<j; i-=2, j/=2)
            printf("\n%dAlgoritmos", ++k);
    }
}