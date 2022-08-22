package Cliente;

import Utils.Utils;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.charset.StandardCharsets;

public class Cliente {
    public static void main(String[] args) {
        for(;;){
            try {
                Socket conexion = new Socket("Localhost", 50000);
                System.out.println("Cliente iniciado");

                DataOutputStream salida = new DataOutputStream(conexion.getOutputStream());
                DataInputStream entrada = new DataInputStream(conexion.getInputStream());

                salida.writeInt(123);

                long timeStart = System.currentTimeMillis();
                /**Mandando 10,000 números double con writeDouble*/
                for(double i = 0; i < 10000.0; i++){
                    salida.writeDouble(i);
                }
                long timeEnd = System.currentTimeMillis();

                Utils.getElapsedTime(timeStart, timeEnd);
                salida.write("Hola".getBytes(StandardCharsets.UTF_8));

                byte[] buffer = new byte[4];

                Utils.read(entrada, buffer, 0, 4);
                System.out.println(new String(buffer, "UTF-8"));

                /**Mandando 10,000 números con bytebuffer*/
                timeStart = System.currentTimeMillis();
                ByteBuffer b = ByteBuffer.allocate(10000*8);
                for(int i = 0; i < 10000; i++){
                    b.putDouble(i);
                }
                byte[] a = b.array();
                salida.write(a);
                timeEnd = System.currentTimeMillis();

                Utils.getElapsedTime(timeStart, timeEnd);
                conexion.close();

                break;
            }
            catch (Exception ex){
                System.err.println(ex);
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
            }
        }
    }
}
