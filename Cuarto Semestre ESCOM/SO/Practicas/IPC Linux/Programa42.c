#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <time.h> //Libreria para manipular la fecha y hora del sistema

int main(int argc, char const *argv[]){
	
	int shmid, i, salida; //Declaración de la variable de memoria compartida, entre otras
	float *random[10]; //Declaración de la variable que va a ser compartida
	pid_t pid; //Declaración de la variable "pid"
	srand(time(NULL)); //Genera la semilla para la llamada al sistema "rand" en base a la 
					   //hora del sistema al momento de la ejecución
	key_t key; //Declaración de la variable "key"

	key = ftok("Memoria", 'k'); //Convierte una ruta y un proyecto a una llave de IPC del sistema
	shmid = shmget(key, (sizeof(float)*10), IPC_CREAT|0600); //Obtiene un segmento de memoria compartida
	*random = (float*)shmat(shmid, 0, 0); //Una variable apuntador, apunta la dirección de memoria 
										  //compratida obtenida anteriormente

	pid = fork(); //Crea un nuevo proceso
	if(pid == -1){ //verifica si el proceso tuvo errores
		perror("Error al crear el proceso"); //En caso de no haberse creado el proceso, manda un error
		exit(-1); //Termina el proceso con mensaje de error
	} else if(pid == 0){ //Verifica que el proceso se haya creado correctamente
		for(i = 0; i < 10; i++){ //for que itera desde el 0 hasta el 9
			(*random)[i] = rand() % 100; //Asigna un número aleatorio a la posición actual 
		}	                             //de la variable random
		exit(0); //Finaliza el proceso
	}

	pid = wait(&salida); //Espera a que el proceso termine

	for(i = 0; i < 10; i++){ //For que itera desde el 0 hasta el 9 
		printf("%0.2f \n", (*random)[i]); //Imprimer la variable compartida
	}

	shmdt(&random); //Desvincula la variable apuntador del segmento de memoria compartida
	shmctl(shmid, IPC_RMID, 0); //Elimina el segmento de memoria compartida

	return 0; //Fin del programa
}