import java.io.*;
import java.net.*;
/**
 *
 * @author axele
 */
public class SDO {
    public static void main(String[] args){
        try{
           DatagramSocket s = new DatagramSocket(8888);
           s.setReuseAddress(true);
            System.out.println("Servidor iniciado, esperando objeto..");
            while(true){
                DatagramPacket p = new DatagramPacket(new byte[65535],65535);
                s.receive(p);
                ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(p.getData()));
                Objeto o = (Objeto)ois.readObject();
                System.out.println("Objeto recibido con los datos:\nX:"+o.getX()+" Y:"+o.getY()+" Z:"+o.getZ());
                
                Objeto o1 = new Objeto(8,9.0f,"Diez");
                ByteArrayOutputStream baos= new ByteArrayOutputStream();
                ObjectOutputStream oos = new ObjectOutputStream(baos);
                oos.writeObject(o1);
                oos.flush();
                byte[] b = baos.toByteArray();
                DatagramPacket p1 = new DatagramPacket(b,b.length,p.getAddress(),p.getPort());
                s.send(p1);
                System.out.println("Objeto enviado con los datos:\nX:"+o1.getX()+" Y:"+o1.getY()+" Z:"+o1.getZ());
                
            }//while
        }catch(Exception e){
            e.printStackTrace();
        }//catch
    }//main
}
