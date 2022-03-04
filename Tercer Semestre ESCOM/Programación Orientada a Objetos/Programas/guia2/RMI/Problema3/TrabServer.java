package guia2.RMI.Problema3;

import java.rmi.*;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.*;

public class TrabServer extends UnicastRemoteObject implements TrabInterface{

    public TrabServer() throws RemoteException{
        super();
    }

    public Double salario(int hrs) throws RemoteException{
        Double salario= 185.56;
        Double saldob=salario*2;
        if (hrs <= 40)
            return hrs*salario;
        return (40*salario) + ((hrs-40)*saldob);

    }

    public static void main(String[] args) {
        try {
            Registry registro= LocateRegistry.createRegistry(7777);
            registro.rebind(TrabInterface.LOOKUPNAME, new TrabServer());
            System.out.println("Servidor Listo");
        } catch (Exception e) {
            System.err.println("Error: "+e);
        }
    }


    
}
