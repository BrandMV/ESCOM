#include <stdlib.h>
#include <stdio.h>

int esSumaConjunto(int conjunto[], int n, int sum){
    //*Se crea la tabla inicializando los valores subconjunto[n+1][sum+1]

    int subconjunto[n+1][sum+1];

    //*Si la suma a buscar es 0, se regresa true
    for(int i=0; i<= n; i++)
        subconjunto[i][0] = 1;
    //*Si la suma no es 0, pero el conjunto es vacio se regresa false
    for(int i = 1; i <= sum; i++)
        subconjunto[0][i] = 0;

    //*Se llena la tabla recorriendo la suma y los elementos del conjunto
    for(int i=1; i <= n; i++){
        for(int j=1; j <= sum; j++){
            //*Si el elemento actual es mayor al valor actual de la suma copiamos el valor del caso anterior
            if(j < conjunto[i - 1])
                subconjunto[i][j] = subconjunto[i-1][j];
            //*Si el valor actual de la suma es mayor que el iesimo elemento
            //*]hacemos or entre los casos previos y el caso de j-valor de suma actual
            if(j >= conjunto[i-1])
                subconjunto[i][j] = subconjunto[i-1][j] || subconjunto[i-1][j-conjunto[i-1]];
        }
    }

    return subconjunto[n][sum];
}

int main(){
    int conjunto[] = { 2,6,4,8 };
    int sum = 10;
    int n = sizeof(conjunto) / sizeof(conjunto[0]);
    if (esSumaConjunto(conjunto, n, sum) == 1)
        printf("Se encontro un subconjunto con la suma dada");
    else
        printf("No se encontro un subconjunto con la suma dada");
    return 0;
}


#include <stdlib.h>
#include <stdio.h>

int tab[2000][2000];

int esSumaConjunto(int conjunto[], int n, int sum){
    if (sum == 0)
        return 1;

    if (n <= 0)
        return 0;

    if (tab[n - 1][sum] != -1)
        return tab[n - 1][sum];

    if (conjunto[n - 1] > sum)
        return tab[n - 1][sum] = esSumaConjunto(conjunto, n - 1, sum);
    else{

        return tab[n - 1][sum] = esSumaConjunto(conjunto, n - 1, sum) || esSumaConjunto(conjunto, n - 1, sum - conjunto[n - 1]);
    }
}

int main(){
    int conjunto[] = { 2,6,4,8 };
    int sum = 10;
    int n = sizeof(conjunto) / sizeof(conjunto[0]);
    if (esSumaConjunto(conjunto, n, sum) == 1)
        printf("Se encontro un subconjunto con la suma dada");
    else
        printf("No se encontro un subconjunto con la suma dada");
    return 0;
}