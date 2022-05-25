import java.net.*;
import java.io.*;
import java.nio.*;
import java.nio.channels.*;
import java.util.*;

public class UDPEchoClient{
public final static int DEFAULT_PORT = 7;
private final static int LIMIT = 100;

public static void main(String[] args) {
    int port = DEFAULT_PORT;
    try{
         port = Integer.parseInt(args[1]);
    }catch(Exception e){
      System.err.println(e);
    }//catch
    SocketAddress remote;
    try{
         remote = new InetSocketAddress(args[0], port);
    }catch(Exception e){
      System.err.println("Sintaxis: java USPEchoClient host [port]");
       return;
    }//catch

    try{
        DatagramChannel channel = DatagramChannel.open();
        channel.configureBlocking(false);
        channel.connect(remote);
        Selector selector = Selector.open();
        channel.register(selector,SelectionKey.OP_READ | SelectionKey.OP_WRITE);
        ByteBuffer buffer = ByteBuffer.allocateDirect(4);
        int n = 0;
        int numbersRead =0;
        while(true){
          //espera 1 minuto por la conexi�n
          selector.select(60000);
          Set readyKeys = selector.selectedKeys();
          if(readyKeys.isEmpty() && n == LIMIT){
               break;
          } else {
               Iterator iterator = readyKeys.iterator();
               while(iterator.hasNext()){
                 SelectionKey key = (SelectionKey)iterator.next();
                 iterator.remove();
                 if(key.isReadable()){
                    buffer.clear();
                    channel.read(buffer);
                    buffer.flip();
                    int echo = buffer.getInt();
                    System.out.println("Leido: "+echo);
                    numbersRead++;
                 }//if
                 if(key.isWritable()){
                    buffer.clear();
                    buffer.putInt(n);
                    buffer.flip();
                    channel.write(buffer);
                    System.out.println("Escrito: "+n);
                    n++;
                    if(n==LIMIT){
                        //todos los paquetes han sido escritos; cambiamos a modo de solo lectura
                        key.interestOps(SelectionKey.OP_READ);
                    }//if
                 }//if
               }//while
          }//else
        }//while
        System.out.println("Enviados "+numbersRead+" de "+LIMIT);
        System.out.println("Tasa de exito: "+100.0*numbersRead/LIMIT+" %");
    }catch(Exception e){
      System.err.println(e);
    }//catch

}//main
}//class