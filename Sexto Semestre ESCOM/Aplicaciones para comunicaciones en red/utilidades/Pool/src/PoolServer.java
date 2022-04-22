import java.net.*;
import java.io.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

class Manejador implements Runnable{
    protected Socket cl = null;

    public Manejador(Socket cl) {
        this.cl = cl;
    }

    public void run() {
        try {
            PrintWriter pw = new PrintWriter(new OutputStreamWriter(cl.getOutputStream()));
            BufferedReader br = new BufferedReader(new InputStreamReader(cl.getInputStream()));
            while(true){
                String linea = br.readLine();
                if(linea.compareToIgnoreCase("salir")==0){
                    br.close();
                    pw.close();
                    cl.close();
                    break;
                }else{
                    System.out.println("Rensaje recibido de:"+cl.getInetAddress()+":"+cl.getPort()+"\ncon el mensaje:"+linea+"\n\n");                  
                    pw.println(linea);
                    pw.flush();
                }//else
            }//while

            System.out.println("Solicitud procesada: ");
        } catch (IOException e) {
            //report exception somewhere.
            e.printStackTrace();
        }
    }
}

public class PoolServer implements Runnable{
    protected int          puerto   = 9000;
    protected ServerSocket s = null;
    protected boolean      detenido    = false;
    protected Thread       runningThread= null;
    protected ExecutorService pool = Executors.newFixedThreadPool(3);

    public PoolServer(int puerto){
        this.puerto = puerto;
    }

    public void run(){
        synchronized(this){
            this.runningThread = Thread.currentThread();
        }
        iniciaServidor();
        while(! detenido()){
            Socket cl = null;
            try {
                cl = this.s.accept();
                System.out.println("Conexion aceptada..");
            } catch (IOException e) {
                if(detenido()) {
                    System.out.println("Servidor detenido.") ;
                    break;
                }throw new RuntimeException("Error al aceptar nueva conexion", e);
            }//catch
            this.pool.execute(new Manejador(cl));
        }//while
        this.pool.shutdown();
        System.out.println("Servidor detenido.") ;
    }


    private synchronized boolean detenido() {
        return this.detenido;
    }

    public synchronized void stop(){
        this.detenido = true;
        try {
            this.s.close();
        } catch (IOException e) {
            throw new RuntimeException("Error al cerrar el socket del servidor", e);
        }
    }

    private void iniciaServidor() {
        try {
            this.s = new ServerSocket(this.puerto);
            System.out.println("Servicio iniciado.. esperando cliente..");
        } catch (IOException e) {
            throw new RuntimeException("No puede iniciar el socket en el puerto: "+s.getLocalPort(), e);
        }
    }

public static void main(String[] args){
    PoolServer server = new PoolServer(9000);
new Thread(server).start();
}//main    
}//class
