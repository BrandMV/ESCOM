package guia2.RMI.Problema2;

import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class CircCliente {

    public static void main(String[] args) {
        
        try {
            Registry registro=LocateRegistry.getRegistry("127.0.0.1", 7777);
            CircInterface netConn=(CircInterface) registro.lookup(CircInterface.LOOKUPNAME);
            String punt= netConn.punto(5.0, 6.0);
            System.out.println(punt);
        } catch (Exception e) {
            System.out.println("Exception in main: "+e);
            e.printStackTrace();
        }
    }
    
}
