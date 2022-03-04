#include <stdio.h>
#include <stdlib.h>

int main (int argc, char ** argv){
    int i,j=0,n;

    if(argc != 2){
        printf("\nIntroduce el valor de n");
        exit(1);
    }

    n = atoi(argv[1]);

    for(i=10; i<n*5; i*=2)
        printf("\n%dAlgoritmos", ++j);
}
