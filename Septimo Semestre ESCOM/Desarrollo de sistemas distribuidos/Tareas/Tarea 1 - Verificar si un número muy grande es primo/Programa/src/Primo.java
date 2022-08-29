import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;

public class Primo {
    static Object obj = new Object();
    static int isPrime = 0;
    static class Worker extends Thread{
        Socket conexion;
        Worker(Socket conexion){
            /**Desambiguamos y asignamos*/
            this.conexion = conexion;
        }

        public void run(){
            /**Código despues de aceptar la conexion*/
            try {
                DataOutputStream salida = new DataOutputStream(conexion.getOutputStream());
                DataInputStream entrada = new DataInputStream(conexion.getInputStream());
                System.out.println("Dentro hilo");

                synchronized (obj){
                    /**Leyendo números*/
                    long numero = entrada.readLong();
                    long numeroInicial = entrada.readLong();
                    long numeroFinal = entrada.readLong();

                    System.out.println("Intervalo: " + numeroInicial +  ", " + numeroFinal);


                    for(long i = numeroInicial; i < numeroFinal; i++){
                        if(numero % i == 0){
                            isPrime++;
                            salida.writeInt(isPrime);
                            System.out.println("No es primo");
                            break;
                        }
                    }
                }


                if(isPrime == 0){
                    salida.writeInt(isPrime);
                    System.out.println("Es primo");
                }

                entrada.close();
                salida.close();
                conexion.close();
            }
            catch (Exception ex){
                System.err.println(ex.getMessage());
            }
        }

        public static void read(DataInputStream f, byte[] b, int posicion, int longitud) throws Exception{
            while(longitud > 0){
                int n = f.read(b, posicion, longitud);
                posicion += n;
                longitud -= n;
            }
        }
    }

    public static void main(String[] args)throws Exception{
        if(args.length != 1){
            System.out.println("Debe ingresar un socket como argumento, ejemplo: java Primo 50000");
            System.exit(0);
        }
        int port = Integer.valueOf(args[0]);
        ServerSocket servidor = new ServerSocket(port);
        //for(int i=0; i < 4; i++){
            Socket conexion = servidor.accept();
            System.out.println("Conectamos");

            Worker w = new Worker(conexion);
            w.start();
            w.join();
        //}
    }
}
