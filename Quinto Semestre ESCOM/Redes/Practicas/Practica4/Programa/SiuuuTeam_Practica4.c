#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/if_packet.h>
#include <net/ethernet.h> //L2 protocols
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <string.h>

void obtenerDatos(int ds);

/*
    En la compilacion se recomienda ejecutar en modo root
*/

unsigned char MAC[6], MASK[4], IP[4], BROAD[4]; //variables para obtener datos
int MTU;  //variable para obtener el MTU

void obtenerDatos(int ds)
{                     //ds: Descriptor de socket
    int i = 0;        //variable para loop
    char nombre[10];  //variable que guarda el nombre de la interfaz de red
    struct ifreq nic; //variable para usar la estructura ifreq
    int index;        //variable para guardar el index de la interfaz de red
    char opc;         //varibale para indicar como queremos obtener los datos n = a
                    // partir del nombre i = a partir del indice

    printf("\nPara Obtener datos a partir del nombre introduzca n");
    printf("\nPara Obtener datos a partir del indice introduzca i");
    printf("\nOpcion: ");
    scanf("%c", &opc); //leemos el indice

    if (opc == 'n') //si es n, obtenemos datos a partir del nombre
    {
        //leemos el nombre de la interfaz de red de la que queremos saber los datos
        printf("\nIntroduce la interfaz de red: ");
        scanf("%s", nombre);
        strcpy(nic.ifr_name, nombre); //copiamos el nombre introducdio a la variable ifr_name: nombre de la interfaz
        
        
        /*
            La función ioctl la usamos para manipular los valores de los paramatros de un socket.
            Proporciona una iterfaz para controlar el comportamiento de dispositivos y de sus descriptores,
            en este caso de sockets            
        */
        // obtener el indice usando SIOCGIFINDEX
        if (ioctl(ds, SIOCGIFINDEX, &nic) == -1)
            perror("Error al obtener el indice"); //si hay error manda este error
        else
            printf("\nEl indice es: %d", nic.ifr_ifindex); //imprimimos el indice de la interfaz de red

        //obtener la MAC usando SIOCGIFHWADDR
        if (ioctl(ds, SIOCGIFHWADDR, &nic) == -1)
            perror("Error al obtener la MAC"); //si hay error manda este error
        else
        {
            //copiamos los 6 primeros datos de la estructura nic.ifr_hwaddr.sa_data
            //ya que este es el espacio correspondiente a la MAC
            memcpy(MAC, nic.ifr_hwaddr.sa_data, 6);
            printf("\nMAC: ");
            //recorremos nuestro arreglo de 6 posiciones para imrpimir la MAC
            for (i = 0; i < 6; i++)
                printf("%2x:", MAC[i]);
        }

        //obtener la IP usando SIOCGIFADDR
        if (ioctl(ds, SIOCGIFADDR, &nic) == -1)
            perror("Error al obtener la IP"); //si hay error manda este error
        else
        {
            //copiamos los 6 primeros datos de la estructura nic.addr.sa_data
            memcpy(IP, nic.ifr_addr.sa_data, 6);
            printf("\nIP: ");
            //como trabajamos a nivel de bytes, para la ip los datos que imprimiremos seran del 2 al 6
            for (i = 2; i < 6; i++)
                printf("%2d:", IP[i]);
        }

        //obtener la direccion de broadcast usando SIOCGIFBRDADDR
        if (ioctl(ds, SIOCGIFBRDADDR, &nic) == -1)
            perror("Error al obtener la direccion de broadcast"); //si hay error manda este error
        else
        {
            //copiamos los 6 primeros datos de la estructura nic.ifr_broadaddr.sa_data
            memcpy(BROAD, nic.ifr_broadaddr.sa_data, 6);
            printf("\nBroadcast: ");
            //como trabajamos a nivel de bytes, para la direccion de broadcast los datos que imprimiremos seran del 2 al 6
            for (i = 2; i < 6; i++)
                printf("%2d:", BROAD[i]);
        }

        //obtener la mascara de subred SIOCGIFNETMASK
        if (ioctl(ds, SIOCGIFNETMASK, &nic) == -1)
            perror("Error al obtener la mascara de subred"); //si hay error manda este error
        else
        {
            //copiamos los 6 primeros datos de la estructura nic.ifr_netmask.sa_data
            memcpy(MASK, nic.ifr_netmask.sa_data, 6);
            //imprimimos la mascara de subred con un for que recorre las posiciones, las imprimimos como decimales
            printf("\nMASK: ");
            for (i = 2; i < 6; i++)
                printf("%2d:", MASK[i]);
        }

        //obtener el MTU (Maximum Transfer UNit) usando SIOCGIFMTU
        if (ioctl(ds, SIOCGIFMTU, &nic) == -1)
            perror("Error al obtener el MTU"); //si hay error manda este error
        else
        {
            printf("\nMTU: %d ", nic.ifr_mtu); //imprimimos el MTU de la interfaz de red
        }
    }
    else //si no obtenemos datos a partir del indice
    {
        //Esta parte es para obtener los datos de la interfaz a partir de su indice
        printf("\nIntroduce el indice de la interfaz de red: ");
        scanf("%d", &index); //leemos el indice

        nic.ifr_ifindex = index; //establecemos el indice en la estructura
        
        //obtenemos el nombre de la interfaz de red con SIOCGIFNAME
        if (ioctl(ds, SIOCGIFNAME, &nic) == -1)
            perror("Error al obtener el nombre"); //si hay error manda este error
        else
            printf("\nEl nombre es: %s", nic.ifr_name); //imprimimos el indice de la interfaz de red

        //obtener la MAC usando SIOCGIFHWADDR
        if (ioctl(ds, SIOCGIFHWADDR, &nic) == -1)
            perror("Error al obtener la MAC"); //si hay error manda este error
        else
        {
            //copiamos los 6 primeros datos de la estructura nic.ifr_hwaddr.sa_data
            //ya que este es el espacio correspondiente a la MAC
            memcpy(MAC, nic.ifr_hwaddr.sa_data, 6);
            printf("\nMAC: ");
            //recorremos nuestro arreglo de 6 posiciones para imrpimir la MAC
            for (i = 0; i < 6; i++)
                printf("%2x:", MAC[i]);
        }

        //obtener la IP usando SIOCGIFADDR
        if (ioctl(ds, SIOCGIFADDR, &nic) == -1)
            perror("Error al obtener la IP"); //si hay error manda este error
        else
        {
            //copiamos los 6 primeros datos de la estructura nic.ifr_addr.sa_data
            memcpy(IP, nic.ifr_addr.sa_data, 6);
            printf("\nIP: ");
            //como trabajamos a nivel de bytes, para la ip los datos que imprimiremos seran del 2 al 6
            for (i = 2; i < 6; i++)
                printf("%2d:", IP[i]);
        }

          //obtener la direccion de broadcast usando SIOCGIFBRDADDR
        if (ioctl(ds, SIOCGIFBRDADDR, &nic) == -1)
            perror("Error al obtener la direccion de broadcast"); //si hay error manda este error
        else
        {
            //copiamos los 6 primeros datos de la estructura nic.ifr_broadaddr.sa_data
            memcpy(BROAD, nic.ifr_broadaddr.sa_data, 6);
            printf("\nBroadcast: ");
            //como trabajamos a nivel de bytes, para la direccion de broadcast los datos que imprimiremos seran del 2 al 6
            for (i = 2; i < 6; i++)
                printf("%2d:", BROAD[i]);
        }

        //obtener la mascara de subred SIOCGIFNETMASK
        if (ioctl(ds, SIOCGIFNETMASK, &nic) == -1)
            perror("Error al obtener la MAC"); //si hay error manda este error
        else
        {
            //copiamos los 6 primeros datos de la estructura nic.ifr_netmask.sa_data
            memcpy(MASK, nic.ifr_netmask.sa_data, 6);
            //imprimimos la mascara de subred con un for que recorre las posiciones, las imprimimos como decimales
            printf("\nMASK: ");
            for (i = 2; i < 6; i++)
                printf("%2d:", MASK[i]);
        }

        //obtener el MTU (Maximum Transfer UNit) usando SIOCGIFNETMASK
        if (ioctl(ds, SIOCGIFMTU, &nic) == -1)
            perror("Error al obtener el MTU"); //si hay error manda este error
        else
        {
            printf("\nMTU: %d ", nic.ifr_mtu); //imprimimos el MTU de la interfaz de red
        }
    }
}

int main()
{
    int packet_socket; //variable para el socket

    printf("\n\t\t\tInteracciones con la NIC\n\n");


    /*
        primer parametro: familia a trabajar
        segundo parametro: SOCK_RAW: para trabajar en la capa de enlace de datos
        tercer parametro: colocamos todos los protocolos
        socket Devuelve un valor entero
    */
    packet_socket = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));

    if (packet_socket == -1)
    { //-1 si no se pudo abrir el socket
        perror("Error al abrir el socket");
    }
    else
    {
        perror("Exito al abrir el socket");
        obtenerDatos(packet_socket); //mandamos a llamar a al función que obtiene todos los datos
    }
    close(packet_socket); //cerramos el socket
    printf("\n");

    return 0; 
}