import java.net.*;
import java.io.*;
/**
 *
 * @author axele
 */
public class CEcoD2 {
    public static void main(String[] args){
        try{
            int pto=1234,max=10,tp=5;
            InetAddress dir = InetAddress.getByName("127.0.0.1");
            DatagramSocket cl = new DatagramSocket();
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("Cliente iniciado en el puerto "+cl.getLocalPort());
            while(true){
                System.out.println("Escribe un mensaje, <Enter> para enviar, \"salir\" para terminar.");
                String msj= br.readLine();
                byte[] b = msj.getBytes();
                if(msj.compareToIgnoreCase("salir")==0){
                    System.out.println("Usuario escribio SALIR\termina aplicacion..");
                    br.close();
                    cl.close();
                    System.exit(0);
                } else if(b.length>max){
                    ByteArrayInputStream bais = new ByteArrayInputStream(b);
                    int np = (int)b.length/tp;
                    if(b.length%tp>0)
                        np = np+1;
                    for(int i=0;i<np;i++){
                        byte[] b2 = new byte[tp];
                        int n = bais.read(b2);
                        Datos d = new Datos(i,b2);
                        ByteArrayOutputStream baos = new ByteArrayOutputStream();
                        ObjectOutputStream oos = new ObjectOutputStream(baos);
                        oos.writeObject(d);
                        oos.flush();
                        byte[]tmp = baos.toByteArray();
                        System.out.println("tam paquete: "+tmp.length);
                        //DatagramPacket p = new DatagramPacket(b2,n,dir,pto);
                        DatagramPacket p = new DatagramPacket(tmp,tmp.length,dir,pto);
                        cl.send(p);
                        DatagramPacket peco = new DatagramPacket(new byte[tmp.length],tmp.length);
                        cl.receive(peco);
                        ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(peco.getData()));
                        Datos dd = (Datos)ois.readObject();
                        String eco = new String(dd.getdatos(),0,dd.getdatos().length);
                        //String eco = new String(peco.getData(),0,peco.getLength());
                        System.out.println("eco: "+eco);
                        ois.close();
                        oos.close();
                        baos.close();
                    }//for
                } else{
                        Datos d = new Datos(0,b);
                        ByteArrayOutputStream baos = new ByteArrayOutputStream();
                        ObjectOutputStream oos = new ObjectOutputStream(baos);
                        oos.writeObject(d);
                        oos.flush();
                        byte[]tmp = baos.toByteArray();
                        //DatagramPacket p = new DatagramPacket(b2,n,dir,pto);
                        DatagramPacket p = new DatagramPacket(tmp,tmp.length,dir,pto);
                        cl.send(p);
                        DatagramPacket peco = new DatagramPacket(new byte[tmp.length],tmp.length);
                        cl.receive(peco);
                        ObjectInputStream ois = new ObjectInputStream(new ByteArrayInputStream(peco.getData()));
                        Datos dd = (Datos)ois.readObject();
                        String eco = new String(dd.getdatos(),0,dd.getdatos().length);
                        //String eco = new String(peco.getData(),0,peco.getLength());
                        System.out.println("eco: "+eco);
                        ois.close();
                        oos.close();
                        baos.close();

//                        DatagramPacket p = new DatagramPacket(b,b.length,dir,pto);
//                        cl.send(p);
//                        DatagramPacket peco = new DatagramPacket(new byte[max],max);
//                        cl.receive(peco);
//                        String eco = new String(peco.getData(),0,peco.getLength());
//                        System.out.println("eco: "+eco);
                }//else
            }//while
        }catch(Exception e){
            e.printStackTrace();
        }
    }//main
}//class
