package server;

import java.io.*;
import java.net.*;
import java.nio.ByteBuffer;

public class Servidor {
    static class Worker extends Thread {
        Socket conexion;

        public Worker(Socket conexion) {
            this.conexion = conexion;
        }

        public void run() {
            try {
                /** Flujos de entrada y salida */
                DataOutputStream salida = new DataOutputStream(conexion.getOutputStream());
                DataInputStream entrada = new DataInputStream(conexion.getInputStream());

                // 1- Recibiendo el nombre del archivo
                int size = entrada.readInt(); // Leemos la longitud del nombre del archivo
                byte[] buffer = new byte[size];
                read(entrada, buffer, 0, size);
                String fileName = new String(buffer, "UTF-8");
                System.out.println("Nombre del archivo " + fileName);

                // 2. Recibiendo la longitud del arhivo
                int archivoLength = entrada.readInt();
                System.out.println("La longitud del archivo es de " + archivoLength);

                // 3. Recibiendo el contenido del archivo
                boolean isOK = recieveFile(entrada, archivoLength, fileName);

                // 5. Mandando respuesta al cliente
                String respuesta;
                if (!isOK) {
                    respuesta = "El servidor no pudo guardar el archivo " + fileName;
                    salida.writeInt(respuesta.length()); // Mandamos la longitud de la respúesta del servidor
                    salida.write(respuesta.getBytes());
                } else {
                    respuesta = "OK";
                    salida.writeInt(respuesta.length()); // Mandamos la longitud de la respúesta del servidor
                    salida.write(respuesta.getBytes());
                }

                entrada.close();
                salida.close();
                conexion.close();
            } catch (Exception e) {
                System.err.println(e.getMessage());
            }
        }

        public static boolean recieveFile(DataInputStream entrada, int archivoLength, String fileName) {
            File f = new File("");
            File archivo = new File(f.getAbsolutePath() + "/" + fileName);
            try {
                DataOutputStream dos = new DataOutputStream(new FileOutputStream(archivo));
                int datosRecibidos = 0;
                int l = 0;

                // 4. Guardar datos en el disco local
                while (datosRecibidos < archivoLength) {
                    byte[] b = new byte[1500];
                    l = entrada.read(b);
                    dos.write(b, 0, l);
                    dos.flush();
                    datosRecibidos = datosRecibidos + l;
                }

                dos.close();
                return true; // Si se recibió correctamente
            } catch (Exception e) {
                System.out.println(e.getMessage());
                return false; // Si no se recibió correctamente
            }
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
        ServerSocket servidor = new ServerSocket(50000);
        for (; ; ) {
            Socket conexion = servidor.accept();
            Worker w = new Worker(conexion);
            w.start();
        }
    }
}

