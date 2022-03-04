#include<pthread.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

#define ARR_LENGTH 10

int Numeros[ARR_LENGTH];
int NumerosPrimos[ARR_LENGTH];
int numeroCompuesto;

int esPrimo(int n){
	int bandera = 1;
	for(int j=2;j<n;j++){
		if(n%j==0)
			bandera=0;
	}
	return bandera;
}

void DeterminaPrimos(int numC){
	int i;
	int primos=0;
	int posicionArray = 0;
	for(i=2;i<numC;i++){
		if(numC%i==0){
			Numeros[posicionArray]=i;
			posicionArray++;
		}
	}
	for(i=0;i<ARR_LENGTH;i++){
		if(esPrimo(Numeros[i])==1){
			NumerosPrimos[i]=Numeros[i];
			primos++;
		}
	}
	if(primos>0)
		printf("El numero %d esta compuesto por los siguientes numeros primos: ",numeroCompuesto);
	else
		printf("El numero %d no esta compuesto por numeros primos",numeroCompuesto);
	for(i=0;i<ARR_LENGTH;i++){
		if(NumerosPrimos[i]>0)
			printf("%d ",NumerosPrimos[i]);
	}
	printf("\n");
}

int EsCompuesto(int numC){
	int i;
	for(int i=2;i<numC;i++){
		if(numC%i==0)
			return i;
	}
	return 0;
}

void *Codigo_Hilo1(void *arg){
	printf("\nIntroduce un numero: \n");
	scanf("%d",&numeroCompuesto);
	if(EsCompuesto(numeroCompuesto)>=2)
		printf("El numero %d es compuesto",numeroCompuesto);
	pthread_exit(NULL);
}

void *Codigo_Hilo2(void *arg){
	if(EsCompuesto(numeroCompuesto)>=2)
		DeterminaPrimos(numeroCompuesto);
	pthread_exit(NULL);
}

void *Codigo_Hilo3(void *arg){
	if(EsCompuesto(numeroCompuesto)<2)
		printf("\nEl numero %d es primo\n",numeroCompuesto);
	pthread_exit(NULL);
}

int main(){
	pthread_t hilo1;
	pthread_t hilo2;
	pthread_t hilo3;

	pthread_create(&hilo1,NULL,Codigo_Hilo1,NULL);
	pthread_join(hilo1,NULL);
	printf("\nHilo numero 1 terminado\n");

	pthread_create(&hilo2,NULL,Codigo_Hilo2,NULL);
	pthread_join(hilo2,NULL);
	printf("\nHilo numero 2 terminado\n");

	pthread_create(&hilo3,NULL,Codigo_Hilo3,NULL);
	pthread_join(hilo3,NULL);
	printf("\nHilo numero 3 terminado\n");

	pthread_exit(NULL);
}

