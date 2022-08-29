package server;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;

public class ServidorHTTP {
    static class Worker extends Thread{
        Socket conexion;
        Worker(Socket conexion){
            this.conexion = conexion;
        }
        public void run(){
            //System.out.println((InetSocketAddress)conexion.g);
            try {
                BufferedReader entrada = new BufferedReader(new InputStreamReader(conexion.getInputStream()));
                /**Con printwriter tiene los metodos para salto de linea*/
                PrintWriter salida = new PrintWriter(conexion.getOutputStream());
               // StringBuffer sb = new StringBuffer();

                String s = entrada.readLine();
                System.out.println(s);

                if(s.startsWith("GET /primo?numero")){
                    String respuesta = "<html><button onclick='alert(\"OK\")'>Boton</button></html>";

                    salida.println("HTTP/1.1 200 OK");
                    salida.println("Server: ServidorWeb.java");
                    salida.println("Date: " + new Date());
                    salida.println("Content-type: text/html; charset=utf-8");
                    salida.println("Content-length: " + respuesta.length());
                    salida.println();
                    salida.flush();//Garantizamos que el encabezado va
                    salida.println(respuesta);
                    salida.flush();
                }else{
                    salida.println("HTTP/1.1 404 File Not Found");
                    salida.println("Server: ServidorWeb.java");
                    salida.println("Date: " + new Date());
                    salida.println("Content-type: text/html; charset=utf-8");
                    salida.println("Content-length: 0");
                    salida.println();
                    salida.flush();
                }
            }catch (Exception ex){
                System.err.println(ex.getMessage());
            }
        }
    }

    public static void main(String[] args) throws Exception{
        ServerSocket servidor = new ServerSocket(8081);
        for(;;){
            Socket conexion = servidor.accept();
            new Worker(conexion).start();
        }
    }
}
