package guia2.RMI.AreaTriangulo;

import java.rmi.*;

public interface TrianguloInterface extends Remote{
    
    public Double areaT(Double h, Double b) throws RemoteException;
    public final static String LOOKUPNAME="Triangulo";
    
}
