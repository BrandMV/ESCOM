#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>

void regionCritica(){
	int i;
	printf("\nProceso en la region critica proceso con pid=%d\n",getpid());
	for(i=0;i<3;i++){
		printf("\nRegión critica: %d\n",i);
		sleep(1);	
	}
}

void regionNoCritica(){
	int i;
	printf("\nEn la region NO critica proceso con pid=%d\n",getpid());
	for(i=0;i<5;i++){
		printf("\nContando: %d\n",i);
		sleep(1);
	}
}


int main(){
	int PID;
	int shmid1;
	int shmid2;
   	int shmid3;
	int *Hijo_desea_entrar;
	int *Padre_desea_entrar;
	int *Proceso_favorecido;
	key_t llave1;
	key_t llave2;
   	key_t llave3;
	llave1=ftok("Prueba1",'k');
	llave2=ftok("Prueba2",'l');
	llave3=ftok("Prueba3",'m');
	shmid1=shmget(llave1,sizeof(int),IPC_CREAT|0600);
   	shmid2=shmget(llave2,sizeof(int),IPC_CREAT|0600);
	shmid3=shmget(llave3,sizeof(int),IPC_CREAT|0600);
	Hijo_desea_entrar=shmat(shmid1,0,0);
	Padre_desea_entrar=shmat(shmid2,0,0);
	Proceso_favorecido=shmat(shmid3,0,0);

      	while(1){
        	*Padre_desea_entrar=1;
        	while(*Hijo_desea_entrar){
        		if(*Proceso_favorecido==1){
        			*Padre_desea_entrar=0;
        			while(*Proceso_favorecido==1);
	        			*Padre_desea_entrar=1;
        		}
        	}
        	regionCritica();
        	*Proceso_favorecido=1;
        	*Padre_desea_entrar=0;
        	regionNoCritica();
      	}

   return 0;
}
