#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
    This is just a pseudocode
*/

int main(){

    Algoritmo frecuenciaMinNumeros
        Leer n
        Dimension A[n]
        i = 1
        Mientras i <= n
            Leer A[i]
            i = i+1
        FinMientras

        f = 0                                   ---------> 1 asignacion
        i = 1
        Mientras i <= n
            ntemp = A[i]                        ---------> 1 asignacion
            j = 1
            ftemp = 0                           ---------> 1 asignacion
            Mientras j <= n
                si ntemp = A[j]                 ---------> 1 comparacion
                    ftemp = ftemp +1            ---------> 2 asignacion + operacion
                FinSi
                j = j +1
            FinMientras

            si f < ftemp                        ---------> 1 comparacion
                f = ftemp                       ---------> 1 asignacion
                num=ntemp                       ---------> 1 asignacion
            FinSi

            i = i + 1
        FinMientras
        Escribir num
    FinAlgoritmo
    
}