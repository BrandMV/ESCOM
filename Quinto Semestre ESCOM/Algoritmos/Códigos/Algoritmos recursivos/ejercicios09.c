#include <stdio.h>
#include <stdlib.h>

int n,k;

int main(){
    
    return 0;
}

// Codigo 04

subAlgoritmo volados(n,cadena)
    Si n != 0                                   ----- 1
        volados(n-1,concatenar(cadena,'S'))     ----- 1
        volados(n-1,concatenar(cadena,'A'))     ----- 1
    SiNo
        Mostrar cadena
    FinSi
FinSubAlgoritmo


// Codigo 01
Busqueda(A[],i,val){
    if(i<0)                             ----- 1
        return -1;                      ----- 1  
        if(A[i] == val)                 ----- 1
            return i                    ----- 1
        return Busqueda(A[],i-1,val);   ----- 2
}

// Codigo 02
int coef(int n, int k){
    if(k == 0 || k == n)                    ----- 1   
        return 1;                           ----- 1
    else if(k > 0 && k< n)                  ----- 2
        return coef(n-1,k-1)+coef(n-1,k);   ----- 5
}


// Codigo 03
Palindormo(cadena){
    if(longitud(cadena) == 1)                                   ----- 1  
        return TRUE;                                            ----- 1  
    if(primer_caracter(Cadena) != ultimo_caracter(cadena))      ----- 1  
        return FALSE;                                           ----- 1  

    cadena = remover_primer_ultimo_caracter(Cadena);            ----- 1  
    Palindromo(cadena);                                         
}


// Codigo 05
decABin(n){ 
    if(n>1)             ----- 1 
        DecABin(n/2)    ----- 1 
        Mostrar(n%2)    ----- 1 
}

// Codigo 06
int producto(int a, int b){
    if(b == 0)                          ----- 1 
        return 0;                       ----- 1 
    else
        return a + producto(a,b-1);     ----- 3

}



