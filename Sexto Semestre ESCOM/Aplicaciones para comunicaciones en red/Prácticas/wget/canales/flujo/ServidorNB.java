import java.nio.channels.*;
import java.io.*;
import java.net.*;
import java.nio.ByteBuffer;
import java.util.Iterator;
/**
 *
 * @author Axel
 */
public class ServidorNB {
    public static void main(String[] args){
        try{
            String EECO="";
            int pto=9999;
            ServerSocketChannel s = ServerSocketChannel.open();
            s.configureBlocking(false);
            s.socket().bind(new InetSocketAddress(pto));
            System.out.println("Esperando clientes...");
            Selector sel = Selector.open();
            s.register(sel, SelectionKey.OP_ACCEPT);
            while(true){
                sel.select();
                Iterator<SelectionKey>it = sel.selectedKeys().iterator();
                while(it.hasNext()){
                    SelectionKey k = (SelectionKey)it.next();
                    it.remove();
                    if(k.isAcceptable()){
                        SocketChannel cl = s.accept();
                        System.out.println("Cliente conectado desde "+cl.socket().getInetAddress()+":"+cl.socket().getPort());
                        cl.configureBlocking(false);
                        cl.register(sel,SelectionKey.OP_READ|SelectionKey.OP_WRITE);
                        continue;
                    }//if
                    if(k.isReadable()){
                        try{
                        SocketChannel ch = (SocketChannel)k.channel();
                        ByteBuffer b = ByteBuffer.allocate(2000);
                        b.clear();
                        int n=0; 
                        String msj="";
                        n=ch.read(b);
                            b.flip();
                            if(n>0)
                               msj = new String(b.array(),0,n);
                            System.out.println("Mensaje  de "+n+" bytes recibido: "+msj);
                            if (msj.equalsIgnoreCase("SALIR")){
                                k.interestOps(SelectionKey.OP_WRITE);
                                ch.close();
                                continue;
                               // k.cancel();
                            }else{
                            EECO="ECO->"+msj;
                            k.interestOps(SelectionKey.OP_WRITE);
                            }//else

                        }catch(IOException io){}
                        continue;
                    }else if(k.isWritable()){
                           try{
                           SocketChannel ch = (SocketChannel)k.channel();
                           ByteBuffer bb = ByteBuffer.wrap(EECO.getBytes());
                           ch.write(bb);
                           System.out.println("Mensaje  de "+EECO.length()+" bytes enviado: "+EECO);
                           EECO="";
                           }catch(IOException io){}
                            k.interestOps(SelectionKey.OP_READ);
                           continue;
                    }//if
                }//while
                
            }//while
        }catch(Exception e){
            e.printStackTrace();
        }//catch
              
        
    }//main
}
