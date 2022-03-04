package guia2.RMI.Problema5;

import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;
import java.rmi.server.UnicastRemoteObject;

public class arrServer extends UnicastRemoteObject implements arrInterface{

    public arrServer() throws RemoteException{
        super();
    }

    public int maximo(int arr[]) throws RemoteException{
        int aux=arr[0];
        for(int i=1; i<arr.length;i++)
            if(aux < arr[i])
                aux=arr[i];
        return aux;

    }

    public int minimo(int arr[]) throws RemoteException{
        int aux=arr[0];
        for(int i=1; i<arr.length;i++)
            if(aux > arr[i])
                aux=arr[i];
        return aux;
        
    }

    public Double prom(int arr[]) throws RemoteException{
        Double prome=0.0;
        for(int i=0;i<arr.length;i++)
            prome+=arr[i];
        prome/=arr.length;
        return prome;

        
    }

    public static void main(String[] args) {
        try {
            Registry registro= LocateRegistry.createRegistry(7777);
            registro.rebind(arrInterface.LOOKUPNAME, new arrServer());
            System.out.println("Servidor Listo");
        } catch (Exception e) {
            System.err.println("Error: "+e);
        }
    }
    
}
