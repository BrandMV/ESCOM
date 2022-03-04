package guia2.RMI.AreaTriangulo;

import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.*;

public class ServerTriangulo extends UnicastRemoteObject implements TrianguloInterface{

    public ServerTriangulo() throws RemoteException{
        super();
    }

    public synchronized Double areaT(Double h, Double b) throws RemoteException{
        return (b*h)/2;
    }

    public static void main(String[] args) {
        try {
            Registry registro= LocateRegistry.createRegistry(7777);
            registro.rebind(TrianguloInterface.LOOKUPNAME, new ServerTriangulo());
            System.out.println("Servidor Listo");
        } catch (Exception e) {
            System.err.println("Error: "+e);
        }
    }
    
}
