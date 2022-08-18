package cliente;

import Utils.Utils;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;

public class Cliente {
    public static void main(String[] args) {
        try {
            Socket conexion = new Socket("Localhost", 50000);
            System.out.println("Cliente iniciado");

            DataOutputStream salida = new DataOutputStream(conexion.getOutputStream());
            DataInputStream entrada = new DataInputStream(conexion.getInputStream());

            salida.writeInt(123);
            salida.writeDouble(1234567890.1234567890);
            salida.write("Hola".getBytes(StandardCharsets.UTF_8));

            byte[] buffer = new byte[4];

            Utils.read(entrada, buffer, 0, 4);
            System.out.println(new String(buffer, "UTF-8"));

            ByteBuffer b = ByteBuffer.allocate(5*8);
            b.putDouble(1.1);
            b.putDouble(1.2);
            b.putDouble(1.3);
            b.putDouble(1.4);
            b.putDouble(1.5);

            byte[] a = b.array();

            salida.write(a);

            conexion.close();
        }
        catch (Exception ex){
            System.err.println(ex);
        }
    }

}
