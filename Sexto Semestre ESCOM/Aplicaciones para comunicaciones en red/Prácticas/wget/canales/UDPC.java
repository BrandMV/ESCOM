import java.nio.*;
import java.nio.channels.*;
import java.net.InetSocketAddress;
import java.util.Iterator;
/**
 *
 * @author axel
 */
public class UDPC {
    public static void main(String[] args){
        try{
           int pto=7;
           InetSocketAddress dst = new InetSocketAddress("127.0.0.1",pto);
           DatagramChannel cl = DatagramChannel.open();
           cl.configureBlocking(false);
           Selector sel = Selector.open();
           cl.register(sel, SelectionKey.OP_WRITE);
           ByteBuffer b = ByteBuffer.allocate(4);
           int n=0;
           while(n<100){
               sel.select();
               Iterator<SelectionKey>it = sel.selectedKeys().iterator();
               while(it.hasNext()){
                   SelectionKey k = (SelectionKey)it.next();
                   it.remove();
                   if(k.isWritable()){
                      DatagramChannel ch = (DatagramChannel)k.channel();
                      b.clear();
                      b.putInt(n++);
                      b.flip();
                      ch.send(b, dst);
                      continue;
                   }//if
               }//while
           }//while
           cl.close();
           System.out.println("Termina envio de datagramas");
        }catch(Exception e){
            e.printStackTrace();
        }//catch
    }//main
}
