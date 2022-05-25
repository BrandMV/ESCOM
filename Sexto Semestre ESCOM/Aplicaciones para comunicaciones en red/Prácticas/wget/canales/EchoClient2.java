import java.nio.*;
import java.nio.charset.*;
import java.net.*;
import java.nio.channels.*;
//import java.nio.CharBuffer;
//import java.nio.channels.SocketChannel;
//import java.net.InetSocketAddress;
//import java.nio.ByteBuffer;
import java.io.*;

public class EchoClient2{
   private Charset charset=Charset.forName("GBK");
 
   public String decode(ByteBuffer buffer){ 
     CharBuffer charBuffer= charset.decode(buffer);//decode(buffer);
     return charBuffer.toString();
   }
    public ByteBuffer encode(String str){  
     return charset.encode(str);
   }
 

public static void main(String [] argv)throws Exception{
String host = "localhost";
int port = 13;
if (argv.length == 2) {
host = argv [0];
port = Integer.parseInt (argv [1]);
}
InetSocketAddress addr = new InetSocketAddress (host, port);
SocketChannel sc = SocketChannel.open();
sc.configureBlocking (false);
System.out.println ("initiating connection");
sc.connect (addr);
while ( ! sc.finishConnect()) {
doSomethingUseful();
}
System.out.println ("connection established");
/*******************************/
ByteBuffer buf = ByteBuffer.allocateDirect(1024);
Charset cset=Charset.defaultCharset();  //Charset.forName("GBK");

    try {
        // Clear the buffer and read bytes from socket
        buf.clear();
        int numBytesRead = sc.read(buf);
        buf.flip();
        //CharBuffer cb= cset.decode(buf);
        String datos=(cset.decode(buf)).toString();
        System.out.println("Datos: "+datos);
        //System.out.println("Buffer: "+cb.toString());
       
    } catch (IOException e) {
        // Connection may have been closed
    }

/*******************************/
// Do something with the connected socket
// The SocketChannel is still nonblocking
sc.close();
}
private static void doSomethingUseful(){
System.out.println ("doing something useless");
}

}//class
