
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Date;
import java.util.StringTokenizer;

public class ServidorHttp {
    static class Worker extends Thread {
        Socket conexion;

        Worker(Socket conexion) {
            this.conexion = conexion;
        }

        public void run() {
            try {
                BufferedReader entrada = new BufferedReader(new InputStreamReader(conexion.getInputStream()));
                /**Con printwriter tiene los metodos para salto de linea*/
                PrintWriter salida = new PrintWriter(conexion.getOutputStream());
                String s = entrada.readLine();
                String verificacion = null;

                if (s.startsWith("GET /primo?")) {
                    long numero = Long.parseLong(getNumero(s));
                    long numeroDividido = numero / 2;

                    /**Obteniendo los intervalos para mandar al Servidor A*/
                    long numeroInicial = 2;
                    long numeroFinal = 0;

                    int port = 60000;
                    Socket conexion = null;
                    int primo = 0;

                    /**Nos conectamos a las 4 instancias del servidor A con un puerto diferente*/
                    for (int i = 0; i < 4; i++) {
                        try {
                            //Creamos una instancia del servidor A
                            conexion = new Socket("Localhost", port);
                            port++;

                            /**Mandamos intervalos para que las instancias del servidor A hagan sus operaciones*/
                            DataOutputStream salidaSocket = new DataOutputStream(conexion.getOutputStream());
                            DataInputStream entradaSocket = new DataInputStream(conexion.getInputStream());
                            if (i != 0) {
                                numeroInicial = numeroFinal + 1;
                            }
                            numeroFinal = (numeroDividido / 4) * (i + 1);

                            salidaSocket.writeLong(numero);
                            salidaSocket.writeLong(numeroInicial);
                            salidaSocket.writeLong(numeroFinal);

                            int size = entradaSocket.readInt();
                            byte[] buffer = new byte[size];
                            System.out.println(size);
                            read(entradaSocket, buffer, 0, size);
                            verificacion = new String(buffer, "UTF-8");

                            System.out.println("Intervalo " + (i + 1) + ": " + numeroInicial + ", " + numeroFinal + ", divide o no: " + verificacion + " tam: " + size);

                            // Vamos sumando las veces que se obtuvo un DIVIDE de parte de los servidores
                            if (verificacion.equals("DIVIDE")) primo++;

                            salidaSocket.close();
                            entradaSocket.close();
                            conexion.close();
                        } catch (Exception e) {
                            Thread.sleep(200);
                            System.err.println(e.getMessage());
                        }
                    }

                    // Si al menos un servidor devolvio la palabra DIVIDE el número no es primo
                    if (primo > 0) {
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
                    } else {
                        System.out.println("Numero " + numero + " es primo");
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
                } else {
                    salida.println("HTTP/1.1 404 File Not Found");
                    salida.println("Server: Primo");
                    salida.println("Date: " + new Date());
                    salida.println("Content-type: text/html; charset=utf-8");
                    salida.println("Content-length: 0");
                    salida.println();
                    salida.flush();
                }
            } catch (Exception ex) {
                System.err.println(ex.getMessage());
            }
        }

        /**
         * Método que obtiene el numero de los parametros
         *
         * @param peticion petición http que se realiza
         * @return el numero
         */
        public static String getNumero(String peticion) {
            StringTokenizer tokens = new StringTokenizer(peticion, "?");
            String req_a = tokens.nextToken();
            String req = tokens.nextToken();
            String params = req.substring(0, req.indexOf(" ")) + "\n";
            String numero = params.substring(params.indexOf("=") + 1, req.indexOf(" "));

            System.out.println("Numero: " + numero);
            return numero;
        }

        /**
         * Función que lee una cadena de bytes mandada desde el servidor
         *
         * @param f        el flujo de entrada
         * @param b        el arreglo de bytes
         * @param posicion la posicion del arreglo
         * @param longitud la longitud del arreglo
         * @throws Exception
         */
        public static void read(DataInputStream f, byte[] b, int posicion, int longitud) throws Exception {
            while (longitud > 0) {
                int n = f.read(b, posicion, longitud);
                posicion += n;
                longitud -= n;
            }
        }
    }

    public static void main(String[] args) throws Exception {
        ServerSocket servidor = new ServerSocket(8081);
        for (; ; ) {
            Socket conexion = servidor.accept();
            new Worker(conexion).start();
        }
    }
}
