import java.net.*;
import java.io.*;

/**
 *
 * @author axele
 */
public class SRecibe {
    public static void main(String[] args){
      try{
          int pto = 8000;
          ServerSocket s = new ServerSocket(pto);
          s.setReuseAddress(true);
          System.out.println("Servidor iniciado esperando por archivos..");
          File f = new File("");
          String ruta = f.getAbsolutePath();
          String carpeta="archivos";
          String ruta_archivos = ruta+"\\"+carpeta+"\\";
          System.out.println("ruta:"+ruta_archivos);
          File f2 = new File(ruta_archivos);
          f2.mkdirs();
          f2.setWritable(true);
          for(;;){
              Socket cl = s.accept();
              System.out.println("Cliente conectado desde "+cl.getInetAddress()+":"+cl.getPort());
              DataInputStream dis = new DataInputStream(cl.getInputStream());
              String nombre = dis.readUTF();
              long tam = dis.readLong();
              System.out.println("Comienza descarga del archivo "+nombre+" de "+tam+" bytes\n\n");
              DataOutputStream dos = new DataOutputStream(new FileOutputStream(ruta_archivos+nombre));
              long recibidos=0;
              int l=0, porcentaje=0;
              while(recibidos<tam){
                  byte[] b = new byte[1500];
                  l = dis.read(b);
                  System.out.println("leidos: "+l);
                  dos.write(b,0,l);
                  dos.flush();
                  recibidos = recibidos + l;
                  porcentaje = (int)((recibidos*100)/tam);
                  System.out.print("\rRecibido el "+ porcentaje +" % del archivo");
              }//while
              System.out.println("Archivo recibido..");
              dos.close();
              dis.close();
              cl.close();
          }//for
          
      }catch(Exception e){
          e.printStackTrace();
      }  
    }//main
}
