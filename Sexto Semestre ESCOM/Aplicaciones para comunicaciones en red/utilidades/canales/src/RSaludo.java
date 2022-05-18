
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
public class RSaludo {
    public static void main(String[] args){
        try{
            InetSocketAddress dst = new InetSocketAddress(1234);
            DatagramChannel s = DatagramChannel.open();
            s.setOption(StandardSocketOptions.SO_REUSEADDR, true);
            s.configureBlocking(false);
            s.bind(dst);
            System.out.println("Servidor iniciado.. esperando mensaje de cliente..");
            Selector sel = Selector.open();
            //BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            s.register(sel,SelectionKey.OP_READ);
            for(;;){
                sel.select();
                Iterator <SelectionKey> it = sel.selectedKeys().iterator();
                while(it.hasNext()){
                    SelectionKey k = (SelectionKey)it.next();
                    it.remove();
                    if(k.isReadable()){
                        DatagramChannel ch = (DatagramChannel)k.channel();
                        ByteBuffer b = ByteBuffer.allocate(2000);
                        b.clear();
                        SocketAddress e = ch.receive(b);
                        InetSocketAddress emisor = (InetSocketAddress)e;
                        String saludo = new String(b.array(),0,b.limit());
                        System.out.println("Mensaje recibido desde: "+ emisor.getAddress()+":"+emisor.getPort()+" con el saludo: "+saludo);
                        saludo = "hola " + saludo;
                        ByteBuffer b1 = ByteBuffer.wrap(saludo.getBytes());
                        ch.send(b1, e);
                        //k.interestOps(SelectionKey.OP_WRITE);
                        continue;
                    }
                }
            }//for
        }catch(Exception e){
            e.printStackTrace();
        }//catch
    }//main
}
