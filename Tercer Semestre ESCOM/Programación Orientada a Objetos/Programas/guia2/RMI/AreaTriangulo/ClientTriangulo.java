package guia2.RMI.AreaTriangulo;

import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class ClientTriangulo {

    public static void main(String[] args) {

        try {
            Registry registro=LocateRegistry.getRegistry("127.0.0.1", 7777);
            TrianguloInterface netConn=(TrianguloInterface) registro.lookup(TrianguloInterface.LOOKUPNAME);
            Double area= netConn.areaT(5.0, 6.0);
            System.out.println("El area del triangulo es: "+ area);
        } catch (Exception e) {
            System.out.println("Exception in main: "+e);
            e.printStackTrace();
        }
    }
    
}
