package guia2.RMI.Problema2;

import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.*;


public class CircServer extends UnicastRemoteObject implements CircInterface{

    public CircServer() throws RemoteException{
        super();
    }

    public synchronized String punto(Double x, Double y) throws RemoteException{
        if(Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2)) <=100)
            return "El punto esta dentro del circulo";
        return "El punto no esta dentro del ciruclo";
    }

    public static void main(String[] args) {
        try {
            Registry registro= LocateRegistry.createRegistry(7777);
            registro.rebind(CircInterface.LOOKUPNAME, new CircServer());
            System.out.println("Servidor Listo");
        } catch (Exception e) {
            System.err.println("Error: "+e);
        }
    }
    
}
