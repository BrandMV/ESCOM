#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/types.h> //tipos de datos, permite usar pid_t
#include <unistd.h> //permite utilizar la llamada al sistema fork()
#include <wait.h> //define las declaraciones de espera

struct msg{
    long MID; //almacena el id del mensaje
    char ms[40]; //almacena el mensaje que será enviado
    pid_t PID; //almacena el PID del proceso
};

int main()
{
    key_t llave; //redefinicion de un entero
    int idcmsg; //almacena el id de la cola de mensajes
    struct msg mensaje; //mensaje que se enviará

    llave=ftok("prueba", 'k');//se crea la llave, los procesos cona cceso al archivo y al entero
                                //pueden acceder a los recursos compartidos

    idcmsg=msgget(llave, 0600 | IPC_CREAT); //se crea la cola de mensajes
    msgrcv(idcmsg, (struct msgbuf *)&mensaje, sizeof(mensaje.PID)+sizeof(mensaje.ms), 1, 0); //se recibe la cola de mensajes
    printf("He recibido un mensaje:\n");
    printf("%s, mi PID es %d \n", mensaje.ms, mensaje.PID); //imprime el mensaje recibido
    mensaje.MID=2;
    mensaje.PID=getpid();
            
    strcpy(mensaje.ms, "Hola soy el proceso 2");
    msgsnd(idcmsg, (struct msgbuf *)&mensaje, sizeof(mensaje.PID)+sizeof(mensaje.ms), IPC_NOWAIT);//se manda un mensaje        
    printf("He enviado el mensaje\n");

    return 0;
}