
import java.io.DataOutputStream;
import java.io.ObjectOutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.net.ServerSocket; //*Para sockets
import java.net.Socket;

//*Los flujos nos permiten transportar datos de cualquier lugar a cualquier lugar
public class SHMF {
    public static void main(String [] args){
        try{
            ServerSocket s = new ServerSocket(1234);
            System.out.println("Starting server from port: " + s.getLocalPort());
            
            //*Ciclo infinito para esperar a alguien
            for(;;){
                Socket cl = s.accept(); //*Aceptamos la conexión
                System.out.println("Client connected from " + cl.getInetAddress() + ":" + cl.getPort()); //*InetAddress devuelve dirección, getPort devuelve puerto
                
                //*OutputSreamWriter escribir un caracter a la vez con PrintWriter podemos escribir bloqes de texto
                //PrintWriter pw = new PrintWriter(new OutputStreamWriter(cl.getOutputStream()));
                //*Para mandar cualquier dato primitivo
                //DataOutputStream dos = new DataOutputStream(cl.getOutputStream());
                //*Para un objeto el objeto debe ser serializable
                ObjectOutputStream oos = new ObjectOutputStream(cl.getOutputStream());
                oos.writeFloat(3.7f);
                oos.flush();
                oos.close();
                //dos.writeFloat(3.7f);
                //dos.flush();
                //dos.close();
                //pw.println("Un mensaje desde el servidor...");
                //pw.flush();
                //pw.close();
                cl.close();
            }
            //*accept():

        }catch(Exception e){
            System.out.println(e);
        }
    }//*Main
}
