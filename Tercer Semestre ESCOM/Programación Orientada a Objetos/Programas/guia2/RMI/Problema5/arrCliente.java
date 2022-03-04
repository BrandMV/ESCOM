package guia2.RMI.Problema5;

import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class arrCliente {

    public static void main(String[] args) {
        try {
            int arr[]={5,2,7,8,1};
            Registry registro=LocateRegistry.getRegistry("127.0.0.1", 7777);
            arrInterface netConn=(arrInterface) registro.lookup(arrInterface.LOOKUPNAME);
            System.out.println("El maximo es: "+netConn.maximo(arr));
            System.out.println("El minimo es: "+netConn.minimo(arr));
            System.out.println("El promedio es: "+netConn.prom(arr));
        } catch (Exception e) {
            System.out.println("Exception in main: "+e);
            e.printStackTrace();
        }
    }
    }
    

