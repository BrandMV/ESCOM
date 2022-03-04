#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //Librería necesaria para manejar hilos
#include <semaphore.h> //Librería necesaria para manejar semáforos
#include <unistd.h>

sem_t semaforo; //Declaración de la variable "semaforo"
int var = 0; //Declaración de la variable var que manipularan los hilos

void *Hilo1(void *segs); //Declaración de la función del primer hilo
void *Hilo2(void *segs); //Declaración de la función del segundo hilo

int main(int argc, char const *argv[]){ 
	
	pthread_t id_hilo1, id_hilo2; //Declaracion de las variables hilos
	sem_init(&semaforo, 0, 1); //Inicia el semáforo
	int segs = 0; //Declaración de la variable segs

	printf("Escriba el tiempo a esperar: "); //Impresión en pantalla
	scanf("%d", &segs); //Guarda la entrada del usuario en una variable

	pthread_create(&id_hilo1, NULL, Hilo1, &segs); //Creación del primer hilo
	pthread_create(&id_hilo2, NULL, Hilo2, &segs); //Creación del segundo hilo

	pthread_join(id_hilo1, NULL); //El proceso principal espera a la ejecución
	pthread_join(id_hilo2, NULL); //del primer y segundo hilo, despues continúa

	sleep(segs); //El proceso principal se duerme según la entrada del usuario

	printf("Valor de la variable al final %d \n", var); //Impresión en pantalla
								          				//del valor final de la variable
	return 0; // Fin del programa
}

void *Hilo1(void *segs){ //Inicio de la ejecución del primer hilo

	int i;	
	int *seg = (int*)segs; //Parseo de la variable segs
	for(i = 0; i < (*seg); i++){ //for que itera desde 0 a la cantidad dada por el usuario
		sem_wait(&semaforo); //Instrucción que espara una "luz verde del semaforo"
		var++; //Incrementa en uno la variable
		sem_post(&semaforo); //Cambia el valor del semaforo, para indicar que su ejecución 
							 //ha finalizado
	}
}

void *Hilo2(void *segs){ //Inicio de la ejecución del segundo hilo

	int i;
	int *seg = (int*)segs;
	for(i = 0; i < (*seg); i++){
		sem_wait(&semaforo);
		var--; //Decrementa en uno la variable
		sem_post(&semaforo);
	}
}