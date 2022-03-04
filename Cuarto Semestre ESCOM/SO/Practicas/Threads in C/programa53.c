#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //libreria para usar hilos
#include <unistd.h>
#include <unistd.h> //permite utilizar la llamada al sistema fork()
#include <wait.h> //define las declaraciones de espera
#include <sys/types.h> //tipos de datos, permite usar pid_t

void *hiloH1(){ //función del hilo hijo número 1
    printf("\t\tSoy el hilo hijo 1 con ID: %d\n", pthread_self());

    pthread_exit(NULL);//se acaba el hilo
}

void *hiloH2(){ //función del hilo hijo número 2
    printf("\t\tSoy el hilo hijo 2 con ID: %d\n", pthread_self());

    pthread_exit(NULL);//se acaba el hilo
}

void *hilo1(){
    pthread_t hs1, hs2; //variables para los hilos hijos

    printf("\tSoy el hilo 1 con ID: %d y mi proceso padre es: %d\n", pthread_self(), getpid());
    printf("\tCreare dos hilos\n");


    pthread_create(&hs1, NULL, hiloH1, NULL); //se crea el hilo 1
   
    pthread_create(&hs2, NULL, hiloH2, NULL); //se crea el hilo 2
   
    pthread_join(hs1, NULL); //se espera a que termine de ejecutarse el hilo hijo 1
    pthread_join(hs2, NULL);//se espera a que termine de ejecutarse el hilo hijo 2

    pthread_exit(NULL);//se acaba el hilo

}

void *hilo2(){
    pthread_t hs1, hs2; //variables para los hilos hijos

    printf("\tSoy el hilo 2 con ID: %d y mi proceso padre es: %d\n", pthread_self(), getpid());
    printf("\tCreare dos hilos\n");
   

    pthread_create(&hs1, NULL, hiloH1, NULL); //se crea el hilo 1
    pthread_create(&hs2, NULL, hiloH2, NULL); //se crea el hilo 2
    sleep(1);
    
    pthread_join(hs1, NULL); //se espera a que termine de ejecutarse el hilo hijo 1
    pthread_join(hs2, NULL);//se espera a que termine de ejecutarse el hilo hijo 2

    pthread_exit(NULL);//se acaba el hilo
}

void *hilo3(){
    pthread_t hs1, hs2; //variables para los hilos hijos

    printf("\tSoy el hilo 3 con ID: %d y mi proceso padre es: %d\n", pthread_self(), getpid());
    printf("\tCreare dos hilos\n");
 

    pthread_create(&hs1, NULL, hiloH1, NULL); //se crea el hilo 1
    pthread_create(&hs2, NULL, hiloH2, NULL); //se crea el hilo 2
    sleep(2);
    pthread_join(hs1, NULL); //se espera a que termine de ejecutarse el hilo hijo 1
    pthread_join(hs2, NULL);//se espera a que termine de ejecutarse el hilo hijo 2

    pthread_exit(NULL);//se acaba el hilo

}

int main(){

    pid_t pid; //guarda el id del procesp
    pthread_t h1, h2, h3;

    pid = fork();

    if(pid==0){

        printf("Proceso hijo con ID: %d, creare 3 hilos\n\n", getpid());
        
        pthread_create(&h1, NULL, hilo1, NULL); //se crea el hilo 1
        sleep(1);
        pthread_create(&h2, NULL, hilo2, NULL); //se crea el hilo 2
    
        pthread_create(&h3, NULL, hilo3, NULL); //se crea el hilo 3
        

        pthread_join(h1, NULL); //se espera a que termine de ejecutarse el hilo 1 
        sleep(1);
        pthread_join(h2, NULL);//se espera a que termine de ejecutarse el hilo 2
        pthread_join(h3, NULL);//se espera a que termine de ejecutarse el hilo 3
       
        
    }else{
        wait(NULL);
        printf("\nProceso padre con ID: %d\n", getpid());
    }

    return 0;
}
