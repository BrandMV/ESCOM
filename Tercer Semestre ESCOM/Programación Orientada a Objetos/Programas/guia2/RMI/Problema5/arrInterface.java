package guia2.RMI.Problema5;

import java.rmi.RemoteException;

import java.rmi.*;

public interface arrInterface extends Remote{

    public int maximo(int arr[]) throws RemoteException;
    public int minimo(int arr[]) throws RemoteException;
    public Double prom(int arr[]) throws RemoteException;

    public final static String LOOKUPNAME="arreglo";
    
}
