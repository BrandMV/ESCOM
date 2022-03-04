#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h> //L2 protocols
#include <netinet/ip.h> 
#include <arpa/inet.h>
#include <string.h>

int main(){
    int udp_socket, bindValue, sendtoValue; //sendtoValue: para sendto y bindValue para bind
    struct sockaddr_in local, remota;//estructuras para el servidor y client
    unsigned char msg[100] = "Hola a todos soy un mensajito"; //Mensaje a enviar

    printf("\n\n\t\t\t*****MI PRIMER SOCKET*****\n\n");

    /*
        socket nos permite abrir un socket, AF_INET es la familia y usamos SOCK_DGRAM para abrir un socket
        udp, el 0 es para el protocolo IP en la cabecera IP a envar o recibir
    */
    udp_socket = socket(AF_INET, SOCK_DGRAM, 0);

   //Aqui indicamos si el socket se abrio correctamente o no: -1 = Error, de otra forma se abre correctamente
    if(udp_socket == -1){
        perror("\nError al abrir el socket");
        exit(0);//salimos del programa
    }else{
        perror("\nExito al abrir el socket");//se abrio el socket
        local.sin_family = AF_INET; //address family: AF_INET
        local.sin_port = htons(0); //port in network byte order, la api de socket asigna el puerto
        local.sin_addr.s_addr = INADDR_ANY;

        /*
            Con bind enlazamos un nombre a un socket, comop parametros esta el socket, la direccion local en este
            caso servidor y el tamaño de la direccion
        */
        bindValue = bind(udp_socket,(struct sockaddr *)&local,sizeof(local));

        //Si bindValue es -1 no se pudo hacer el bind
        if(bindValue == -1){
            perror("\nError en bind");
            exit(0);//salimos del programa
        }else{
            perror("\nExito en el bind");//se hizo el bind
            remota.sin_family = AF_INET; //address family: AF_INET
            remota.sin_port = htons(53); //port in network byte order, cambio puerto serv
            remota.sin_addr.s_addr = inet_addr("8.8.8.8"); //inet_addr: convertir cadena

            /*
                sendto la usamos para mandar mensajes a otro conector, aqui especificamos la direccion 
                a donde transmitiremos el mensaje, en este caso al servidor
            */
            sendtoValue = sendto(udp_socket, msg, 100, 0, (struct sockaddr *)&remota, sizeof(remota));

            //Si devuelve -1 no se pudo enviar
            if(sendtoValue == -1){
                perror("\nError al enviar");
                exit(0);//salimos
            }else
                perror("\nExito al enviar"); //se envio el mensaje
        }
    }

    close(udp_socket); //cerramos el socket

    return 0;
}