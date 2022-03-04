#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
    This is just a pseudocode
*/

int main(){

    func maximoComunDivisor(m, n){
        a = max(n, m);
        b = min(n, m);
        residuo = 1;

        mientras(residuo > 0){
            residuo = a mod b; ---------> 1 operacion mod
            a = b;
            b = residuo;
        }
        maximoComunDivisor = a;

        return maximoComunDivisor;
    }

    return 0;
}