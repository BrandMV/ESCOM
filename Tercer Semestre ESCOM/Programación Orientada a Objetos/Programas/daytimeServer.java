import java.net.*;
import java.util.Date;
import java.io.*;


public class daytimeServer {
    public final static int daytimePort = 13;
    public static void main(String[] args) {
        ServerSocket theServer;
        Socket theConnection;
        PrintStream p;

        try{// es un try anidado, si theserver = new ServerSocket... lanza una excepcion nos vamos al segundo catch
            theServer = new ServerSocket(daytimePort); //1 esta dentro del try por que es un metodo que nos puede generar una excepcion, paso 1
            try{
                while(true){ //infinito
                    theConnection = theServer.accept(); //se desbloquea el programa cuando un cliente se conecta, esperamos hasta que el cliente se conecte, paso 2
                    //byte a la vez
                    p = new PrintStream(theConnection.getOutputStream()); //paso 3
                    p.println(new Date()); //fecha y hora actual, paso 4
                    theConnection.close(); //paso 5
                }
            }
            catch(IOException e){
                theServer.close();
                System.err.println(e);
            }
        }
        catch(IOException e){
            System.err.println(e);
        }
    }
}
