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
#define MAXUSERS 5

//************************************************************************
                //*       Estructura para usuario       *//
//************************************************************************
typedef struct user{
    char name[50];              //*Nombre del usuario máximo 50 carácteres
    int id;                     //*Id para identificar al usuario
    int socket;                 //*Socket que identifica al que se conecta el 
    struct sockaddr_in addr;   //*Dirección del usuario
}User;
//*       Estrucutra para argumentos de hilos       *//
struct args{
    User *chatUser;
    int socket;
};


//************************************************************************
                //*       Declaración de funciones       *//
//************************************************************************
void sendMsgToClients(char *msg, int id);
void *clientActions(void *args);


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
User *users[MAXUSERS];       //*Arreglo global que guardará los usuarios
int userID = 0;                 //*Variable para los ID
int totalUsers = 0;                 //*Variable que guarda el total de usuarios conectados



int main(){
    int tcpSocket = 0;                  //*Variable para socket
    struct sockaddr_in client;          //*Estrucutra del client
    struct sockaddr_in server;          //*Estrucutra del servidor
    char userName[50];                  //*Variable para nombre de usuario
    int con = 0;                        //*Variable para la conexion al servidor
    pthread_t clientThread;               //*Variable para los hilos del cliente y servidor
    int bindValue;                      //*Variable para hacer el bind
    int listenValue;                    //*Variable para listen
    int acceptValue;                    //*Variable para accept

    printf("\t\t\t*****Servidor Siuuu Team chat!*****");
    printf("\n");
    printf("\n");

    tcpSocket = socket(AF_INET,SOCK_STREAM,0);

    if(tcpSocket == -1){
        perror("\nError al abrir el socket");
        exit(0);
    }else{
        server.sin_family = AF_INET;                        //*Siempre le asignamos AF_INET que es la familia de direcciones
        server.sin_port = htons(8080);                      //*Es el puerto con los bytes en orden de red
        server.sin_addr.s_addr = inet_addr("10.0.2.15");    //*Dirección IP del host

        /*
            *Con bind enlazamos un nombre a un socket, como parametros esta el socket, la dirección 
            *en este caso el servidor y el tamaño de la dirección
        */
        bindValue = bind(tcpSocket, (struct sockaddr *)&server,sizeof(server));

        if(bindValue == -1){
            perror("\nError al hacer bind :(");
            exit(0);
        }else{
            /*
                *Listen espera conexiones en un socket.
                *El primer parametro es el socket y el segundo el backlog, este es el limite de la cola para
                *las conexiones, en este caso 5
            */
            listenValue = listen(tcpSocket,5);

            //*Si listen falla se regresa un error
            if(listenValue == -1){
                perror("\nError al escuchar la conexion :(");
                exit(0);
            }else{
                cyan();
                printf("\t\t\t*****Chat Room iniciado con exito*****");
                printf("\n");
                printf("\n");
                while(1){

                    /*
                        *La función accept acepta una conexion de parte del cliente y se mantiene en estado de espera
                        *para que un cliente se conecte, al conectarse un cliente con connect() la funcion accept
                        *devuelve un nuevo identificador de socket
                    */
                   socklen_t clis= sizeof(client);
                    acceptValue = accept(tcpSocket, (struct sockaddr *)&client, &clis);
                    if(totalUsers == MAXUSERS){
                        red();
                        printf("Se ha alzanzado el maximo de usuarios\n");
                        close(acceptValue); //*Cerramos la conexion del usuario actual
                        reset();
                    }else{
                        //*Creamos el usuario con sus datos
                        User *chatUser = (User*)malloc(sizeof(User));       //*Establecemos memoria para el usuario actual
                        chatUser->id = userID++;                            //*Le asignamos un id
                        chatUser->socket = acceptValue;                     //*Le asignamos un identificador de socket
                        chatUser->addr = client;                            //*Le asignamos su dirección  
                        int i = 0;
                        //*Agregamos el usuario creado al arreglo de usuarios en el chat
                        for(i = 0;i<MAXUSERS;i++)
                            if(users[i] == NULL){   //*Si no hay ningun usuario lo guardamos
                                users[i] = chatUser;
                                break;              //*Salimos del for
                            }

                        //*Establecemos los argumentos que tendrán los hilos
                        struct args *thread_args = (struct args *)malloc(sizeof(struct args));
                        thread_args -> chatUser = chatUser;
                        thread_args -> socket = tcpSocket;
                        /*
                            *Creamos un nuevo hilo para el cliente
                            *Para más detalles de hilos revisar el manual man pthreads
                            *Si no devuelve 0 es que hubo error al crear el hilo
                        */
                        if(pthread_create(&clientThread, NULL, (void *)clientActions, (void *)thread_args) != 0){
                            perror("\nError al crear hilo");
                            exit(0);
                        }

                    }

                    reset();
                }
                reset();
            }
        }
    }   
    reset();
    close(tcpSocket);
    return 0;
}

/**
 * @brief Hilo que gestiona las acciones del cliente
 * @param args Argumentos del hilo, pasamos el cliente actual
 * @returns NULL para indicar que termina  
 */
void *clientActions(void *args){
    totalUsers++;               //*Incrementamos en uno la cantidad de usuarios conectados
    char name[50];              //*Nombre del usuario
    char msgToClients[2048];   //*Mensaje desde el cliente
    User* user = ((struct args*)args)-> chatUser;
    int recvValue;              //*Variable para el valor de recv
    int i;
    int f = 0;
	memset(msgToClients, 0, 2048); //resetea el buffer de mensajes

    if(recv( user->socket, name, 50, 0) == -1 ){
        perror("\nError al recibir datos");
        exit(0);
    }else{
        strcpy(user->name, name);
        cyan();
        sprintf(msgToClients, "\033[1;36mSe ha conectado %s al chat!, usuarios conectados: %d\n", name,totalUsers);
        printf("%s",msgToClients);
        sendMsgToClients(msgToClients, user->id);
    }

    while(1){
		memset(msgToClients, 0, 2048); //resetea el buffer de mensajes

        recvValue =recv( user->socket, msgToClients, 2048, 0);
        if(recvValue == -1 ){
            perror("\nError al recibir datos");
            break;        
        }else if(recvValue > 0){
            sendMsgToClients(msgToClients, user->id);
            printf("%s",msgToClients);
        }else{
            red();
            totalUsers--;
            sprintf(msgToClients, "\033[1;31mSe desconecto %s, usuarios conectados: %d\n",name, totalUsers);
            printf("%s",msgToClients);
            sendMsgToClients(msgToClients, user->id);
            reset();
            break;
        }
    }


    //*Cuando se desconecta el usuario cerramos su socket y lo quitamos del arreglo
    close(user->id);
    for(i = 0;i<MAXUSERS;i++)
        if(users[i] != NULL){   //*Si no hay ningun usuario lo guardamos
            users[i] = NULL;
            break;              //*Salimos del for
        }
    free(user);     //*LIberamos memoria del usuario
    pthread_detach(pthread_self());     //*Quitamos el hilo
    reset();
    return NULL;
}

/**
 * @brief FUnción que se encarga de mandar el mensaje a los clientes
 * @param msg Mensaje que se enviará a los clientes
 * @param id Id del usuario que manda el mensaje
 * @returns No retorna nada
 */
void sendMsgToClients(char *msg, int id){
    int i;
    for(i = 0;i<MAXUSERS;i++)
        if(users[i] != NULL)
            if(users[i]->id != id)
                if(send(users[i]->socket,msg, strlen(msg), 0) == -1){
                    perror("\nError al enviar :(");
                    exit(0);
                }

}