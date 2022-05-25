import java.nio.channels.*;
import java.nio.*;
import java.io.*;
import java.net.InetSocketAddress;
import java.util.Iterator;

/**
 *
 * @author axel
 */

class Objeto implements Serializable{
  String x;
  float y;
  int z;

  public Objeto(String x, float y, int z){
      this.x=x;
      this.y=y;
      this.z=z;
  }
}//class

public class SNB {
   public static void main(String[] args){
       try{
           ServerSocketChannel s = ServerSocketChannel.open();
           s.configureBlocking(false);
           s.socket().bind(new InetSocketAddress(9999));
           Selector sel = Selector.open();
           s.register(sel, SelectionKey.OP_ACCEPT);
           System.out.println("Servidor listo.. esperando clientes...");
           while(true){
               sel.select();
               Iterator<SelectionKey> it = sel.selectedKeys().iterator();
               while(it.hasNext()){
                   SelectionKey k = (SelectionKey)it.next();
                   it.remove();
                   if(k.isAcceptable()){
                       ServerSocketChannel sch = (ServerSocketChannel)k.channel();
                       SocketChannel cl = sch.accept();
                       System.out.println("Cliente conectado desde: "+cl.socket().getInetAddress()+":"+cl.socket().getPort());
                       cl.configureBlocking(false);
                       cl.register(sel, SelectionKey.OP_READ|SelectionKey.OP_WRITE);
                       continue;
                   }//if
                   if(k.isReadable()){
                       ByteBuffer b = ByteBuffer.allocate(2000);
                       b.clear();
                       SocketChannel ch = (SocketChannel)k.channel();
                       ch.read(b);
                       b.flip();
                       if(b.hasArray()){
                           ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(b.array()));
                           Objeto o = (Objeto)ois.readObject();
                           System.out.println("Objeto recibido..");
                           System.out.println("x:"+o.x+" y:"+o.y+" z:"+o.z);
                           ch.write(b);
                           k.cancel();
                       }//if
                   }else if (k.isWritable()){

                   }//else
               }//while
           }//while

       }catch(Exception e){
           e.printStackTrace();
       }//catch
   }//main
}
