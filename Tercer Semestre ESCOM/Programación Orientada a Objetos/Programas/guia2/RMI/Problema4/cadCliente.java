package guia2.RMI.Problema4;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class cadCliente {
    public static void main(String[] args) {
        try {
            Registry registro=LocateRegistry.getRegistry("127.0.0.1", 7777);
            cadInterface netConn=(cadInterface) registro.lookup(cadInterface.LOOKUPNAME);
            String cadena="Hola amigos";
            System.out.println("La cadena en mayusculas: "+ netConn.cadMayus(cadena));
            System.out.println("La longitud de la cadena es: "+ netConn.longCad(cadena));
        } catch (Exception e) {
            System.out.println("Exception in main: "+e);
            e.printStackTrace();
        }
    }
    
}
