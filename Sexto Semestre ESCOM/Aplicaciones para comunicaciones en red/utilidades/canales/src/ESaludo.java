import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.*;
import java.nio.*;
import java.nio.channels.*;
import java.util.Iterator;

/**
 *
 * @author axele
 */
public class ESaludo {
    public static void main(String[] args){
        try{
            InetSocketAddress dst = new InetSocketAddress("127.0.0.1",1234);
            DatagramChannel cl = DatagramChannel.open();
            cl.configureBlocking(false);
            Selector sel = Selector.open();
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            cl.register(sel,SelectionKey.OP_READ|SelectionKey.OP_WRITE);
            for(;;){
                sel.select();
                Iterator <SelectionKey> it = sel.selectedKeys().iterator();
                while(it.hasNext()){
                    SelectionKey k = (SelectionKey)it.next();
                    it.remove();
                    if(k.isWritable()){
                        DatagramChannel ch = (DatagramChannel)k.channel();
                        System.out.println("Escribe tu nombre:");
                        String nombre = br.readLine();
                        ByteBuffer b = ByteBuffer.wrap(nombre.getBytes());
                        ch.send(b,dst);
                        k.interestOps(SelectionKey.OP_READ);
                        continue;
                    }else if(k.isReadable()){
                        DatagramChannel ch = (DatagramChannel)k.channel();
                        ByteBuffer b1 = ByteBuffer.allocate(2000);
                        b1.clear();
                        SocketAddress e = ch.receive(b1);
                        InetSocketAddress emisor = (InetSocketAddress)e;
                        String saludo = new String(b1.array(),0,b1.limit());
                        System.out.println("Mensaje recibido desde: "+ emisor.getAddress()+":"+emisor.getPort()+" con el saludo: "+saludo);
                        k.interestOps(SelectionKey.OP_WRITE);
                        //continue;
                        k.cancel();
                        System.exit(0);
                    }//if
                }//while
                
            }//for
            //cl.close();
            
        }catch(Exception e){
            e.printStackTrace();
        }//catch
    }//main
}
