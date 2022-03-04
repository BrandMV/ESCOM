package Practicas.Practica8;

import java.rmi.Remote;
import java.rmi.RemoteException;

public interface ChatInterface extends Remote{

    public String preg(String pre) throws RemoteException;

    public final static String LOOKUPNAME="chatbot";
    
}
