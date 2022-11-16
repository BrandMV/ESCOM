import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;

public class ClaseRMI extends UnicastRemoteObject implements InterfaceRMI {
    public ClaseRMI() throws RemoteException{
        super();
    }

    public double[][] multiplica_matrices(double[][] A, double[][] B, int N, int M){
        double[][] C = new double[N/6][M/6];

        for (int i = 0; i < N/6; i++){
            for (int j = 0; j < N/6; j++){
                for (int k = 0; k < N; k++){
                    C[i][j] += A[i][k] * B[j][k];
                }
            }
        }

        return C;
    }
}
