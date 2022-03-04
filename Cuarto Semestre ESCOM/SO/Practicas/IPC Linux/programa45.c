#include <stdio.h>
#include <stdlib.h>	
#include <unistd.h>		
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <time.h>

#define FALSE 	0
#define TRUE 	1
#define NF 		5			//Constante que indica el Numero de filósofos
#define RIGHT 	(i+1)%NF
#define	LEFT 	(i+NF-1)%NF
#define COMER 		2		//El filosofo está comiendo 
#define HAMBRE	 	1		//Estado hambriento del filosofo
#define PENSAR 	0		//Estado pensativo del filosofo 


int estado[NF];		//Arreglo donde está el estado del filósofo		

void pensar(void);
void comer (void);
int* enter_to_buffer(int *new_dato);
void up(int semid);
void down(int semid);
int crea_semaforo(key_t key, int valor_ini);


int crea_semaforo(key_t key, int valor_ini)
{
	int semid;	//ID del semáforo
	
	semid = semget(key,1,IPC_CREAT | 0644 );
	
	if(semid==-1)
	{
		printf("\nNo se pudo crear el semaforo");
		exit(-1);
		
	}
	
	semctl(semid,0,SETVAL,valor_ini);
	
}

void down(int semid)
{
	struct sembuf op_v[]={0,-1,0};
	semop(semid,op_v,1);
	
	
}


void up(int semid)
{
	struct sembuf op_p[]={0,+1,0};
	semop(semid,op_p,1);
	
}


int* enter_to_buffer(int *new_dato)
{
	
	int i=0,memory=0;
	int *data=NULL;
	key_t key7;
	key7=ftok("file7",'n');
	
	if(key7==-1)
	{
		printf("\nNo se pudo crear la llave numéro 4");
		exit(-1);	
		
	}
	
	memory=shmget(key7,sizeof(int),IPC_CREAT| 0600);
	data=shmat(memory,0,0);
	data=new_dato;
	return data;


}


void comer (void)
{
	int j;
	
	for(j=0;j<NF;j++)
	{
		if(estado[j]==COMER)
		{
			printf("\nEl filosofo %d esta comiendo",j+1);
			
		}
		else if(estado[j]==PENSAR)
		{
			printf("\nEl filosofo %d esta pensando",j+1);
		}
		
	}
	
	
}



void pensar(void)
{
	int j;
	for(j=0;j<NF;j++)
	{
		if(estado[j] == PENSAR)
		{
			//Continua 
		}
		else if(estado[j]==COMER)
		{
			printf("\nEl filosofo %d esta comiendo",j+1);
			
		}
		
		
	}
	
	
}


void main()
{
	int s[NF],i=0, almacena=0,no_filosofo=5,sema_mutex=0;
	key_t key1=0,key2=0,key3=0,key4=0,key5=0,key6=0;
	
	printf("1");
	
	//Creando los semáforos de los filósofos 
	
	key1=ftok("file1",'a');
	s[0] = crea_semaforo(key1,1);
	
	key2=ftok("file2",'b');
	s[1] = crea_semaforo(key2,1);
	
	key3=ftok("file3",'c');
	s[2] = crea_semaforo(key3,1);
	
	key4=ftok("file4",'d');
	s[3] = crea_semaforo(key4,1);

	key5=ftok("file5",'e');
        s[4] = crea_semaforo(key5,1);
	
	key6=ftok("file6",'f');
	sema_mutex=crea_semaforo(key6,1);
	int p=0;
	while(p<NF)
	{
		
		almacena=i;
		pensar();
		
		down(sema_mutex); 
		printf("\nTomando el tenedor");
		estado[i]=HAMBRE;
		
		//Verificando 
		if(estado[i]==HAMBRE && estado[LEFT] != COMER && estado[RIGHT] != COMER)
		{
				estado[i]=COMER;
				up(s[i]);
			
		}
		
		
		//Se termina de probar
		up(sema_mutex);
		down (s[i]);
		
		
		//termina la funcion tomar tenedor
		comer();
		
		down(sema_mutex);
		estado[i]=PENSAR;
		i=LEFT;
		
		if(estado[i]==HAMBRE && estado[LEFT]!=COMER && estado[RIGHT] != COMER)
		{
			estado[i]=HAMBRE;
			up(s[i]);
			
		}
		i=almacena;
		i=RIGHT;
		
		if(estado[i]==HAMBRE && estado[LEFT]!=COMER && estado[RIGHT] != COMER)
		{
			estado[i]=HAMBRE;
			up(s[i]);
			
		}
		
		
		up(sema_mutex);
		printf("\n");
		p++;		
		
		
	}
	

}
