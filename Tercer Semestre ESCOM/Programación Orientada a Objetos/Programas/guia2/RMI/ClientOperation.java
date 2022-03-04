package guia2.RMI;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;

import javax.swing.JOptionPane;



public class ClientOperation {
    private static RMIInterface look_up;

    public static void main(String[] args) 
        throws MalformedURLException, RemoteException, NotBoundException {
        
        look_up = (RMIInterface) Naming.lookup("//localhost/MyServer");
        String txt = JOptionPane.showInputDialog("What is your name?");
            
        String response = look_up.helloTo(txt);
        JOptionPane.showMessageDialog(null, response);
    }
    
}
