#include <sys/socket.h>
#include <linux/if_packet.h>
#include <linux/if_ether.h>
#include <net/ethernet.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <string.h>
#include <stdio_ext.h> //para __fpurge(stdin)

//varibales para la estructura de la trama

unsigned char originMAC[6]; //para la MAC origen
unsigned char broadcastMAC[6]={0xff,0xff,0xff,0xff,0xff,0xff}; //longitud de 6 bytes e inicializamos para broadcast
unsigned char ethertype[2]={0x08,0x06}; //2 bytes para ethertype y se inicializa
//para la trama a enviar usamos un tamaño de  1514
unsigned char sentTrama[1514];

/*
    Esta función de obtener datos recibe el descriptor del socket y nos devuelve
    el indice de nuestra interfaz de red.
    ESta funcion se encarga de obtener la MAC de nuestra maquina e imprimirla
    para identificarla en las tramas que recibiremos.
    De igual forma se encarga de regresar el indice de nuestra interfaz de red a partir del nombre de 
    nuestra interfaz.
*/

int obtenerDatos (int socketDesc){
    struct ifreq nic; //estructura ifreq para consultar datos de nuestra interfaz, man netdevice 
    char interName[20]; //variable que alamcenara el nombre de nustra interfaz
    int i,interIndex; //variable apra loop y para el indice

    printf("\nInserta el nombre de la interfaz de red: ");
    scanf("%s", interName); //leemos el nombre de la interfaz de red

    //almacenamos el nombre de la interfaz en nic.ifr_name
    strcpy(nic.ifr_name,interName);

     /*
        La función ioctl la usamos para manipular los valores de los paramatros de un socket.
        Proporciona una iterfaz para controlar el comportamiento de dispositivos y de sus descriptores,
        en este caso de sockets            
    */
    // obtener el indice usando SIOCGIFINDEX
     if(ioctl(socketDesc,SIOCGIFINDEX,&nic)==-1){
        perror("\n Error al obtener el indice de red"); //error si no obtenemos el indice
        exit(0);    // salimos del programa
    }
    else{

        interIndex=nic.ifr_ifindex; //almacenamos el indice en nuestra variable
        printf("\n El indice es: %d", interIndex); //imprimimos nuestro indice de red
        

            //obtener la MAC usando SIOCGIFHWADDR
            if(ioctl(socketDesc,SIOCGIFHWADDR,&nic)==-1){
                perror("\nError al obtener la MAC"); //error si no obtiene la MAC
                exit(0); //salimos del programa
            }
            else{
                //si obtenemos la mac la almacenamos en nuestra variable global originMAC,
               memcpy(originMAC, nic.ifr_hwaddr.sa_data,6);

               printf("\n La MAC es: ");
               //realizamos un for hasta 6 para imprimir nuestra MAC, usamos el formato hexadecimal usando %.2x
                for(i=0;i<6;i++)
                {
                    printf("%.2x: ", originMAC[i]);
                }
                printf("\n"); //salto de linea para leer mejor la salida del programa

            }
    }
    
    return interIndex; //Retornamos el indice
}

/*
    Esta función se encarga de estructurar la trama, recibe la trama, como sabemos debe ser
    un unsigned char con el tamaño de 1514.
    lo que se hace es copiar en la trama los valores de la mac origen, de la mac de broadcast, el ethertye
    y los datos, en este caso un mensaje
*/
void estructuraTrama(unsigned char *trama){
    unsigned char mensaje[50];

    __fpurge(stdin); //Limpíamops buffer del teclado
    printf("\n"); //salto de linea para mejorar legibilidad
    printf("Ingrese el mensaje de la trama: ");
    fgets(mensaje, sizeof(mensaje),stdin); //esperamos a que se escriba un mensaje a enviar


    /*
        memcpy nos sirve para copiar n caracteres de un espacio de memoria 
        a un espacio de memoria destino, en esta caso el destino es la trama  y se copiaran
        nuestros datos.
    */
    memcpy(trama+0,broadcastMAC,6); //copiamos en las primeras 6 posiciones la mac de broadcast
    memcpy(trama+6,originMAC,6); //copiamos a partir de la posicion 6 la mac origen
    memcpy(trama+12,ethertype,2); //posteriormente copiamos los bytes ppara ethertype
    memcpy(trama+14,mensaje, strlen(mensaje)+1);//copiamos nuestro mensaje a la trama
}

/*
    Esta función envia la trama, recibe el descriptor del socket, el indice de nuestra interfaz de red
    y la trama a enviar
*/
void EnviarTrama (int socketDesc, int interIndex, unsigned char *trama)
{

    int sendTam;
    struct sockaddr_ll interfaz; //usamos la estructura sockaddr_ll, esta es una direccion de la capa fisica
                                 // man packet, de esta manera podemos mandar paquetes de nuestra interfaz


    /*
        con memset copiamos el caracter 0x00, a los primeros n caracteres de nuestra interfaz
        en este caso los n caracterez son el tamaño de la interfaz
    */
    memset(&interfaz, 0x00, sizeof(interfaz));

    interfaz.sll_family = AF_PACKET; //le asignamos la familia AF_PACKET
    interfaz.sll_protocol = htons(ETH_P_ALL); //Le asignamos todos los protocolos
    interfaz.sll_ifindex = interIndex; //el indice será el obtenido previamente

    /*
        Aquí mandamos la trama haciendo uso de la función sendto, con una tamaño de 60
    */

    sendTam = sendto(socketDesc,trama,60,0,(struct sockaddr *)&interfaz, sizeof(interfaz));
    
        if(sendTam == -1){
            perror("\nError"); //si es -1 manda error de envio de trama
            exit(0);//salimos
        } else perror("\nExito al enviar"); //se envia correctamente
}

int main(){
    
    int rawSocket, index; //variable para el socket crudo y el indice de la interfaz
    char opc = 's';

    printf("\n\t\t\nEnviando una trama\n\n");

    /*
        primer parametro: familia a trabajar
        segundo parametro: SOCK_RAW: para trabajar en la capa de enlace de datos
        tercer parametro: colocamos todos los protocolos
        socket Devuelve un valor entero
    */
    rawSocket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    
    if(rawSocket == -1){
        perror("\nError al abrir el socket"); //si no se puede abrir un socket manda error
        exit(0);    //salimos del programa
    } else{
        perror("\nExito al abrir el socket");
        index = obtenerDatos(rawSocket); //Aqui obtenemos el indice de nuestra interfaz, ademas de la MAC
        
        //usamos un while para mandar tramas si el usuario desea
        while( opc == 's'){
            estructuraTrama(sentTrama);   //Le damos la estructura a la trama
            EnviarTrama(rawSocket,index,sentTrama);  //enviamos nuestra trama
            printf("\nInserte una s para seguir mandando tramas, de lo contrario inserte una n: ");
            scanf("%c", &opc);
        }
    }
   
    close(rawSocket); //cerramos nuestro socket
    printf("\n"); //salto de linea para mejorar legibilidad
    return 0; //se termina el programa
}
