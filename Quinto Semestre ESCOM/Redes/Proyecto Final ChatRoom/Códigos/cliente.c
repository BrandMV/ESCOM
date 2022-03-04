//************************************************************************
                //*       LIBRERIAS INCLUIDAS       *//
//************************************************************************

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio_ext.h>
#include <pthread.h>

//************************************************************************
                //*       Estrucutra para argumentos de hilos       *//
//************************************************************************

struct args{
    char name[50];
    int socket;
};

//************************************************************************
                //*       Declaración de funciones       *//
//************************************************************************
void sendMSgsToServer(void *args);
void rcvMsgsFromServer(void *args);

/*
    *Funciones para colores
*/
void red(){
    printf("\033[1;31m");
}
void reset(){
    printf("\033[0m");
}
void yellow(){
    printf("\033[1;33m");
}
void blue(){
    printf("\033[1;34m");
}
void green(){
    printf("\033[1;32m");
}
void white(){
    printf("\033[1;37m");
}
void black(){
    printf("\033[1;30m");
}
void purple(){
    printf("\033[1;35m");
}
void cyan(){
    printf("\033[1;36m");
}
//************************************************************************
                //*       Variables globales       *//
//************************************************************************

int main(){
    int tcpSocket = 0;                  //*Variable para socket
    struct sockaddr_in server;          //*Estrucutra del servidor
    char userName[50];                  //*Variable para nombre de usuario
    int con = 0;                        //*Variable para la conexion al servidor
    pthread_t clientThread, serverThread; //*Variable para los hilos del cliente y servidor
    cyan();
    printf("\t\t\t*****Bienvenido al Siuuu Team chat!*****");
    printf("\n");
    printf("\n");
    green();
    printf("Ingresa tu nombre para conectarte al chat: ");
    reset();
    fgets(userName,50,stdin);                   //*Leemos el nombre del usuario
    userName[strlen(userName)-1]='\0';          //*QUitamos el salto de linea al final de la cadena

    /*
        *La siguiente función es para abrir un socket, en este proyecto estamos usando un scoket
        *tcp (SOCK_STREAM) ya que este nos permite una comunicación bidireccional y es lo que necesitamos
        *para el chat.
        *Para sus métodos y opcioens podemos consultar los manuales 7 ip y socket
    */
    tcpSocket = socket(AF_INET, SOCK_STREAM, 0);
    
    //*Si obtenemos -1 al abrir el socket arrojamos un error, en caso contrario seguimos con el programa
    if(tcpSocket == -1){
        red();
        perror("\nError al abrir el socket");
        exit(0);
    }else{
        server.sin_family = AF_INET;                        //*Siempre le asignamos AF_INET que es la familia de direcciones
        server.sin_port = htons(8080);                      //*Es el puerto con los bytes en orden de red
        server.sin_addr.s_addr = inet_addr("10.0.2.15");    //*Dirección IP del host

        /*
            *Establecemos una conexion en un socket con la siguiente funcion connect.
            *Como nuestro socket es tipo SOCK_STREAM, esta funcion intenta hacer una conexion
            *a otro socket, siendo en este caso nuestro otro socket el servidor (remota).
            *El primer parametro es nuestro socket, el segundo es el otro socket a conectarnos
            *el ultimo parametro es la longitud.
            *Mas detalles en man connect
        */
        con = connect(tcpSocket, (struct sockaddr *)&server, sizeof(server));
        
        //*Si obtenemos -1 al hacer la conexion arrojamos un error, en caso contrario seguimos
        if(con == -1){
            red();
            perror("\nError al conectarse al chat :(");
            exit(0);
        }else{
            /*
                *Usamos send para mandar mensajes a otro socket, al estar usando connect, procedemos a usar send
                *ya que con send nos asegura el envio del mensaje solo si estamos 
                *El primer parametro es el socket, el segundo el mensaje, el tercero la longitud del mensaje
                *y el ultimo el parametro flags
                *Mas detalles en el manual man send
            */
            send(tcpSocket, userName, 50, 0);               //*Mandamos el mensaje con el usuario que se conecto
            cyan();
            printf("\t\t\t*****Te has conectado %s!*****",userName);
            printf("\n");
            printf("\n");
            //*Establecemos los argumentos que tendrán los hilos
            struct args *thread_args = (struct args *)malloc(sizeof(struct args));
            strcpy(thread_args -> name, userName);
               thread_args -> socket = tcpSocket;
            /*
                *Creamos un nuevo hilo para el envio de mensajes del cliente al servidor
                *Para más detalles de hilos revisar el manual man pthreads
                *Si no devuelve 0 es que hubo error al crear el hilo
            */
            if(pthread_create(&clientThread, NULL, (void *)sendMSgsToServer, (void *)thread_args) != 0){
                red();
                perror("\nError al crear hilo de cliente");
                exit(0);
            }
            /*
                *Creamos el hilo sel servidor en donde nos encargaremos de estar recibiendo
                   *los mensajes de otros usuarios o del servidor
                *Si no devuelve 0 es que hubo error al crear el hilo
            */
            if(pthread_create(&serverThread, NULL, (void *)rcvMsgsFromServer, (void *)thread_args) != 0){
                red();
                perror("\nError al crear hilo de cliente");
                exit(0);
            }
        
            while(1){
                //*For para que no se termine el programa hasta que el usuario salga del chat
            }
        }
    }   
    close(tcpSocket);       //*Cerramos el socket
    reset();
    return 0;               //*Salimso del programa
}


/**
 * @brief Hilo que se encarga de mandar mensajes al servidor
 * @param args Mandamos el nombre del usuario y el socket al hilo
 * @returns No retorna nada
*/
void sendMSgsToServer(void *args){
    char userMsg[2048];             //*Variable para el mensaje a enviar (la cantidad máxima es de 2048)
    char msgToServer[2048];         //*Mensaje final que se enviará al servidor

    //*Ciclo infinito para hacer el chat hasta que el usuario finalice el chat

    while(1){
        memset(userMsg, 0, 2048);           //*Limpiamos los mensajes
		memset(msgToServer, 0, 2048);       //*Limpiamos el mensaje al servidor
        green();
        printf("~ ");          
        reset();
        fgets(userMsg, 2048, stdin);        //*Leemos el mensaje a enviar al chat
        userMsg[strlen(userMsg)-1]='\0';    //*QUitamos el salto de linea al final de la cadena


        //*Con sprintf damos formato al mensaje que se enviarà y se mostrara en el servidor y los demas chats
        sprintf(msgToServer, "\033[1;32m[%s]: \033[0m%s\n", ((struct args*)args)->name, userMsg);

        //*Mandamos el mensaje al servidor 
        send(((struct args*)args)->socket, msgToServer, strlen(msgToServer),0);

    }

    pthread_detach(pthread_self());     //*Quitamos el hilo

}

/**
 * @brief Hilo que se encarga de recibir los mensajes enviados del servidor
 * @param args argumentos del hilo, se pasa el socket
 * @returns No retorna nada
 */
void rcvMsgsFromServer(void *args){
    char msgRecv[2048];                 //*Mensaje recibido
    //*Ciclo infinito para recibir mensajes
    while(1){
        /*
            *Con la funciòn recv recibimos un mensaje desde un socket en estado conectado,
            *es la misma funciòn que hemos estado usando (recvfrom) solo que con el parámetro desde en NULL
            *El primer parametro es el socket, el segundo el mensaje a recibir, el tercero la longitud de este mensaje
            *y el ultimo son las banderas
        */
        if(recv(((struct args*)args)->socket, msgRecv, 2048, 0) == -1){ //*Si retorna -1 ocurrió un error
            red();
            printf("\nHa ocurrido un error o se ha alcanzado el limite de usarios\n");
            reset();
            exit(0);
            break;
        }else{
            printf("%s",msgRecv);       //*Imprimimos el mensaje
            green();
            printf("~ ");
            reset();
            fflush(stdout);
            
        }
        memset(msgRecv, 0, sizeof(msgRecv));    //*Limpiamos el buffer del mensaje recibido
    }

    pthread_detach(pthread_self());     //*Quitamos el hilo
}
