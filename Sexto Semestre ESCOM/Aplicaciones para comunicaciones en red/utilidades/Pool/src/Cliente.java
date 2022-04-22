import java.net.*;
import java.io.*;
/**
 *
 * @author axel
 */
public class Cliente {
    public static void main(String[] args){
        try{
            int pto=9000;
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            Socket cl = new Socket("127.0.0.1",pto);
            System.out.println("Conexion establecida..");
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(cl.getOutputStream()));
            BufferedReader br1 = new BufferedReader(new InputStreamReader(cl.getInputStream()));
            while(true){
                System.out.println("Escribe un mensaje <enter> para enviar \"salir\" para terminar");
                System.out.print("#");
                String msj = br.readLine();
                pw.println(msj);
                pw.flush();
                if(msj.compareToIgnoreCase("salir")==0){
                    System.out.println("Termina aplicacion..");
                    br.close();
                    br1.close();
                    pw.close();
                    cl.close();
                    System.exit(0);
                }else{
                String eco = br1.readLine();
                System.out.println("eco recibido:"+eco);
                }//else
            }//while
        }catch(Exception e){
            e.printStackTrace();
        }//catch
    }//main
}
