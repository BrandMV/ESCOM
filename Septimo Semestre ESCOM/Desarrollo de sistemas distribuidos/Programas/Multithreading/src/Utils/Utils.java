package Utils;

import java.io.DataInputStream;

public class Utils {
    public static void read(DataInputStream f, byte[] b, int posicion, int longitud) throws Exception{
        while(longitud > 0){
            int n = f.read(b, posicion, longitud);
            posicion += n;
            longitud -= n;
        }
    }

    public static void getElapsedTime(long timeStart, long timeEnd){
        long elapsedTime = timeEnd - timeStart;
        System.out.println("Tiempo en mandar 10,000 doubles: " + elapsedTime + "ms");
    }
}
