import java.rmi.Remote;
import java.rmi.RemoteException;

public interface InterfaceRMI extends Remote {
    public double[][] multiplica_matrices(double[][] A, double[][] B, int N, int M) throws RemoteException;
}
