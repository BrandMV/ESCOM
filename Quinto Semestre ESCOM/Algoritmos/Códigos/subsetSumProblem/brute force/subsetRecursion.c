#include <stdlib.h>
#include <stdio.h>

int esSumaConjunto(int conjunto[], int n, int sum){

    //* Casos base
    if( sum == 0 )
        return 1;
    if( sum < 0 || (n == 0 && sum != 0) )
        return 0;

    //* Si el último elemento es mayor a la suma que estamos verificando se ignora
    if( conjunto[n-1] > sum )
        return esSumaConjunto(conjunto, n-1, sum);

    //* La primera opciòn es no incluirlo, la segunda es incluirlo
    return esSumaConjunto(conjunto, n-1, sum) || esSumaConjunto(conjunto, n-1, sum - conjunto[n-1]);
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