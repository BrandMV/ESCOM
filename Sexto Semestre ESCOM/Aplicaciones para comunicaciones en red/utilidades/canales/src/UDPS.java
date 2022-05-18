import java.nio.*;
import java.nio.channels.*;
import java.net.InetSocketAddress;
import java.net.SocketAddress;
import java.util.Iterator;
/**
 *
 * @author axel
 */
public class UDPS {
    public static void main(String[] args){
        try{
           int pto=7;
           InetSocketAddress dir = new InetSocketAddress(pto);
           DatagramChannel s = DatagramChannel.open();
           s.configureBlocking(false);
           s.socket().bind(dir);
           Selector sel = Selector.open();
           s.register(sel, SelectionKey.OP_READ);
           ByteBuffer b = ByteBuffer.allocate(4);
           System.out.println("Servidor listo.. Esperando datagramas...");
           //int n=0;
           while(true){
               sel.select();
               Iterator<SelectionKey>it = sel.selectedKeys().iterator();
               while(it.hasNext()){
                   SelectionKey k = (SelectionKey)it.next();
                   it.remove();
                   if(k.isReadable()){
                      DatagramChannel ch = (DatagramChannel)k.channel();
                      b.clear();
                      SocketAddress emisor = ch.receive(b);
                      b.flip();
                      InetSocketAddress d = (InetSocketAddress)emisor;
                      System.out.println("Datagrama recibido desde "+ d.getAddress()+":"+d.getPort());
                      System.out.println("Dato: "+b.getInt());
                      continue;
                   }//if
               }//while
           }//while
           //cl.close();
        }catch(Exception e){
            e.printStackTrace();
        }//catch
    }//main
}
