#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//  Variables globales 
const int longitud = 100000;        //  Longitud maxima


long long int BITree[3][longitud];  //  Inicializamos el arbol



long long int obtenerSuma(long long int *BITree, int indice){
    long long int s = 0;                //  La suma en 0
    
    indice = indice + 1;                //  El indice del arbol es uno más que el del arreglo
    
    
    while (indice>0){
        
        s += BITree[indice];              //  Vamos sumando los elementos del arbol
 
        indice -= indice & (-indice);   //  Nos movemos la nodo padre
    }
return s;                           //Retornamos la suma

}

void actualizar(long long int *BITree, int n, int indice, long long int valor){
    indice = indice + 1;                //  El indice del arbol es uno más que el del arreglo
    
    while (indice <= n){
    
        BITree[indice] += valor;           //  Agregamos el valor al nodo actual
        indice += indice & (-indice);    //  Actualizamos el indice al del nodo padre
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long int inv;                          //  Cantidad de inversiones
    int n,x;                                    //  Longitud del arreglo
    cin >> n;                                   //  Leemos la longitud del arreglo
    
    long long int a[longitud];                         //  Arreglo de longitud n
    //  Llenamos el arreglo con datos
    for(int i=1;i<=n;i++){                      
        cin >> a[i];
    }
    
    //  Con reverse revertimos el array ingresado
    reverse(a+1,a+n+1);
    
    
    //  Con el siguiente for vamos almacenando las sumas delas inversiones triples
    for(int i=1;i<=n;i++){
        x = a[i];
        actualizar(BITree[2],n,x,inv += obtenerSuma(BITree[1],x-1));
        actualizar(BITree[1],n,x, obtenerSuma(BITree[0],x-1));
        actualizar(BITree[0],n,x,1);
    }
    cout << inv << endl;

    return 0;
}