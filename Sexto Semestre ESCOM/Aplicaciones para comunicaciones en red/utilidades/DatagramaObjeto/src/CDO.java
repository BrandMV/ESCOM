import java.io.*;
import java.net.*;
/**
 *
 * @author axele
 */
public class CDO {
   public static void main(String[] args){
       try{
            String host="127.0.0.1";
            int pto=8888;
            InetAddress dst = InetAddress.getByName(host);
            DatagramSocket cl = new DatagramSocket();
            System.out.println("Cliente iniciado, generando objeto a ser enviado a "+host+":"+pto);
            Objeto o = new Objeto(20,30.0f,"Cuarenta");
            ByteArrayOutputStream baos= new ByteArrayOutputStream();
            ObjectOutputStream oos = new ObjectOutputStream(baos);
            oos.writeObject(o);
            oos.flush();
            byte[] b = baos.toByteArray();
            DatagramPacket p = new DatagramPacket(b,b.length,dst,pto);
            cl.send(p);
            System.out.println("Objeto enviado con los datos:\nX:"+o.getX()+" Y:"+o.getY()+" Z:"+o.getZ());
            System.out.println("Esperando recibir objeto..");
            DatagramPacket p1 = new DatagramPacket(new byte[65535],65535);
            cl.receive(p1);
            ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(p1.getData()));
            Objeto o1 = (Objeto)ois.readObject();
            System.out.println("Objeto recibido con los datos:\nX:"+o1.getX()+" Y:"+o1.getY()+" Z:"+o1.getZ());
            cl.close();
        }catch(Exception e){
            e.printStackTrace();
        }//catch 
    }//main 
}
