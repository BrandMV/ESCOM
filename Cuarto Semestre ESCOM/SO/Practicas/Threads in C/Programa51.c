#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

void *HiloP(void *args); //Declaración de la función del hilo principal
void *HilosH(void *args); //Declaración de la función de los hilos hijos

int main(int argc, char const *argv[])
{
	pthread_t hiloP; //Declaración de la variable del hilo principal

	printf("Creando hilo principal...\n"); //Impresión en pantalla
	pthread_create(&hiloP, NULL, HiloP, NULL); //Creación del hilo principal

	pthread_join(hiloP, NULL); //El proceso principal espera la ejecución 
	                           //del hilo principal

	printf("Hilo terminado\n"); //Impresión en pantalla
	printf("Adios");//Impresión en pantalla

	return 0; //Fin del programa
}

void *HiloP(void *args){ //Inicio de la función del hilo principal
	printf("Hilo creado\n"); //Impresión en pantalla
	int i;
	for(i = 0; i < 2; i++){ //for que itera desde 0 hasta 1
		pthread_t hilosH; //Declaración de la variable de los hilos secundarios

		printf("\tCreando otro hilo dentro del hilo principal...\n"); //Impresión en pantalla
		pthread_create(&hilosH, NULL, HilosH, NULL); //Creación de un hilo hijo

		pthread_join(hilosH, NULL); //El hilo principal espera la ejecución del hilo hijo

		printf("\tHilo terminado\n"); //Impresión en pantalla
	}

	printf("Terminando hilo principal...\n"); //Impresión en pantalla
	pthread_exit(NULL); //Termina el hilo principal
}

void *HilosH(void *args){ //Inicio de la función del hilo hijo
	printf("\tHilo creado\n"); //Impresión en pantalla
	printf("\tTerminando hilo...\n"); //Impresión en pantalla

	pthread_exit(NULL); //Termina el hilo hijo
}