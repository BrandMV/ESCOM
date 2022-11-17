import java.rmi.Remote;
import java.rmi.RemoteException;

public interface InterfaceRMI extends Remote {
    double[][] multiplica_matrices(double[][] A, double[][] B, int N, int M) throws RemoteException;
}
