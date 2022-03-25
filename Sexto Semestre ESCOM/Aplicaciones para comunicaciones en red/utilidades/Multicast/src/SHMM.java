import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.*;
import java.util.Collections;
import java.util.Enumeration;
//import java.io.*;

/**
 *
 * @author axel
 */
public class SHMM {
    
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
        int z=0,pto= 9930,pto_dst=9931;
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

          
          MulticastSocket s = new MulticastSocket(pto);
          s.setReuseAddress(true);
          s.setTimeToLive(255);
          InetAddress gpo = InetAddress.getByName("230.1.1.1");
          //InetAddress gpo = InetAddress.getByName("ff3e:40:2001::1");
          SocketAddress dir;
            try{
                 dir = new InetSocketAddress(gpo,pto);
            }catch(Exception e){
              e.printStackTrace();
               return;
            }//catch
            s.joinGroup(dir, ni);
            //s.joinGroup(gpo);
            String msj="Mensaje desde el servidor 3****";
            byte[] b = msj.getBytes();
            System.out.println("Servicio iniciado.. comienza envio de anuncios");
            for(;;){
              DatagramPacket p = new DatagramPacket(b,b.length,gpo,pto_dst);
              s.send(p);
                System.out.println("Mensaje enviado con un ttl="+s.getTimeToLive());
              try{
                  Thread.sleep(5000);
              }catch(InterruptedException ie){}
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }//main
}
