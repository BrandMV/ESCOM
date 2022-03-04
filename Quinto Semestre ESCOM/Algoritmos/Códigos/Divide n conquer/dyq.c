#include <stdio.h>
#include <stdlib.h>

#define mo3(a,b,c) ( (a) > (b) ? ((a) > (c) ? (a) : (c)) : ((b) > (c) ? (b) : (c)))

/*
    Función que calcula la suma Maximo de un sub arreglo del arreglo.
    Recibe el arreglo, el inicio y el final del mismo
    Retorna la suma maximo
*/
long long int sumaMaxima(long long int A[], long long int inicio, long long int final){
    long long int i;                                    //Variable para loops   
    if(inicio == final)                                 //Si el inicio es igual al final indica que hay un elemento y lo retornamos
        return A[inicio];                               

    long long int mitad = (inicio+final) / 2;           //Establecemos la mitad del arreglo

    long long int izq = sumaMaxima(A,inicio,mitad);     //Almacenamos la suma maxima del sub arreglo de la izquierda con una llamda recursiva
    long long int der = sumaMaxima(A,mitad+1,final);    //Almacenamos la suma maxima del sub arreglo de la derecha con una llamda recursiva

    long long int suma = 0;                             
    long long int sumaIzq = A[mitad];                   //Establecemos la suma de la izquierda desde la mitad del arreglo

    //Se recorre desde la mitad hasta el inicio del arreglo para encontrar la suma
    for(i=mitad; i>=inicio;i--){
        suma += A[i];                                   //Vamos acumulando la suma de los elementos
        if(suma > sumaIzq)                              //Si la suma es mayor a la suma de la parte izqueierda, esta sera la suma maximo y se almacena
            sumaIzq = suma;
    }
    suma = 0;                       

    //Hacemos lo anterior, pero ahora partiendo de la mitad+1 hasta el último elemento del arreglo
    long long int sumaDer = A[mitad+1];
    for(i=mitad+1; i<=final;i++){
        suma += A[i];
        if(suma > sumaDer)
            sumaDer = suma;
    }

    long long int sumaCentral = sumaIzq + sumaDer;      //Posteriormente, se suman las sumas de ambos lados para encontrar la del arreglo

    return mo3(izq,der,sumaCentral);                    //Obtenemos el mayor de los 3 y esta sera la suma maxima

}

int main()
{
    long long int N;                             //Variable para longitud del arreglo
    scanf("%lldd",&N);                           //leemos los datos que tendrá el arreglo
    long long int A[N];                           //Declaramos arreglo de tamaño N
    long long int j;                             //Variable para loops
    for(j=0;j<N;j++)                             //Llenamos el arreglo de acuerdo a la longitud
            scanf("%lld", &A[j]);                //Leemos los datos que tendrá el arreglo
    
    printf("%lld", sumaMaxima(A,0,N-1));        //Imprimimos la suma maxima

    return 0;
}