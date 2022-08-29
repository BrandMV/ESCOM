import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;
import java.util.StringTokenizer;

public class ServidorHttp {
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
                //System.out.println(s);

                if(s.startsWith("GET /primo?")){

                    long numero = Long.parseLong(getNumero(s));

                    /**Obteniendo los intervalos para mandar al Servidor A*/
                    long numeroInicial = 2;
                    long numeroFinal = 0;

                    int port = 50000;
                    int conexiones = 0;
                    Socket conexion[] = new Socket[4];

                    /**Nos conectamos a las 4 instancias del servidor A con un puerto diferente*/
                    for(;;){
                        try{
                            System.out.println("Antes de crear socket");
                            conexion[conexiones] = new Socket("Localhost", port);
                            System.out.println("Despues de creear hilo");
                            port++;
                            conexiones++;

                            System.out.println("Conexiones" + conexiones);
                            if(conexiones == 4){
                                break;
                            }

                        }catch (Exception e){
                            Thread.sleep(200);
                            System.err.println(e.getMessage());
                        }
                    }

                    /**Mandamos intervalos para que las instancias del servidor A hagan sus operaciones*/
                    for(int i = 0; i < 4; i++){
                        System.out.println("Mandando intervalos");
                        DataOutputStream salidaSocket = new DataOutputStream(conexion[i].getOutputStream());
                        DataInputStream entradaSocket = new DataInputStream(conexion[i].getInputStream());

                        if(i != 0){
                            numeroInicial = numeroFinal + 1;
                        }
                        numeroFinal = (numero / 4) * (i + 1);
                        System.out.println("Numero final en intervalo " + (i+1) + ": " + numeroFinal);
                        if(numeroFinal == numero){
                            System.out.println("Iguales");
                            numeroFinal--;
                        }

                        salidaSocket.writeLong(numero);
                        salidaSocket.writeLong(numeroInicial);
                        salidaSocket.writeLong(numeroFinal);

                        System.out.println("Intervalo " + (i+1) + ": " + numeroInicial +  ", " + numeroFinal);


                        if(entradaSocket.readInt() > 0){
                            System.out.println("Numero " + numero + "no es primo");
                            String respuesta = "<html><h1>El número " + numero + " no es primo</h1>></html>";

                            salida.println("HTTP/1.1 200 OK");
                            salida.println("Server: Primo");
                            salida.println("Date: " + new Date());
                            salida.println("Content-type: text/html; charset=utf-8");
                            salida.println("Content-length: " + respuesta.length());
                            salida.println();
                            salida.flush();//Garantizamos que el encabezado va
                            salida.println(respuesta);
                            salida.flush();
                        }else{
                            System.out.println("Numero " + numero + "no es primo");
                            System.out.println("Numero " + numero + "no es primo");
                            String respuesta = "<html><h1>El número " + numero + " es primo</h1>></html>";

                            salida.println("HTTP/1.1 200 OK");
                            salida.println("Server: Primo");
                            salida.println("Date: " + new Date());
                            salida.println("Content-type: text/html; charset=utf-8");
                            salida.println("Content-length: " + respuesta.length());
                            salida.println();
                            salida.flush();//Garantizamos que el encabezado va
                            salida.println(respuesta);
                            salida.flush();
                        }

                        salidaSocket.close();
                        entradaSocket.close();
                        conexion[i].close();

                    }



                }else{
                    salida.println("HTTP/1.1 404 File Not Found");
                    salida.println("Server: Primo");
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

        public static String getNumero(String peticion){
            StringTokenizer tokens = new StringTokenizer(peticion, "?");
            String req_a = tokens.nextToken();
            String req = tokens.nextToken();
            String params = req.substring(0, req.indexOf(" "))+"\n";
            String numero = params.substring(params.indexOf("=")+1, req.indexOf(" "));

            System.out.println("Numero: " + numero);
            return numero;
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
