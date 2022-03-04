package guia2.RMI.Problema4;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface cadInterface extends Remote{

    public String cadMayus(String cad) throws RemoteException;
    public int longCad(String cad) throws RemoteException;

    public final static String LOOKUPNAME="Cadena";
    
}
