
import java.rmi.Remote;
import java.rmi.RemoteException;

/**Extending remote helps us to indicate that te interface identifies itself as an interface
 *  whose methods can be invoked from another Java virtual machine*/
public interface RMISearch extends Remote {
    FoundFile search(String file) throws RemoteException;
}
