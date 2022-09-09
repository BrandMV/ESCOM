package cliente;

import javax.net.ssl.SSLSocketFactory;
import java.io.*;
import java.net.*;
import java.nio.ByteBuffer;

public class Cliente {
    static int port = 50000;
    static class Worker extends Thread {
        String fileName;
        public Worker(String fileName){
            this.fileName = fileName;
        }
        public void run() {
            File f = new File("");

            // 1. Leyendo archivo del disco
            File archivo = new File(f.getAbsolutePath() + "/" + fileName);

            // 2. Conectandonos al
            try{
                Socket conexion = new Socket("Localhost", port);
                /**Flujos de entrada y salida*/
                DataOutputStream salidaSocket = new DataOutputStream(conexion.getOutputStream());
                DataInputStream entradaSocket = new DataInputStream(conexion.getInputStream());

                // 3. Enviando el nombre del archivo
                salidaSocket.writeInt(fileName.length()); // Primero mandamos la longitud del nombre del archivo
                salidaSocket.write(fileName.getBytes());

                // 4. Enviando la longitud del archivo
                int archivoLength = (int) archivo.length();
                salidaSocket.writeInt(archivoLength);
                System.out.println("La longitud del archivo es de " + archivoLength);

                // 5. Mandando el contenido del archivo
                DataInputStream dis = new DataInputStream(new FileInputStream(archivo.getAbsolutePath()));
                sendFile(dis, salidaSocket, archivoLength);

                // 6. Esperar respuesta del servidor
                int respuestaServidorLength = entradaSocket.readInt(); // Leemos la longitud del mensaje recibido del servidor
                byte[] buffer = new byte[respuestaServidorLength];
                read(entradaSocket, buffer, 0, respuestaServidorLength);
                String respuestaServidor = new String(buffer, "UTF-8");
                System.out.println(respuestaServidor);

                // 7. Cerrando la conexion
                conexion.close();
            }
            catch (Exception ex){
                System.err.println(ex.getMessage());
            }

        }

        public static void sendFile(DataInputStream dis, DataOutputStream dos, int tam) throws IOException{
            int datosEnviados = 0;
            int l = 0;
            // Cuando se mandan todos los datos acaba el ciclo
            while(datosEnviados < tam){
                byte[] b = new byte[1500];
                l = dis.read(b);
                dos.write(b, 0, l);
                dos.flush();
                datosEnviados = datosEnviados + l;
            }

            dis.close();
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
        /*
        SSLSocketFactory cliente = (SSLSocketFactory) SSLSocketFactory.getDefault();
        Socket socket = cliente.createSocket("localhost",5000);
        */
        Socket conexion = new Socket("Localhost", 50000);

        if (args.length < 1) {
            System.out.println("Debe ingresar un nombre de archivo o mas como argumento: java archivo-1 archivo-2 archivo-3");
            System.exit(0);
        }

        for (int i = 0; i < args.length; i++) {
            Worker w = new Worker(args[i]);
            w.start();

        }



    }
}
