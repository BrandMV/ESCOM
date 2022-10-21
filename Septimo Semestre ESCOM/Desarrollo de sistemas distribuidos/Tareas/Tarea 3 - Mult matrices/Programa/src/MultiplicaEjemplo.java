public class MultiplicaEjemplo {
    static int N = 12;
    static float[][] A = new float[N][N];
    static float[][] B = new float[N][N];
    static float[][] C = new float[N][N];
    public static void main(String[] args) {
/// 1. Inicializando matrices
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = i + 3 * j;
                B[i][j] = 2 * i - j;
                C[i][j] = 0;
            }
        }
        /// 2. Transpuesta de B
        /*
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                float x = B[i][j];
                B[i][j] = B[j][i];
                B[j][i] = x;
            }
        }

         */
        System.out.println("Matriz A:");
        //imprimirMatriz(A, N, N);
        System.out.println("Matriz B:");
        //imprimirMatriz(B, N, N);

        System.out.println("Matriz C:");
        C = multiplicarMatrices(A,B);
        //imprimirMatriz(C, N, N);

        calcularChecksum(C, N);
    }

    static void calcularChecksum(float matriz[][], int tam){
        float checksum = 0;
        for (int i = 0; i < tam; i++){
            for(int j = 0; j < tam; j++){
                checksum += matriz[i][j];
            }
        }

        System.out.println("Checksum de la matriz = " + checksum);
    }

    static void imprimirMatriz(float m[][], int renglones, int columnas) {
        for (int i = 0; i < renglones; i++) {
            for (int j = 0; j < columnas; j++) {
                System.out.printf("%.2f ", m[i][j]);
            }
            System.out.println("");
        }
    }
    static float[][] multiplicarMatrices(float[][] Ax, float[][] Bx){
        float[][] Cx = new float[N][N];
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                for (int k = 0; k < N; k++){
                    Cx[i][j] += Ax[i][k] * Bx[j][k];
                }
            }
        }
        return Cx;
    }
}
