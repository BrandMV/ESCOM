import java.rmi.Naming;

public class Cliente {
    public static void main(String[] args) throws Exception {
        int N = 6, M = 5;
        double [] [] A = new double[N][M];
        double [] [] B = new double[N][N];
        double [] [] Baux = new double[N][N];
        double [] [] C = new double[N][N];
        double [] [] A1 = new double[N/6][M];
        double [] [] A2 = new double[N/6][M];
        double [] [] A3 = new double[N/6][M];
        double [] [] A4 = new double[N/6][M];
        double [] [] A5 = new double[N/6][M];
        double [] [] A6 = new double[N/6][M];
        double [] [] B1 = new double[N/6][M];
        double [] [] B2 = new double[N/6][M];
        double [] [] B3 = new double[N/6][M];
        double [] [] B4 = new double[N/6][M];
        double [] [] B5 = new double[N/6][M];
        double [] [] B6 = new double[N/6][M];

        /// 1. Inicializando matrices
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                A[i][j] = 3*i + 2*j;
            }
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                B[i][j] = 2*i - 3*j;
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

        System.out.println("Matriz B transpuesta:");
        imprimirMatriz(B, B.length, M);
        System.out.println("Matriz A:");
        imprimirMatriz(A, N, M);

        /// Separando matrices
        A1 = separa_matriz(A, 0, N, M);
        A2 = separa_matriz(A, N/6, N, M);
        A3 = separa_matriz(A, N/3, N, M);
        A4 = separa_matriz(A, N/2, N, M);
        A5 = separa_matriz(A, N*2/3, N, M);
        A6 = separa_matriz(A, N*5/6, N, M);
        /*
        System.out.println("Matrices Ax: ");
        imprimirMatriz(A1, N/6, M);
        imprimirMatriz(A2, N/6, M);
        imprimirMatriz(A3, N/6, M);
        imprimirMatriz(A4, N/6, M);
        imprimirMatriz(A5, N/6, M);
        imprimirMatriz(A6, N/6, M);
         */

        B1 = separa_matriz(B, 0, N, M);
        B2 = separa_matriz(B, N/6, N, M);
        B3 = separa_matriz(B, N/3, N, M);
        B4 = separa_matriz(B, N/2, N, M);
        B5 = separa_matriz(B, N*2/3, N, M);
        B6 = separa_matriz(B, N*5/6, N, M);
        /*
        System.out.println("Matrices Bx: ");
        imprimirMatriz(B1, N/6, M);
        imprimirMatriz(B2, N/6, M);
        imprimirMatriz(B3, N/6, M);
        imprimirMatriz(B4, N/6, M);
        imprimirMatriz(B5, N/6, M);
        imprimirMatriz(B6, N/6, M);
         */

        //// Calculando matrices C1 ... C12
        double[][] C1 = multiplica_matrices(A1, B1, N, M);
        double[][] C2 = multiplica_matrices(A1, B2, N, M);
        double[][] C3 = multiplica_matrices(A1, B3, N, M);
        double[][] C4 = multiplica_matrices(A1, B4, N, M);
        double[][] C5 = multiplica_matrices(A1, B5, N, M);
        double[][] C6 = multiplica_matrices(A1, B6, N, M);
        double[][] C7 = multiplica_matrices(A2, B1, N, M);
        double[][] C8 = multiplica_matrices(A2, B2, N, M);
        double[][] C9 = multiplica_matrices(A2, B3, N, M);
        double[][] C10 = multiplica_matrices(A2, B4, N, M);
        double[][] C11 = multiplica_matrices(A2, B5, N, M);
        double[][] C12 = multiplica_matrices(A2, B6, N, M);

        String url = "rmi://localhost/prueba";

       InterfaceRMI r = (InterfaceRMI) Naming.lookup(url);
       InterfaceRMI r2 = (InterfaceRMI) Naming.lookup(url);

        //// Calculando matrices C13 ... C24
        double[][] C13 = r.multiplica_matrices(A3, B1, N, M);
        double[][] C14 = r.multiplica_matrices(A3, B2, N, M);
        double[][] C15 = r.multiplica_matrices(A3, B3, N, M);
        double[][] C16 = r.multiplica_matrices(A3, B4, N, M);
        double[][] C17 = r.multiplica_matrices(A3, B5, N, M);
        double[][] C18 = r.multiplica_matrices(A3, B6, N, M);
        double[][] C19 = r.multiplica_matrices(A4, B1, N, M);
        double[][] C20 = r.multiplica_matrices(A4, B2, N, M);
        double[][] C21 = r.multiplica_matrices(A4, B3, N, M);
        double[][] C22 = r.multiplica_matrices(A4, B4, N, M);
        double[][] C23 = r.multiplica_matrices(A4, B5, N, M);
        double[][] C24 = r.multiplica_matrices(A4, B6, N, M);

        //// Calculando matrices C25 ... C36
        double[][] C25 = r2.multiplica_matrices(A5, B1, N, M);
        double[][] C26 = r2.multiplica_matrices(A5, B2, N, M);
        double[][] C27 = r2.multiplica_matrices(A5, B3, N, M);
        double[][] C28 = r2.multiplica_matrices(A5, B4, N, M);
        double[][] C29 = r2.multiplica_matrices(A5, B5, N, M);
        double[][] C30 = r2.multiplica_matrices(A5, B6, N, M);
        double[][] C31 = r2.multiplica_matrices(A6, B1, N, M);
        double[][] C32 = r2.multiplica_matrices(A6, B2, N, M);
        double[][] C33 = r2.multiplica_matrices(A6, B3, N, M);
        double[][] C34 = r2.multiplica_matrices(A6, B4, N, M);
        double[][] C35 = r2.multiplica_matrices(A6, B5, N, M);
        double[][] C36 = r2.multiplica_matrices(A6, B6, N, M);

    }

    /**
     * @brief Método que imprime una matriz
     * @param m La matriz a imprimir
     * @param renglones Renglones de la matriz a imprimir
     * @param columnas Columnas de la matriz a imprimir
     */
    static void imprimirMatriz(double m[][], int renglones, int columnas) {
        for (int i = 0; i < renglones; i++) {
            for (int j = 0; j < columnas; j++) {
                System.out.printf("%.2f\t", m[i][j]);
            }
            System.out.println("");
        }
    }

    /**
     * @brief Métofo que calcula el checksum de una matriz
     * @param matriz Matriz de la que calcularemos el checksum
     */
    static void calcularChecksum(double  matriz[][], int N, int M){
        float checksum = 0;
        for (int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                checksum += matriz[i][j];
            }
        }
        System.out.println("Checksum de la matriz = " + checksum);
    }

    static double[][] separa_matriz(double[][] A, int inicio, int N, int M){
        double[][] matriz = new double[N/6][M];
        for(int i = 0; i < N/6; i++){
            for(int j = 0; j < M; j++){
                matriz[i][j] = A[i + inicio][j];
            }
        }
        return matriz;
    }

    static double[][] multiplica_matrices(double[][] A, double[][] B, int N, int M){
        double[][] C = new double[N/6][N/6];
        for (int i = 0; i < N/6; i++){
            for (int j = 0; j < N/6; j++){
                for (int k = 0; k < M; k++){
                    C[i][j] += A[i][k] * B[j][k];
                }
            }
        }
        return C;
    }
}
