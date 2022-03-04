#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //libreria para usar hilos
#include <unistd.h>

#define A 10 //unidades en las que se incremente glo
#define B 5 //unidades en las que se decrementa glo
int glo=0; //Variable global

void *hilo1(){ //código del primer hilo
    for (int i = 0; i < 5; i++) //for que hace 5 iteraciones en las que se incrementará glo
    {
        printf("Incrementando la variable global en %d unidades\n", A); 
        glo+=A; //incrementa glo en 10 unidades
    }
    
    
    pthread_exit(NULL); //se acaba el hilo
}

void *hilo2(){ //código del segundo hilo

    for (int i = 0; i < 5; i++)//for que hace 5 iteraciones en las que se decrementará glo
    {
        printf("Decrementando la variable global en %d unidades\n", B);
        glo-=B; //decremetna glo en 5 unidades
    }


    pthread_exit(NULL);//se acaba el hilo
}

int main(){

    pthread_t IDhilo1; //pthread_t es un entero largo, almacena el id del hilo
    pthread_t IDhilo2;

    pthread_create(&IDhilo1, NULL, hilo1, NULL); //se crea el hilo 1
    printf("Hilo 1 creado\n");
    pthread_join(IDhilo1, NULL); //se espera a que termine de ejecutarse el hilo 1
    printf("Hilo 1 finalizado:\n\n");

    pthread_create(&IDhilo2, NULL, hilo2, NULL); //Se crea el hilo 2
    printf("Hilo 2 creado\n");
    pthread_join(IDhilo1, NULL);//se espera a que termine de ejecutarse el hilo 2
    printf("Hilo 2 finalizado:\n\n");

    printf("El valor final de la variable global es: %d\n", glo);// se imprime el valor final de glo

    return 0;

}