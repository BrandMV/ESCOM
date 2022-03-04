#include <stdio.h>
#include <stdlib.h>


int main(){
    int n = 20, i=0;
    int a = 0;
    int b = 1;
    for(i = 0; i<n; i++){
        printf("%d\n", a);
        printf("%d\n", b);
        a = a+b;
        b = a+b;
    }

}