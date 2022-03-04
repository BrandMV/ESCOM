package guia2.RMI.Problema2;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface CircInterface extends Remote{

    public String punto(Double x, Double y) throws RemoteException;
    public final static String LOOKUPNAME="EncontrarPunto";
    
}
