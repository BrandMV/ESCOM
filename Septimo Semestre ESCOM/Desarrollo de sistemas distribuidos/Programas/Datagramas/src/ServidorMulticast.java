import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.nio.ByteBuffer;

public class ServidorMulticast {

    static void envia_mensaje(byte[] buffer, String ip, int puerto) throws IOException{

        DatagramSocket socket = new DatagramSocket();
        /**Representacion interna de la ip*/
        InetAddress grupo = InetAddress.getByName(ip);
        /**Creamos el paquete*/
        DatagramPacket paquete = new DatagramPacket(buffer, buffer.length, grupo, puerto);

        socket.send(paquete);
        socket.close();
    }

    public static void main(String[] args) throws IOException{
        /**Establecemos que prefiera ipv4*/
        System.setProperty("java.net.preferIPv4Stack", "true");

        /** Enviamos una string */
        envia_mensaje("hola".getBytes(), "239.0.0.0", 50000);

        ByteBuffer b = ByteBuffer.allocate(5*8);
        b.putDouble(1.1);
        b.putDouble(1.2);
        b.putDouble(1.3);
        b.putDouble(1.4);
        b.putDouble(1.5);

        envia_mensaje(b.array(), "239.0.0.0", 50000);
    }
}
