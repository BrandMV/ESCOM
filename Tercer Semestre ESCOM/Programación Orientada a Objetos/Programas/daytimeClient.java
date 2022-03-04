//El cliente se conecta al servidor en el puerto 13, cuando un cliente se conecta, el servidor le manda una cadena con la hora y fecha actual y cierra la conexion
//El cliente recibe la cadena y la imprime en pantalla


import java.net.*;

import java.io.*;

public class daytimeClient {
    public static void main(String[] args) {
        Socket theSocket; //Socket viene en java.net
        String hostname;
        DataInputStream theTimeStream; //Stream = flujo

        if(args.length > 0) { hostname = args[0];}
        else { hostname = "localhost";}
        try{ //el codigo dentro del try lo escribimos como si vivieramos en un mundo ideal, Si el constructor lanza una excepcion lo de abajo no se ejecuta
            theSocket = new Socket(hostname, 13); //1 y 2
            //                                      InputStream byte a la vez
            theTimeStream = new DataInputStream(theSocket.getInputStream());//3 el DataInpuntStream tiene readLine(), el cliente necesita flujo de entrada
            String theTime = theTimeStream.readLine(); //readLine puede leer toda la cadena completa de una sola vez
            System.out.println("It is " + theTime + " at " + hostname);
        } //end try
        catch(UnknownHostException e) { System.out.println(e);}
        catch (IOException e) {System.err.println(e);} //los mensajes de error siempre en pantalla
        } //end main
    
} //end daytimeClient

//linda vista seria el ip y el numero de puesto seria el puerto
