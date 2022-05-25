import java.nio.*;
import java.nio.channels.*;
import java.nio.charset.*;
import java.net.*;
import java.io.*;


public class EchoServer {
  	      public static void main(String args[]) throws IOException {
      // RFC867 specifies port 13 for this service.  On Unix platforms,
      // you need to be running as root to use that port, so we allow
      // this service to use other ports for testing.
      int port = 13;  
      if (args.length > 0) port = Integer.parseInt(args[0]);
  
      // Create a channel to listen for connections on.
      ServerSocketChannel server = ServerSocketChannel.open();
  
      // Bind the channel to a local port.  Note that we do this by obtaining
      // the underlying java.net.ServerSocket and binding that socket.
      server.socket().bind(new InetSocketAddress(port));
  
      // Get an encoder for converting strings to bytes
      CharsetEncoder encoder = Charset.forName("US-ASCII").newEncoder();
  
  	      for(;;) {  // Loop forever, processing client connections
          // Wait for a client to connect
          SocketChannel client = server.accept();
          Socket cl = client.socket();
          System.out.println ("Received request from " + cl.getInetAddress() + ":" + cl.getPort() );
          // Build response string, wrap, and encode to bytes
          String date = new java.util.Date().toString() + "\r\n";
          ByteBuffer response = encoder.encode(CharBuffer.wrap(date));
  
          // Send the response to the client and disconnect.
          client.write(response);
          client.close();
      }
      }
}