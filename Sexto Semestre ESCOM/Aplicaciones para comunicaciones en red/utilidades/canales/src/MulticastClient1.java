import java.net.*;
import java.io.*;
import java.nio.*;
import java.nio.channels.*;
import java.util.*;

public class MulticastClient1{
public final static int DEFAULT_PORT = 7;
private final static int LIMIT = 100;

static void displayInterfaceInformation(NetworkInterface netint) throws SocketException {
        System.out.printf("Display name: %s\n", netint.getDisplayName());
        System.out.printf("Name: %s\n", netint.getName());
        String multicast = (netint.supportsMulticast())?"Soporta multicast":"No soporta multicast";
        System.out.printf("Multicast: %s\n", multicast);
        Enumeration<InetAddress> inetAddresses = netint.getInetAddresses();
        for (InetAddress inetAddress : Collections.list(inetAddresses)) {
            System.out.printf("InetAddress: %s\n", inetAddress);
        }
        System.out.printf("\n");
     }

public static void main(String[] args) {
    int port = DEFAULT_PORT;
//    boolean flag=false;
    try{
         port = Integer.parseInt(args[1]);
    }catch(Exception e){
      System.err.println(e);
    }//catch
    SocketAddress remote;
    String hhost="230.0.0.1";
    try{
         remote = new InetSocketAddress(hhost, port);
    }catch(Exception e){
      System.err.println("Sintaxis: java UDPEchoClient host [port]");
       return;
    }//catch

    try{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Enumeration<NetworkInterface> nets = NetworkInterface.getNetworkInterfaces();
        int z=0;
          for (NetworkInterface netint : Collections.list(nets)){
              System.out.print("[Interfaz "+ ++z +"]:");
             displayInterfaceInformation(netint);
          }//for
        System.out.print("\nElige la interfaz multicast:");
        int interfaz = Integer.parseInt(br.readLine());
        //NetworkInterface ni = NetworkInterface.getByName("eth2");
        NetworkInterface ni = NetworkInterface.getByIndex(interfaz);
        br.close();
        System.out.println("\nElegiste "+ni.getDisplayName());
        DatagramChannel channel = DatagramChannel.open(StandardProtocolFamily.INET);
        channel.configureBlocking(false);
        channel.setOption(StandardSocketOptions.SO_REUSEADDR, true);
        channel.setOption(StandardSocketOptions.IP_MULTICAST_IF, ni);
        channel.setOption(StandardSocketOptions.IP_MULTICAST_TTL, 128);
        InetAddress group = InetAddress.getByName("230.0.0.1");
        channel.join(group, ni);
        Selector selector = Selector.open();
        channel.register(selector,SelectionKey.OP_WRITE);
        ByteBuffer buffer = ByteBuffer.allocateDirect(4);
        int n = 0;
        int numbersRead =0;
        while(n<LIMIT){
          //espera 5 segundos por la conexión
          
         
          selector.select(5000);
          Iterator<SelectionKey>it = selector.selectedKeys().iterator();
          while(it.hasNext()){
                 SelectionKey key = (SelectionKey)it.next();
                 it.remove();
                 if(key.isWritable()){
                    buffer.clear();
                    buffer.putInt(++n);
                    buffer.flip();
                    channel.send(buffer, remote);
                    System.out.println("Escribiendo el dato: "+n);
                    continue;
                 }//if
                 //break;
               }//while
               //break;
        }//while
    channel.close();
    }catch(Exception e){
      System.err.println(e);
    }//catch

}//main
}//class