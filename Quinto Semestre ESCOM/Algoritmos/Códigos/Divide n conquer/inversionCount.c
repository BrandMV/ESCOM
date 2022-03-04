#include <stdio.h>
#include <stdlib.h>


/*
    Funcion que junta los dos sub arreglos, prácticamente es un merge sort
    Recibe el arreglo, la parte de la izquierda(p), la mitad(q) y la derecha(r)
    Recibe el conteo completo del array
*/
long long int conteoDivididas(long long int A[], long long int p, long long int q, long long int r){
    long long int C[200000];            //Establecemos un arreglo temporal del tamaño máximo que indica el juez
    long long int i = p;                //i será el inicio del arreglo (derecha)
    long long int j = q;                //La mitad del arreglo
    long long int k = p, numDiv = 0;    //K será la mitad del arreglo y se inicializa en 0 el numero de divididas 

    //Se hará el while hasta que i llegue a la mitad del arreglo y j hasta el final del mismo
    while((i <= q-1) && (j <= r)){
        if(A[i] <= A[j])                //Si el elemento i  es menor al j vamos avanzando e n los indices de cada arreglo
            C[k++] = A[i++];
        //Cuando el elemento i es mayor al j, se forman (q-i) inversiones por que los sub arreglos ya estan ordenados
        //De esta forma los elementos sobrantes en el lado izquierdo seran grandes que los de j.
        else{
            C[k++] = A[j++];            
            numDiv += q-i;
        }
    }

    //Copiamos los elementos que sobran de la primera mitad en el arreglo auxiliar
    while(i <= q-1)
        C[k++] = A[i++];
    //Copiamos los elementos que sobran de la segunda mitad en el arreglo auxiliar
    while(j <= r)
        C[k++] = A[j++];

    //Ahora pasamos a copiar los elementos mezclados en el arreglo original
    for(i=p; i<=r;i++)
        A[i] =C[i];


    return numDiv;                      //Retornamos el numero de inversiones
}

/*
    Función que realiza el conteo de inversiones.
    Recibe el arreglo, el inicio y el final del mismo
    Retorna el conteto total de inversiones.
*/
long long int conteoInversiones(long long int A[], long long int p, long long int r){

    //Si la parte de la izquierda es menor a la derecha
    if( p < r ){
        long long int q = (p + r) / 2;                              //Partimos a la mitad el arreglo
        long long int invDer = conteoInversiones(A,p,q);            //Contamos las inversiones por la derecha           
        long long int invIzq = conteoInversiones(A,q+1,r);          //Contamos las inversiones por la izquierda   
        long long int invDiv = conteoDivididas(A,p,q+1,r);          //Hacemos la mezcla de la suma de los sub arreglos derecha e izquierda
        return invDer + invIzq +invDiv;                             //Devolvemos la suma de todas
    }else return 0;                                                  //En caso contrario devolvemos 0

}

int main()
{
    long long int t;                      //Número de tests
    scanf("%lld",&t);                     //Leemos el nùmero de tests
    long long int i,j;                    //Variable para loop
    long long int n;                      //Longitud del arreglo
    long long int cont = 0;
    while(t--){                           //Mientras haya número de tests vamos leyendo arreglos
        n = 0;   

        scanf("%lld", &n);                //Leemos la longitud

        long long int A[n];               //Declaramos un arreglo del tamaño de la longitud anterior
        for(j=0;j<n;j++){                 //Llenamos el arreglo de acuerdo a la longitud
            scanf("%lld", &A[j]);         //Leemos los datos que tendrá el arreglo
        }
     

        printf("%lld\n",conteoInversiones(A,0,n-1));

    }


    /* code */
    return 0;
}
