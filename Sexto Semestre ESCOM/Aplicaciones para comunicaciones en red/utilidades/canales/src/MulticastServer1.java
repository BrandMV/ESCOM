import java.net.*;
import java.io.*;
import java.nio.*;
import java.nio.channels.*;
import java.util.*;
import java.net.StandardSocketOptions;

public class MulticastServer1{
  public final static int DEFAULT_PORT = 7;
  public final static int MAX_PACKET_SIZE = 65507;  
  
  static void displayInterfaceInformation(NetworkInterface netint) throws SocketException {
        System.out.printf("Display name: %s\n", netint.getDisplayName());
        System.out.printf("Name: %s\n", netint.getName());
        Enumeration<InetAddress> inetAddresses = netint.getInetAddresses();
        for (InetAddress inetAddress : Collections.list(inetAddresses)) {
            System.out.printf("InetAddress: %s\n", inetAddress);
        }
        System.out.printf("\n");
     }


  public static void main(String[] args) {
      int port = DEFAULT_PORT;
      SocketAddress host;
      try{
          BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
          Enumeration<NetworkInterface> nets = NetworkInterface.getNetworkInterfaces();
          int z=0;
          for (NetworkInterface netint : Collections.list(nets)){
              System.out.print("[Interfaz "+ ++z +"]:");
              displayInterfaceInformation(netint);
          }
          
          System.out.print("\nElige la interfaz multicast:");
          int interfaz = Integer.parseInt(br.readLine());
            //NetworkInterface ni = NetworkInterface.getByName("eth2");
          NetworkInterface ni = NetworkInterface.getByIndex(interfaz);
          br.close();
          DatagramChannel channel = DatagramChannel.open(StandardProtocolFamily.INET);
          channel.configureBlocking(false);
          channel.setOption(StandardSocketOptions.SO_REUSEADDR, true);
          DatagramSocket socket = channel.socket();
          SocketAddress address = new InetSocketAddress(port);
          socket.bind(address);
          channel.setOption(StandardSocketOptions.IP_MULTICAST_IF, ni);
          InetAddress group = InetAddress.getByName("230.0.0.1");
          channel.join(group, ni);
          System.out.println("Unido al grupo "+group.getHostAddress()+"... \nesperando datagramas..");
          Selector selector = Selector.open();
          channel.register(selector,SelectionKey.OP_READ);
          ByteBuffer buffer = ByteBuffer.allocateDirect(MAX_PACKET_SIZE);
          while(true){
             selector.select(5000);
             Set readyKeys = selector.selectedKeys();
             
               Iterator iterator = readyKeys.iterator();
               while(iterator.hasNext()){
                 SelectionKey key = (SelectionKey)iterator.next();
                 iterator.remove();
                 if(key.isReadable()){
                    buffer.clear();
                    SocketAddress client = channel.receive(buffer);
                    buffer.flip();
                    int echo = buffer.getInt();
                    System.out.println("Dato leido: "+echo);
                    continue;
                 }//if
             }//while2
          }//while
      }catch(IOException e){
	System.err.println(e);
      }//catch

  }//main
}//class