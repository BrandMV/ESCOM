#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*
    This is just a pseudocode
*/

int main(int argc, char **argv){

    int n,m1,m2,m3,i, *A;

    func sumaCuadratica3Mayores(A, n){

        if(A[1] > A[2] && A[1] > A[3]){ ---------> 2 comparaciones
            m1 = A[1];                  ---------> 1 asignacion
            if(A[2] > A[3]){            ---------> 1 comparacion
                m2 = a[2];              ---------> 1 asignacion
                m3 = A[3];              ---------> 1 asignacion
            }else{
                m2 = A[3];              ---------> 1 asignacion
                m3 = A[2];              ---------> 1 asignacion 
            }else if(A[2] > A[1] && A[2] > A[3]){   --------->  2 comparaciones
                m1 = A[2];              ---------> 1 asignacion
                if(A[1] > A[3]){        ---------> 1 comparacion
                    m2 = A[1];          ---------> 1 asignacion
                    m3 = A[3];          ---------> 1 asignacion
                }else{
                    m2 = A[3];          ---------> 1 asignacion
                    m3 = A[1];          ---------> 1 asignacion
                }
            }else{
                m1 = A[3];              ---------> 1 asignacion
                if(A[1] > A[2]){        ---------> 1 comparacion
                    m2 = A[1];          ---------> 1 asignacion
                    m3 = A[2];          ---------> 1 asigancion
                }else{
                    m2 = A[2];          ---------> 1 asignacion
                    m3 = A[1];          ---------> 1 asignacion
                }
            }
        }
        i = 4;
        while(i <= n){
            if(A[i] > m1){              ---------> n-3 comparaciones
                m3 = m2;                ---------> n-3 asignaciones
                m2 = m1;                ---------> n-3 asignaciones
                m1 = A[i];              ---------> n-3 asignaciones
            }else if(A[i] > m2){        ---------> n-3 comparaciones
                m3 = m2;                ---------> n-3 asignaciones
                m2 = A[i];              ---------> n-3 asignaciones
            }else if(A[i] > m3)
                m3 = A[i];              ---------> n-3 asignaciones

                i = i +1;
        }
        return = pow(m1 + m2 +m3, 2);
    }

    return 0;
}