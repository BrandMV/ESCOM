import java.net.*;
import java.io.*;
/**
 *
 * @author axele
 */
public class CEcoD {
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
                        DatagramPacket p = new DatagramPacket(b2,n,dir,pto);
                        cl.send(p);
                        DatagramPacket peco = new DatagramPacket(new byte[tp],tp);
                        cl.receive(peco);
                        String eco = new String(peco.getData(),0,peco.getLength());
                        System.out.println("eco: "+eco);
                    }//for
                } else{
                        DatagramPacket p = new DatagramPacket(b,b.length,dir,pto);
                        cl.send(p);
                        DatagramPacket peco = new DatagramPacket(new byte[max],max);
                        cl.receive(peco);
                        String eco = new String(peco.getData(),0,peco.getLength());
                        System.out.println("eco: "+eco);
                }//else
            }//while
        }catch(Exception e){
            e.printStackTrace();
        }
    }//main
}//class
