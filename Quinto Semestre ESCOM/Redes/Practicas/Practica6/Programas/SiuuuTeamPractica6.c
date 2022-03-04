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


unsigned char originMAC[6]; //para la MAC origen
unsigned char recvTram[1514];  //Para la trama a recibir será del mismo tamaño de 1524
unsigned char ethertype[2]={0x08,0x06}; //2 bytes para ethertype y se inicializa con ARP



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


/*
    Esta función de obtener datos recibe el descriptor del socket y nos devuelve
    el indice de nuestra interfaz de red.
    ESta funcion se encarga de obtener la MAC de nuestra maquina e imprimirla
    para identificarla en las tramas que recibiremos.
    De igual forma se encarga de regresar el indice de nuestra interfaz de red a partir del nombre de 
    nuestra interfaz.
*/
int obtenerDatos (int socketDesc)
{
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
    Esta funcion es para imprimir la trama recibida.
    Recibe el paquete (la trama) recibida y el tamaño de esta
*/
void imprimirTrama(unsigned char *packet, int size){    
    
   int i; //variable para loop
    
    /*
        El siguiente for es para imprimir la trama, vemos que va desde i hasta el tamaño
        de la trama recibida
    */
    for(i=0; i<size; i++){


        if( i < 6 ) //coloreamos de rojo la direccion origen
            red();
        if( i >= 6 && i <= 11 ) //coloreamos de amarillo la direccion fuente
            yellow();
        if( i >= 12 && i <= 13 ) //coloreamos de azul el ethertype
            blue();
        if( i >= 14 && i <= 1500 ) //coloreamos de verde los datos de la trama
            green();
        if( i >= 1501 && i <= 1514 )
            white();
        /*
            EL siguiente if es para darle formato parecido al de wireshark, una vez se hayan impreso 16 caracteres
            salta a la siguiente línea y continua con la impresión de los digitos
        */
        if(i%16 == 0)
            printf("\n"); //salto de lineal para hacer el formato de 16 en 16
        
       
        printf("%.2x ", packet[i]); //imprimimos los caracteres de dos en dos en formato hexadecimal

        reset();
    }
    red();
    printf("\n\nDireccion origen");
    yellow();
    printf("\nDireccion fuente");
    blue();
    printf("\nEthertype");
    green();
    printf("\nDatos");
    white();
    printf("\nBits de relleno");
    reset();
    //saltos de linea para mejorar legibilidad de la salida
    printf("\n");
    printf("\n");
}

/*
    ESta funcion recibe el socketDesc que es el descriptor de socket y la trama recibida.
    Esta funcion se encarga de recibir tramas de la red usando recvfrom
*/
void recibirTrama(int socketDesc, unsigned char *trama){

    int recvfromL; //para la funcion que recibe la trama

    /* 
        En esta caso la estructura será la tarjeta de red desde la cual recibiremos
        colocamos NULL ya que no nos importará desde cual tarjeta vamos a recibir, igual 
        debido a esto colocamos un 0 al final.
        Usamos un ciclo infinito para recibir tramas en loop.
    */
    while(1){
        recvfromL = recvfrom(socketDesc, trama, 1514, 0, NULL,0);
        if(recvfromL == -1){ //si hubo error al recibir regresa -1
            perror("\nError al recibir"); //imprimimos el error
            exit(0); //salimos del programa
        }else{
            /*
                En el siguiente if hacemos una comparación para solo capturar tramas
                que tengan mi MAC y evitar otro tráfico.
                Usamos la función memcpm y si en la trama aparece mi MAC se imprime.
                De igual forma hacemos otro filtro para que solo nos muestre tramas que tengan 
                peticiones ARP (0806)
            */
            if(!memcmp(trama+0, originMAC, 6)){
                imprimirTrama(trama, recvfromL); //imprimimos la trama recibida
                // break; //usamos este break para que solo imprima una trama
            }
            if(!memcmp(trama+12,ethertype,2)){
                imprimirTrama(trama, recvfromL); //imprimimos la trama recibida
                // break; //usamos este break para que solo imprima una trama
            }


        }
    }

}

int main(){
    
    int rawSocket, index; //variable para el socket crudo y el indice de la interfaz

    printf("\n\t\t\tRecibiendo una trama\n\n");

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
        perror("\nExito al abrir el socket"); //se abrio el socket
        index=obtenerDatos(rawSocket); //Aqui obtenemos los datos
        recibirTrama(rawSocket,recvTram); //Recibimos tramas
    }
   
    close(rawSocket); //Cerramos el socket
    printf("\n"); //salto de lineal para leer mejor la salida
    return 0; //termina el programa
}
