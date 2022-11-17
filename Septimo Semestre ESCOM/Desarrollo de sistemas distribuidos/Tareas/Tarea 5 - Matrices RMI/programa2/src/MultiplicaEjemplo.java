public class MultiplicaEjemplo {
    static int N = 6;
    static int M = 5;
    static double [] [] A = new double[N][M];
    static double [] [] B = new double[N][N];
    static double [] [] Baux = new double[N][N];
    static double [] [] C = new double[N][N];

    public static void main(String[] args) {
/// 1. Inicializando matrices
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                A[i][j] = 3 * i + 2 * j;
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                B[i][j] = 2 * i - 3 * j;
            }
        }
        Baux = B;

        /// 2. Transpuesta de B

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                double x = B[i][j];
                B[i][j] = B[j][i];
                B[j][i] = x;
            }
        }

        System.out.println("Matriz A:");
        imprimirMatriz(A, N, M);
        System.out.println("Matriz B:");
        imprimirMatriz(B, N, M);

        System.out.println("Matriz C:");
        C = multiplicarMatrices(A, B);
        imprimirMatriz(C, N, N);

        calcularChecksum(C, N);
    }

    static void calcularChecksum(double matriz[][], int tam) {
        float checksum = 0;
        for (int i = 0; i < tam; i++) {
            for (int j = 0; j < tam; j++) {
                checksum += matriz[i][j];
            }
        }

        System.out.println("Checksum de la matriz = " + checksum);
    }

    static void imprimirMatriz(double m[][], int renglones, int columnas) {
        for (int i = 0; i < renglones; i++) {
            for (int j = 0; j < columnas; j++) {
                System.out.printf("%.2f\t", m[i][j]);
            }
            System.out.println("");
        }
    }

    static double[][] multiplicarMatrices(double[][] Ax, double[][] Bx) {
        double[][] Cx = new double[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < M; k++) {
                    Cx[i][j] += Ax[i][k] * Bx[j][k];
                }
            }
        }
        return Cx;
    }
}
