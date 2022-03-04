#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN(a,b) ((a) < (b)  ? (a) : (b) )      //  Para encontrar el minimo de dos numeros


float minimaDist(float izq, float der, float min){

    if(der == 0 && izq == 0)                  //  Si las distancias derecha e izquierda son 0, retornamos la minima calculada
        return min;
    else if(der != 0)                         //  Si la derecha no es 0, entonces retornamos la menor distancia entre la derecha y la minima calculada
            return MIN(der,min);    
         else if(izq != 0)                    //  Si la izquierda no es 0, entonces retornamos la menor distancia entre la izquierda y la minima calculada
                return MIN(izq,min);
    else
        return MIN(MIN(der,izq), min);        //  Si la derecha e izquierda son distancias válidas se retorna el menor de los 3
}

float calcularDistancia(float x1,float y1,float x2,float y2){ return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2)); }

float distanciaEstrellas(float X[], float Y[], long int inicio, long int final){
    if(inicio == final)                                 //Si el inicio es igual al final indica que hay un elemento y lo retornamos
        return 0;

    long int i,j, mitad = (inicio + final) / 2;                     //  Calculamos la mitad para buscar
    float izq = distanciaEstrellas(X,Y,inicio,mitad);               //  Llamada recursiva para la parte izquierda
    float der = distanciaEstrellas(X,Y,mitad+1,final);              //  Llamada recursiva para la parte derecha
                        
    float distancia = 0, min = 0;                                  //  Inicializamos las distancias
  

    /*  
        Vamos recorriendo los elementos de la mitad izquierda y la mitad derecha
        para ir calculando sus distancias
    */
    for(i=inicio; i<=mitad;i++){
        for(j=final; j>=mitad+1;j--){       
            distancia = calcularDistancia(X[i],Y[i],X[j],Y[j]);      //  Calculamos distancias
            //  Si la distancia calculada es menor a la minima o la minima es 0, la nueva distancia será la calculada
            if((distancia <= min) || (min == 0))     
                min = distancia;
        }
    }
    return minimaDist(izq,der,min);                                //  Regresamos la distancia minima
}

int main()
{
    long int n;                             //  Cantidad de estrellas
    scanf("%ld", &n);                       //  Leemos la cantidad de estrellas
    if(n < 2) return 0;                     //  Si la cantidad de estrellas es menor a 2 salimos
    float X[n],  Y[n];                      //  Arreglos que guardarán las coordenadas de cada estrella
    long int i;                             //  Variable para loops;

    //  Leemos los puntos
    for(i=0;i<n;i++){
        scanf("%f",&X[i]);
        scanf("%f",&Y[i]);
    }

    printf("%f",distanciaEstrellas(X,Y,0,n-1));  //Imprimimimos la distancia minima de dos estrellas
    return 0;
}