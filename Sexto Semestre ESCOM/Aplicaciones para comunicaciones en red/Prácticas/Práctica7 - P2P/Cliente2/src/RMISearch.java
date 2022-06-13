
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface RMISearch extends Remote {
    FoundFile search(String file) throws RemoteException;
}
