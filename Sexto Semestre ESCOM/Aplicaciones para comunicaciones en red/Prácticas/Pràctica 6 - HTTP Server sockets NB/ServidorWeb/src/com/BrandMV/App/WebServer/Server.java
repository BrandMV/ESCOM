package com.BrandMV.App.WebServer;

import com.BrandMV.App.Constants.Constants;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.StandardSocketOptions;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;


/**
 * @author BrandMV
 * Server connection using non blocking sockets
 */
public class Server{
    protected int port;
    protected ServerSocketChannel s;

    public Server(int port){
        this.port = port;
    }

    /**
     * Method that initialize the server using non blocking sockets
     */
    private void initServer(){
        try {
            Selector selector = Selector.open();
            s = ServerSocketChannel.open();
            s.configureBlocking(false);
            s.setOption(StandardSocketOptions.SO_REUSEADDR, true);
            s.socket().bind(new InetSocketAddress(port));
            s.register(selector, SelectionKey.OP_ACCEPT);
            System.out.println(Constants.SERVER_CONNECTION_START);
            while(true){
                selector.select();
                Iterator<SelectionKey> it = selector.selectedKeys().iterator();
                while(it.hasNext()){
                    SelectionKey k = (SelectionKey) it.next();
                    it.remove();
                    if(k.isAcceptable()){
                        SocketChannel cl = s.accept();
                        System.out.println(String.format(Constants.CONNECTED_CLIENT_MESSAGE, cl.socket().getInetAddress().getHostAddress(), cl.socket().getPort()));
                        cl.configureBlocking(false);
                        cl.register(selector, SelectionKey.OP_READ);
                        continue;
                    }
                    if(k.isReadable()){
                        SocketChannel ch = (SocketChannel) k.channel();
                        HTTPServer httpServer = new HTTPServer(ch);
                        httpServer.connection();
                    }
                }
            }
        }catch (IOException e){
            throw new RuntimeException(String.format(Constants.SERVER_CONNECTION_ERROR, s.socket().getLocalPort()), e);
        }
    }

    public static void main(String[] args) {
        Server server = new Server(Constants.PORT);
        server.initServer();
    }
}
