
import java.nio.*;
import java.io.*;
import java.nio.channels.*;

/**
 *
 * @author axele
 */
public class Stdnb {
  public static void main(String[] args){
      
      System.out.println("escribe texto:");
      try{
          ReadableByteChannel in = Channels.newChannel(System.in);
          Selector sel = Selector.open();
          ByteBuffer b = ByteBuffer.allocate(10);
          System.out.println("posicion:"+b.position()+" limite: "+b.limit());
          b.clear();
          while(in.read(b)!=-1){
            b.flip();
            System.out.println("buffer:"+ new String(b.array(),0,b.limit()));
            b.clear();
          }
          
      }catch(Exception e){
          e.printStackTrace();
      }//catch
  }   //main 
}
