import java.io.IOException;
import java.net.*;
import java.util.Scanner;

public class Chat {
    public static final String GRUPO = "239.10.10.10";
    public static final int TAMMSG = 100;
    public static final int PUERTO = 10000;
    static class Worker extends Thread{
        public void run(){
            for(;;){
                try{
                    /**Uniendonos al grupo*/
                    SocketAddress socketAddress;
                    InetAddress grupoChat = InetAddress.getByName(GRUPO);
                    MulticastSocket socket = new MulticastSocket(PUERTO);
                    NetworkInterface ni = NetworkInterface.getByIndex(0);
                    socketAddress = new InetSocketAddress(grupoChat, PUERTO);
                    socket.joinGroup(socketAddress, ni);
                    /**Recibiendo mensajes*/
                    byte[] buffer = recibe_mensaje_multicast(socket, TAMMSG);
                    /**Codificación para visualizar acentos y caracteres en la ventanaa de windows*/
                    String mensaje = new String(buffer, "Windows-1252");
                    System.out.println(mensaje);
                    System.out.println("Escribe tu mensaje para el chat: ");
                    socket.leaveGroup(socketAddress, ni);
                    socket.close();
                }catch (IOException e){
                    System.err.println(e.getMessage());
                }
            }
        }
    }

    public static void main(String[] args) throws IOException{
        new Worker().start();

        String nombre = args[0];
        Scanner scan = new Scanner(System.in);
        System.out.println("Escribe tu mensaje para el chat: ");
        /**Leyendo mensajes*/
        for(;;){
            String mensaje = scan.nextLine();
            byte buffer[] = String.format("%s:-%s", nombre, mensaje).getBytes();
            envia_mensaje_multicast(buffer, GRUPO, PUERTO);
        }
    }

    /**
     * @brief Método que recibe mensajes multicast
     * @param socket           El socket
     * @param longitud_mensaje La longitud del mensaje
     * @return
     * @throws IOException
     */
    static byte[] recibe_mensaje_multicast(MulticastSocket socket, int longitud_mensaje) throws IOException{
        byte[] buffer = new byte[longitud_mensaje];
        DatagramPacket paquete = new DatagramPacket(buffer, buffer.length);
        socket.receive(paquete);
        return paquete.getData();
    }

    /**
     * @brief Método que envia mensajes por medio de un socket multicast
     * @param buffer El mensaje a enviar
     * @param ip     La ip del socket
     * @param puerto El puerto del socket
     * @throws IOException
     */
    static void envia_mensaje_multicast(byte[] buffer, String ip, int puerto) throws IOException{
        DatagramSocket socket = new DatagramSocket();
        socket.send(new DatagramPacket(buffer, buffer.length, InetAddress.getByName(ip), puerto));
        socket.close();
    }
}
