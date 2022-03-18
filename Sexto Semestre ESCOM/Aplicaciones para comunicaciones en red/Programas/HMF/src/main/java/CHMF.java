
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.InputStreamReader;
import java.io.ObjectInputStream;
import java.net.Socket;


public class CHMF {
    public static void main(String[] args) {
        try{
            Socket cl = new Socket("localhost", 1234); //*Conectamos al servidor
            System.out.println("Conexion establecida, recibiendo mensaje desde el servidor");
            //BufferedReader br = new BufferedReader(new InputStreamReader(cl.getInputStream()));
            //DataInputStream dis = new DataInputStream(cl.getInputStream());
            ObjectInputStream ois = new ObjectInputStream(cl.getInputStream());
            Dato d = (Dato)ois.readObject();
            //String mensaje = br.readLine(); //*Leer una cantidad n de lineas hasta un slto de linea o la maxima cantidad de caracteres a leer
            //int v = dis.readInt();
            System.out.println("Mensaje del servidor: " + v);
            //br.close(); //*Cerrar porque son bloqueantes
            //dis.close();
            ois.close();
            cl.close();
        }catch(Exception e){
            System.out.println("Excepetio " + e);    
        }
    } //*MAIN   
}
