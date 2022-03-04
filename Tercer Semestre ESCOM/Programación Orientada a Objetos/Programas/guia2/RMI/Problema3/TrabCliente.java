package guia2.RMI.Problema3;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class TrabCliente {

    public static void main(String[] args) {
        try {
            Registry registro=LocateRegistry.getRegistry("127.0.0.1", 7777);
            TrabInterface netConn=(TrabInterface) registro.lookup(TrabInterface.LOOKUPNAME);
            Double sal= netConn.salario(50);
            System.out.println("El salario total es: "+sal);
        } catch (Exception e) {
            System.out.println("Exception in main: "+e);
            e.printStackTrace();
        }
    }

}
