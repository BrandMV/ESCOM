import java.io.IOException;
import java.net.*;
import java.nio.ByteBuffer;

public class ClienteMulticast {

    static byte[] recibe_mensaje(MulticastSocket socket, int longitud_mensaje) throws IOException{
        byte[] buffer = new byte[longitud_mensaje];
        /**Creamos paquete vacio*/
        DatagramPacket paquete = new DatagramPacket(buffer, buffer.length);
        socket.receive(paquete);

        return paquete.getData();
    }

    public static void main(String[] args) throws IOException {
        System.setProperty("java.net.preferIPv4Stack", "true");
        // Grupo al que se suscribe el cliente
        InetSocketAddress grupo = new InetSocketAddress(InetAddress.getByName("239.0.0.0"), 50000);
        MulticastSocket socket = new MulticastSocket(50000);

        NetworkInterface netInter = NetworkInterface.getByName("em1");
        // se crea el grupo en cuanto se une el primero
        socket.joinGroup(grupo, netInter);

        byte[] a = recibe_mensaje(socket, 4);
        System.out.println(new String(a, "UTF-8"));

        byte[] buffer = recibe_mensaje(socket, 5*8);
        ByteBuffer b = ByteBuffer.wrap(buffer);

        for(int i = 0; i < 5;i++) System.out.println(b.getDouble());
        //abandonamos el grupo
        socket.leaveGroup(grupo, netInter);
        socket.close();
    }
}
