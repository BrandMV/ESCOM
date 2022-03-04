package guia2.RMI.Problema3;

import java.rmi.*;

public interface TrabInterface extends Remote{

    public Double salario(int hrs) throws RemoteException;
    public final static String LOOKUPNAME="salario";
    
}
