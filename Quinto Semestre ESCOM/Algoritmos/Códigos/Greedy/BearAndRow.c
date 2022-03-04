#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char S[1000000];                            //*Variable global para las cadenas

long long int bearRow(){

    long long int N = strlen(S);            //*Obtenemos la longitud de la cadena
    long long int i = 0,j = 0;              //*Variables para loop
    long long int res = 0;                  //*Variable que almacena el resultdo
    long long int seg = 0;                  //*Varibale que guarda los segundos

    //*Recorremos toda la cadena
    while(i < N){
        //*Mientras haya un cero en la cadena y no rebasemos el tamaño de la cadena vanzamos en la cadena
        while(S[i] == '0' && i < N){
            i++;                            //*Avanzamos el indice
            //*Si llegamos al final de la cadena salimos del ciclo
            if(i == N)  
                break;
        }
        //*Cuando nos encontremos con un uno vamos sumando los segundos
        if(S[i] == '1' && i < N)
            res += seg + seg * (i - j - 1);
        //*Mientras haya un uno vamos moviendolo a la derecha aumentando los segundos
        while(S[i] == '1' && i < N){
            seg++;          //*Aumentan los segundos por cada moviemiento
            i++;            //*Avanzamos la cadena
            //*Si llegamos al final de la cadena salimos del ciclo
            if(i == N)
                break;
        }

        if(i < N)
            j = i -1;

    }

    if(S[N - 1] == '0')
        res += seg + seg *(i - j - 1);

    return res;
}

int main()
{
    int T = 0;                      //*Variable para el numero de casos de prueba
    scanf("%d", &T);                //*Leemos los casos de prueba
    while(T--){                     //*Leemos los casos de prueba
        scanf("%s", S);
        printf("%d\n", bearRow());  //*Imprimimos el resultado
    }
    /* code */
    return 0;
}
