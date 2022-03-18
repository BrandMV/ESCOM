import java.net.*;
import java.io.*;
/**
 *
 * @author axele
 */
public class SEcoD2 {
    public static void main(String[] args){
        try{
            int pto = 1234,max=65535;
            DatagramSocket s = new DatagramSocket(pto);
                    System.out.println("Servidor de datagrama iniciado en el puerto "+s.getLocalPort());
                    while(true){
                        DatagramPacket p = new DatagramPacket(new byte[max],max);
                        s.receive(p);
                        ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(p.getData()));
                        Datos dd = (Datos)ois.readObject();
                        String msj = new String(dd.getdatos(),0,dd.getdatos().length);
                        //String msj = new String(p.getData(),0,p.getLength());
                        System.out.println("Segmento:"+dd.getnp()+"  Datos recibidos: "+msj+ " Devolviendo eco..");
                        s.send(p);
                    }//while
        }catch(Exception e){
            e.printStackTrace();
        }//catch
    }//main
}//class
