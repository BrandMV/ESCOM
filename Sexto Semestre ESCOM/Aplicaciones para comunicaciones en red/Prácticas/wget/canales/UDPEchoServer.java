import java.net.*;
import java.io.*;
import java.nio.*;
import java.nio.channels.*;
import java.util.*;

public class UDPEchoServer{
  public final static int DEFAULT_PORT = 7;
  public final static int MAX_PACKET_SIZE = 65507;  

  public static void main(String[] args) {
      int port = DEFAULT_PORT;
      SocketAddress host;
      try{
          DatagramChannel channel = DatagramChannel.open();
          channel.configureBlocking(false);
          DatagramSocket socket = channel.socket();
          SocketAddress address = new InetSocketAddress(port);
          socket.bind(address);
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
	  if(echo==1000){ 
	    channel.close();
	    System.exit(0);
	  } else{
                    System.out.println("Dato leido: "+echo);
	  buffer.flip();
                    channel.send(buffer,client);
	}//else
                 }//if
                 //if(key.isWritable()){
                 //   System.out.println("Nada");
                // }//if
             }//while2
          }//while
      }catch(IOException e){
	System.err.println(e);
      }//catch

  }//main
}//class