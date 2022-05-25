import java.net.*;
import java.io.*;
import java.nio.*;
import java.nio.channels.*;
import java.util.*;

public class MulticastClient{
public final static int DEFAULT_PORT = 1030;
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
        DatagramChannel channel = DatagramChannel.open();
        //DatagramChannel channel = DatagramChannel.open(StandardProtocolFamily.INET);
        channel.configureBlocking(false);
        channel.setOption(StandardSocketOptions.SO_REUSEADDR, true);
        channel.setOption(StandardSocketOptions.IP_MULTICAST_IF, ni);
       //channel.setOption(StandardSocketOptions.IP_MULTICAST_TTL, 128);
        SocketAddress address = new InetSocketAddress(DEFAULT_PORT);
        channel.bind(address);
        InetAddress group = InetAddress.getByName("ff3e:40:2001::1");
        //InetAddress group = InetAddress.getByName("230.0.0.1");
        channel.join(group, ni);
        System.out.println("Unido al grupo y escuchando datagramas...");
        Selector selector = Selector.open();
        channel.register(selector,SelectionKey.OP_READ);
        ByteBuffer buffer = ByteBuffer.allocateDirect(4);
        int n = 0;
        int numbersRead =0;
        while(true){
          //espera 5 segundos por la conexión
          selector.select(5000);
          Iterator<SelectionKey>it = selector.selectedKeys().iterator();
          while(it.hasNext()){
                 SelectionKey key = (SelectionKey)it.next();
                 it.remove();
                 if(key.isReadable()){
                    buffer.clear();
                    SocketAddress remoto = channel.receive(buffer);
                    InetSocketAddress emisor = (InetSocketAddress)remoto;
                    buffer.flip();
                    int dato = buffer.getInt();
                    System.out.println("Dato leido desde "+emisor.getAddress()+":"+emisor.getPort()+"  -->"+dato);
                    continue;
                 }//if
                 //break;
               }//while
               //break;
        }//while
//    channel.close();
    }catch(Exception e){
      System.err.println(e);
    }//catch

}//main
}//class