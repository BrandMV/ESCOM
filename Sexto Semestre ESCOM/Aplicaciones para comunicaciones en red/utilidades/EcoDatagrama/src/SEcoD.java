import java.net.*;
import java.io.*;
/**
 *
 * @author axele
 */
public class SEcoD {
    public static void main(String[] args){
        try{
            int pto = 1234,max=65535;
            DatagramSocket s = new DatagramSocket(pto);
                    System.out.println("Servidor de datagrama iniciado en el puerto "+s.getLocalPort());
                    while(true){
                        DatagramPacket p = new DatagramPacket(new byte[max],max);
                        s.receive(p);
                        String msj = new String(p.getData(),0,p.getLength());
                        System.out.println("Datos recibidos: "+msj+ " Devolviendo eco..");
                        s.send(p);
                    }//while
        }catch(Exception e){
            e.printStackTrace();
        }//catch
    }//main
}//class
