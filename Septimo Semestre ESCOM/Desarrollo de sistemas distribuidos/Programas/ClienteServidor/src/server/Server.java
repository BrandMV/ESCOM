package server;

import Utils.Utils;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;

public class Server {
    public static void main(String[] args) {
        try {
            ServerSocket servidor = new ServerSocket(50000);
            System.out.println("Servidor iniciado");

            Socket conexion = servidor.accept();

            DataOutputStream salida = new DataOutputStream(conexion.getOutputStream());
            DataInputStream entrada = new DataInputStream(conexion.getInputStream());

            int n = entrada.readInt();
            System.out.println(n);

            /**Leyendo 10,000 double*/
            long timeStart = System.currentTimeMillis();
            for(double i = 0; i < 10000.0; i++){
                double x = entrada.readDouble();
                System.out.println(x);
            }
            long timeEnd = System.currentTimeMillis();
            Utils.getElapsedTime(timeStart, timeEnd);

            byte[] buffer = new byte[4];
            Utils.read(entrada, buffer, 0, 4);
            System.out.println(new String(buffer, "UTF-8"));

            salida.write("Hola".getBytes());

            /**Leyendo 10,000 empaquetados*/
            timeStart = System.currentTimeMillis();
            byte[] a = new byte[10000*8];
            Utils.read(entrada, a, 0, 10000*8);
            timeEnd = System.currentTimeMillis();

            Utils.getElapsedTime(timeStart, timeEnd);
            ByteBuffer b = ByteBuffer.wrap(a);
            for(int i = 0 ; i < 10000; i++) System.out.println(b.getDouble());

            conexion.close();
        }
        catch (Exception ex){
            System.out.println(ex);
        }
    }
}