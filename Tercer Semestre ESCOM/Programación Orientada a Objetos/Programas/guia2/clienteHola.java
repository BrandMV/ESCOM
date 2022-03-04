import java.net.*;
import java.io.*;

public class clienteHola {
    
    public static void main(String[] args) {
        Socket theSocket; //Socket viene en java.net
        String hostname;
        DataInputStream cadenaStream; //Stream = flujo

        if(args.length > 0) { hostname = args[0];}
        else { hostname = "localhost";}
        try{ //el codigo dentro del try lo escribimos como si vivieramos en un mundo ideal, Si el constructor lanza una excepcion lo de abajo no se ejecuta
            theSocket = new Socket(hostname, 80); //1 y 2
            //                                      InputStream byte a la vez
            cadenaStream = new DataInputStream(theSocket.getInputStream());//3 el DataInpuntStream tiene readLine(), el cliente necesita flujo de entrada
            String cadena = cadenaStream.readLine(); //readLine puede leer toda la cadena completa de una sola vez
            System.out.println(cadena);
        } //end try
        catch(UnknownHostException e) { System.out.println(e);}
        catch (IOException e) {System.err.println(e);} //los mensajes de error siempre en pantalla
        } //end main
    
}
