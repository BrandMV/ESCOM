/*
 * Writer
 */


import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.InetSocketAddress;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;

public class Sender_O {
    public static void main(String[] args) throws IOException {
        System.out.println("Sender Start");

        ServerSocketChannel ssChannel = ServerSocketChannel.open();
        ssChannel.configureBlocking(true);
        int port = 12345;
        ssChannel.socket().bind(new InetSocketAddress(port));

        String obj ="testtext";
        while (true) {
                SocketChannel sChannel = ssChannel.accept();

                ObjectOutputStream  oos = new 
                      ObjectOutputStream(sChannel.socket().getOutputStream());
                oos.writeObject(obj);
                oos.close();

                System.out.println("Connection ended");
        }
    }
}
