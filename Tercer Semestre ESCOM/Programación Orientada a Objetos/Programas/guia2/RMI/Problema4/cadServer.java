package guia2.RMI.Problema4;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class cadServer extends UnicastRemoteObject implements cadInterface{

    public cadServer() throws RemoteException{
        super();
    }

    public String cadMayus(String cad) throws RemoteException{
        return cad.toUpperCase();
    }
    public int longCad(String cad) throws RemoteException{
        return cad.length();
    }

    public static void main(String[] args) {
        try {
            Registry registro= LocateRegistry.createRegistry(7777);
            registro.rebind(cadInterface.LOOKUPNAME, new cadServer());
            System.out.println("Servidor Listo");
        } catch (Exception e) {
            System.err.println("Error: "+e);
        }
    }
    
}
