import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.nio.channels.*;
import java.nio.*;
import java.net.*;
import java.util.Iterator;

/**
 *
 * @author axel
 */
public class EcoC {
     public static void main(String[] args){
       String host="127.0.0.1";
       int pto=9999;
       try{
           BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
           SocketChannel cl = SocketChannel.open();
           cl.configureBlocking(false);
           Selector sel = Selector.open();
           cl.connect(new InetSocketAddress(host,pto));
           cl.register(sel,SelectionKey.OP_CONNECT);
           
           while(true){
               sel.select();
               Iterator<SelectionKey>it =sel.selectedKeys().iterator();
               while(it.hasNext()){
                   SelectionKey k = (SelectionKey)it.next();
                   it.remove();
                   if(k.isConnectable()){
                       SocketChannel ch = (SocketChannel)k.channel();
                       if(ch.isConnectionPending()){
                           try{
                               ch.finishConnect();
                               System.out.println("Conexion establecida.. Escribe un mensaje <ENTER> para enviar \"SALIR\" para teminar");
                           }catch(Exception e){
                               e.printStackTrace();
                           }//catch
                       }//if_conectionpending
                       //ch.configureBlocking(false);
                       ch.register(sel, SelectionKey.OP_READ|SelectionKey.OP_WRITE);
                       continue;
                   }//if
                   if(k.isWritable()){
                       SocketChannel ch2 = (SocketChannel)k.channel();
                       String msj = br.readLine();
                       ByteBuffer b = ByteBuffer.wrap(msj.getBytes());
                       ch2.write(b);
                       if(msj.equalsIgnoreCase("SALIR")){
                           System.out.println("Termina aplicacion...");
                           ch2.close();
                           System.exit(0);
                       }else{
                       k.interestOps(SelectionKey.OP_READ);
                       continue;
                       }//else
                   } else if(k.isReadable()){
                       SocketChannel ch2 = (SocketChannel)k.channel();
                       ByteBuffer b = ByteBuffer.allocate(2000);
                       b.clear();
                       int n = ch2.read(b);
                       b.flip();
                       String eco = new String(b.array());
                       System.out.println("Eco recibido: "+eco);
                       k.interestOps(SelectionKey.OP_WRITE);
                       continue;
                   }//if
               }//while
           }//while
       }catch(Exception e){
           e.printStackTrace();
       } 
    }//main
}
