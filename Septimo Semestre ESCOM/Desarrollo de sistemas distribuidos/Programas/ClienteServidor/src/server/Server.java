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

            Socket conexion = servidor.accept();

            DataOutputStream salida = new DataOutputStream(conexion.getOutputStream());
            DataInputStream entrada = new DataInputStream(conexion.getInputStream());

            int n = entrada.readInt();
            System.out.println(n);

            double x = entrada.readDouble();
            System.out.println(x);

            byte[] buffer = new byte[4];
            Utils.read(entrada, buffer, 0, 4);
            System.out.println(new String(buffer, "UTF-8"));

            salida.write("Hola".getBytes());

            byte[] a = new byte[5*8];
            Utils.read(entrada, a, 0, 5*8);

            ByteBuffer b = ByteBuffer.wrap(a);
            for(int i = 0 ; i < 5; i++) System.out.println(b.getDouble());

            conexion.close();
        }
        catch (Exception ex){
            System.out.println(ex);
        }
    }
}
