#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h> //L2 protocols
#include <netinet/ip.h> 
#include <arpa/inet.h>
#include <string.h>
#include <stdio_ext.h>


int main(){
    //comValue: para sendto y rcvfrom, lengthRecv: medir tamaño de datos que me envian, 
    //udp_socket será para el socket
    int udp_socket, bindValue, comValue, lengthRecv; 
    struct sockaddr_in local, remota;//estructuras para el servidor y client
    unsigned char paqRec[512]; //Buffer para recibir información del servidor
    unsigned char msg[100];//arreglo para guardar los mensajes enviados 


    printf("\n\n\t\t\t*****CHAT CLIENTE A SERVIDOR*****\n\n");

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
        local.sin_addr.s_addr = INADDR_ANY;//cualquiera al ser comunicacion local en la maquina

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
            remota.sin_port = htons(8080); //port in network byte order, cambio puerto serv
            remota.sin_addr.s_addr = inet_addr("10.0.2.15"); //inet_addr: convertir cadena, cambia puerto servidor

            lengthRecv = sizeof(remota);//calculamos el comValueaño de la estrucutra remota

            //ciclo 
            while(1){

                //Solicitando mensaje a enviar
                __fpurge(stdin);//Limpíamops buffer del teclado
                printf("\nIngresa un mensaje: ");
                fgets(msg, sizeof(msg),stdin);//esperamos a que se escriba un mensaje a enviar

                /*
                    sendto la usamos para mandar mensajes a otro conector, aqui especificamos la direccion 
                    a donde transmitiremos el mensaje, en este caso al servidor
                */
                comValue = sendto(udp_socket, msg, strlen(msg)+1, 0, (struct sockaddr *)&remota, sizeof(remota));

                //Si devuelve -1 no se pudo enviar
                if(comValue == -1){
                    perror("\nError al enviar");
                    exit(0);//salimos
                }else
                    perror("\nExito al enviar");
                
                /*
                    para recibir usaremos la función recvfrom
                    EL buffer se definde 512 bytes porque es la cantidad idonea en los sockets para recbir 
                    informacion
                    Flags: 0 = manera bloqueante: para esperar a que me llegue algo
                    &lengthRecv es el tamaño de remota
                */
                comValue = recvfrom(udp_socket, paqRec, sizeof(paqRec), 0, (struct sockaddr *)&remota, &lengthRecv);

                //Si hay error al recibir devuelve -1
                if(comValue == -1){
                    perror("\nError al recibir");
                    exit(0);//Salimos del programa
                }else
                    printf("\nServidor: %s\n\n", paqRec);//Si no hay error, imprimimos el paquete recibido

            
        }
    }

    close(udp_socket);//cerramos el socket

    return 0;
    }
}