import java.net.*;
import java.io.*;
import java.nio.*;
import java.nio.channels.*;

public class UDPEchoServer{
  public final static int DEFAULT_PORT = 7;
  public final static int MAX_PACKET_SIZE = 65507;  

  public static void main(String[] args) {
      int port = DEFAULT_PORT;
      try{
          DatagramChannel channel = DatagramChannel.open();
          DatagramSocket socket = channel.socket();
          SocketAddress address = new InetSocketAddress(port);
          socket.bind(address);
          ByteBuffer buffer = ByteBuffer.allocateDirect(MAX_PACKET_SIZE);
          while(true){
             SocketAddress client = channel.receive(buffer);
             buffer.flip();
             channel.send(buffer,client);
             buffer.clear();
          }//while
      }catch(IOException e){
	System.err.println(e);
      }//catch
  }//main
}//class