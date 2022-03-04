package guia2.RMI;

import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ServerOperation extends UnicastRemoteObject implements RMIInterface{

    protected ServerOperation() throws RemoteException{
        super(); //llama al constructor de UnicastRemoteObject
    }

    @Override
    public String helloTo(String name) throws RemoteException{
        System.err.println(name + " is trying to contact!");
        return "Server says hello to " + name;

    }

    public static void main(String[] args) {
        try {
            Naming.rebind("//localhost/MyServer", new ServerOperation());
            System.err.println("Server ready");
            
        } catch (Exception e) {
            System.err.println("Server exceptio: " + e.toString());
            e.printStackTrace();
        }
    }


}
    

