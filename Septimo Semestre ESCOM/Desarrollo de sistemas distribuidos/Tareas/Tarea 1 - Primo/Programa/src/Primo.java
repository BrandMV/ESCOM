import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.charset.StandardCharsets;

public class Primo {
    static Object obj = new Object();
    static int isPrime = 0;

    static class Worker extends Thread {
        Socket conexion;

        Worker(Socket conexion) {
            /**Desambiguamos y asignamos*/
            this.conexion = conexion;
        }

        public void run() {
            /**Código despues de aceptar la conexion*/
            try {
                DataOutputStream salida = new DataOutputStream(conexion.getOutputStream());
                DataInputStream entrada = new DataInputStream(conexion.getInputStream());
                System.out.println("Dentro hilo");
                String verificacion = null;
                /**Leyendo números*/
                long numero = entrada.readLong();
                long numeroInicial = entrada.readLong();
                long numeroFinal = entrada.readLong();
               // System.out.println("Intervalo: " + numeroInicial + ", " + numeroFinal + ", numero: " + numero);

                // Se sincroniza el proceso que modifica la variable verificacion la cual indica al servidor b si se encontro un numero que divide
                synchronized (obj) {
                    for (long i = numeroInicial; i <= numeroFinal; i++) {
                        if (numero % i == 0) {
                            System.out.println("la i: " + i);
                            isPrime++;
                            verificacion = "DIVIDE";
                            salida.writeInt(verificacion.length());
                            salida.write(verificacion.getBytes(StandardCharsets.UTF_8));
                            System.out.println("DIVIDE");
                            break;
                        }
                    }
                    if (isPrime == 0) {
                        verificacion = "NO DIVIDE";
                        salida.writeInt(verificacion.length());
                        salida.write(verificacion.getBytes(StandardCharsets.UTF_8));
                        System.out.println("NO DIVIDE");
                    }
                }
                entrada.close();
                salida.close();
                conexion.close();
            } catch (Exception ex) {
                System.err.println(ex.getMessage());
            }
        }
    }

    public static void main(String[] args) throws Exception {
        if (args.length != 1) {
            System.out.println("Debe ingresar un socket como argumento, ejemplo: java Primo 50000");
            System.exit(0);
        }
        int port = Integer.valueOf(args[0]);
        ServerSocket servidor = new ServerSocket(port);
        Socket conexion = servidor.accept();
        Worker w = new Worker(conexion);
        w.start();
        // Esperamos por la finalizacion del hilo
        w.join();
    }
}
