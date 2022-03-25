import java.io.*;
import java.net.*;
import java.util.Collections;
import java.util.Enumeration;


/**
 *
 * @author axel
 */
public class CHMM {

    static void despliegaInfoNIC(NetworkInterface netint) throws SocketException {
        System.out.printf("Nombre de despliegue: %s\n", netint.getDisplayName());
        System.out.printf("Nombre: %s\n", netint.getName());
        String multicast = (netint.supportsMulticast())?"Soporta multicast":"No soporta multicast";
        System.out.printf("Multicast: %s\n", multicast);
        Enumeration<InetAddress> inetAddresses = netint.getInetAddresses();
        for (InetAddress inetAddress : Collections.list(inetAddresses)) {
            System.out.printf("Direccion: %s\n", inetAddress);
        }
        System.out.printf("\n");
     }

    
    public static void main(String[] args){
      try{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Enumeration<NetworkInterface> nets = NetworkInterface.getNetworkInterfaces();
        int z=0,pto= 9931;
          for (NetworkInterface netint : Collections.list(nets)){
              System.out.print("[Interfaz "+ ++z +"]:");
             despliegaInfoNIC(netint);
          }//for
        System.out.print("\nElige la interfaz multicast:");
        int interfaz = Integer.parseInt(br.readLine());
        //NetworkInterface ni = NetworkInterface.getByName("eth2");
        NetworkInterface ni = NetworkInterface.getByIndex(interfaz);
        br.close();
        System.out.println("\nElegiste "+ni.getDisplayName());

          
          MulticastSocket cl = new MulticastSocket(pto);
          cl.setReuseAddress(true);
          InetAddress gpo = InetAddress.getByName("230.1.1.1");
          //InetAddress gpo = InetAddress.getByName("ff3e:40:2001::1");
          SocketAddress dir;
            try{
                 dir = new InetSocketAddress(gpo,pto);
            }catch(Exception e){
              System.err.println("Sintaxis: java UDPEchoClient host [port]");
               return;
            }//catch

 
          
          cl.joinGroup(dir, ni);
          //cl.joinGroup(gpo);
          System.out.println("Servicio iniciado y unido al grupo.. comienza escucha de mensajes");
          for(;;){
              DatagramPacket p = new DatagramPacket(new byte[65535],65535);
              cl.receive(p);
              System.out.println("Datagrama multicast recibido desde "+p.getAddress()+":"+p.getPort()+"Con el mensaje:"+new String(p.getData(),0,p.getLength()));
              
              
              
          }//for
          
      }catch(Exception e){
          e.printStackTrace();
      }
  }    
}
