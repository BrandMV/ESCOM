import java.io.FileOutputStream;
import java.net.InetSocketAddress;
import java.net.StandardSocketOptions;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
 
 
public class Receiver {
 
	

	public static void main(String[] args) {
		
		String outputFile = "C:\\Users\\52552\\Documents\\NetBeansProjects\\canales\\duke1_c.png", host = "127.0.0.1";		
		int port = 8001, bufferSize = 10240;
		
		try {
			ByteBuffer buffer = ByteBuffer.allocate(bufferSize);
			Selector selector = Selector.open();
			ServerSocketChannel server = ServerSocketChannel.open();
			server.configureBlocking(false);
                        server.setOption(StandardSocketOptions.SO_REUSEADDR, true);
			server.socket().bind(new InetSocketAddress(host,port));
			server.register(selector, SelectionKey.OP_ACCEPT);
			
			System.out.println("Servidor iniciado..."); 
			while(true) 
			{
				int x = selector.select(); //if(selector.select()>0)
                                if(x==0)
                                    continue;
				Iterator<SelectionKey> iterator = selector.selectedKeys().iterator();
				while (iterator.hasNext()) {
		
					SelectionKey key = (SelectionKey) iterator.next();
					iterator.remove();
														
					if (key.isAcceptable()) {						
						SocketChannel client = server.accept();
						client.configureBlocking(false);
						client.register(selector, SelectionKey.OP_READ);						
						continue;
					}					
 
					SocketChannel channel = (SocketChannel) key.channel();
					int counter = 1; 
					if ( key.isReadable() ) {
						FileOutputStream os = new FileOutputStream(outputFile);
                                                FileChannel destination = os.getChannel();
						int res; 
						                                                
							while((res = channel.read(buffer)) != -1){ //EOF
							counter += res; 
							System.out.println("Leyendo bloque de "+res+" Bytes");
							buffer.flip();
                                                        //while(buffer.hasRemaining()){
                                                        destination.write(buffer);
                                                       // }//while
                                                        buffer.clear();
                                                        }//while
	
						
                                                destination.close();
						os.close();	
                                                channel.close();
						System.out.println("Recibidos: " + counter+ " Bytes");
                                                //System.exit(0);
						//return;
					}
				}			
			}
		} catch (Exception e) {
			e.printStackTrace();
		}				
	}
}
