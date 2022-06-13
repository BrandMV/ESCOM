
import constants.Constants;

import java.io.IOException;
import java.net.DatagramPacket;
import java.net.Inet4Address;
import java.net.InetAddress;
import java.net.MulticastSocket;

/**
 * Class that will create a thread, announcing every 5 seconds the stream server port
 */
public class MulticastServer extends Thread{
    private InetAddress group = null;

    public void run(){
        try {
            group = InetAddress.getByName(Constants.MULTICAST_ADDRESS);
            while (true){
                send("MulticastServer");
                try {
                    Thread.sleep(5000);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }
            }
        }catch (IOException e){
            e.printStackTrace();
            System.exit(2);
        }
    }

    public Boolean send(String message){
        try {
            MulticastSocket sendSocket = new MulticastSocket(Constants.MULTICAST_PORT);
            sendSocket.joinGroup(group);
            DatagramPacket packet = new DatagramPacket(message.getBytes(), message.length(), group, Constants.MULTICAST_PORT);
            sendSocket.send(packet);
            sendSocket.close();
            return true;
        }catch (IOException e){
            e.printStackTrace();
            return false;
        }
    }

    public static void main(String[] args) {
        try {
            MulticastServer multicastServer = new MulticastServer();
            multicastServer.start();
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
