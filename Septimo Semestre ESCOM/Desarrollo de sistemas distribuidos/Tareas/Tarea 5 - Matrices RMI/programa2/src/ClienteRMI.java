import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;
import java.util.*;

public class ClienteRMI {
    static int N = 6000;
    static int M = 5000;

    /**
     * @brief Hilo que realiza la multiplicación de las matrices parciales
     */
    static class Worker extends Thread{
        double [] [] Ax = new double[N/6][M];
        double [] [] Bx = new double[N/6][M];
        double[][] Cx = new double[N/6][N/6];
        int Ci;
        boolean isRmiMult;
        InterfaceRMI r;

        public Worker(double[][] Ax, double[][] Bx, int Ci, boolean isRmiMult, InterfaceRMI r){
            this.Ax = Ax;
            this.Bx = Bx;
            this.Ci = Ci;
            this.isRmiMult = isRmiMult;
            this.r = r;
        }

        public void run() {
            if(isRmiMult){
                try {
                    this.Cx = r.multiplica_matrices(Ax,Bx, N, M);
                } catch (RemoteException e) {
                    e.printStackTrace();
                }

            }else{
                this.Cx = multiplica_matrices(Ax,Bx, N, M);
            }
        }
    }

    public static void main(String[] args) throws Exception{
        double [] [] A = new double[N][M];
        double [] [] B = new double[N][N];
        double [] [] Baux = new double[M][N];
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
        if(N == 6 && M == 5){
            System.out.println("Matriz A");
            imprimirMatriz(A, N, M);
            System.out.println("Matriz B");
            imprimirMatriz(Baux, M, N);
        }


        /// 2. Transpuesta de B

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < i; j++) {
                double x = B[i][j];
                B[i][j] = B[j][i];
                B[j][i] = x;
            }
        }
        //System.out.println("Transpuesta");
        //imprimirMatriz(B, N, M);

        /// Separando matrices
        A1 = separa_matriz(A, 0, N, M);
        A2 = separa_matriz(A, N/6, N, M);
        A3 = separa_matriz(A, N/3, N, M);
        A4 = separa_matriz(A, N/2, N, M);
        A5 = separa_matriz(A, N*2/3, N, M);
        A6 = separa_matriz(A, N*5/6, N, M);

        B1 = separa_matriz(B, 0, N, M);
        B2 = separa_matriz(B, N/6, N, M);
        B3 = separa_matriz(B, N/3, N, M);
        B4 = separa_matriz(B, N/2, N, M);
        B5 = separa_matriz(B, N*2/3, N, M);
        B6 = separa_matriz(B, N*5/6, N, M);

        List<double[][]> AM = new ArrayList<>(5);
        AM.add(A1);
        AM.add(A2);
        AM.add(A3);
        AM.add(A4);
        AM.add(A5);
        AM.add(A6);
        List<double[][]> BM = new ArrayList<>(5);
        BM.add(B1);
        BM.add(B2);
        BM.add(B3);
        BM.add(B4);
        BM.add(B5);
        BM.add(B6);

        String url = "rmi://localhost/prueba";

        InterfaceRMI r = (InterfaceRMI) Naming.lookup(url);
        InterfaceRMI r2 = (InterfaceRMI) Naming.lookup(url);


        /// Creando hilos para hacer las multiplciaciones
        Worker WM[] = new Worker[36];
        for(int i = 0, j = 0; i < WM.length; i++, j++){
            if(j == 6){
                j = 0;
            }
            if(i < 6){
                WM[i] = new Worker(AM.get(0), BM.get(j), i, false, null);
            }
            if(i >= 6 && i < 12){
                WM[i] = new Worker(AM.get(1), BM.get(j), i, false, null);
            }
            if(i >= 12 && i < 18){
                WM[i] = new Worker(AM.get(2), BM.get(j), i, true, r);
            }
            if(i >= 18 && i < 24){
                WM[i] = new Worker(AM.get(3), BM.get(j), i, true, r);
            }
            if(i >= 24 && i < 30){
                WM[i] = new Worker(AM.get(4), BM.get(j), i, true, r2);
            }
            if(i >= 30 && i < 36){
                WM[i] = new Worker(AM.get(5), BM.get(j), i, true, r2);
            }

        }
        for(int i = 0; i < WM.length; i++){
            WM[i].start();
        }
        for(int i = 0; i < WM.length; i++){
            WM[i].join();
        }

        List<double[][]> CM = new ArrayList<>();
        for(int i = 0; i < 36; i++){
            CM.add(WM[i].Cx);
        }

/*
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

        //InterfaceRMI r = (InterfaceRMI) Naming.lookup(url);
       // InterfaceRMI r2 = (InterfaceRMI) Naming.lookup(url);

        //// Calculando matrices C13 ... C24
        double[][] C13 = multiplica_matrices(A3, B1, N, M);
        double[][] C14 = multiplica_matrices(A3, B2, N, M);
        double[][] C15 = multiplica_matrices(A3, B3, N, M);
        double[][] C16 = multiplica_matrices(A3, B4, N, M);
        double[][] C17 = multiplica_matrices(A3, B5, N, M);
        double[][] C18 = multiplica_matrices(A3, B6, N, M);
        double[][] C19 = multiplica_matrices(A4, B1, N, M);
        double[][] C20 = multiplica_matrices(A4, B2, N, M);
        double[][] C21 = multiplica_matrices(A4, B3, N, M);
        double[][] C22 = multiplica_matrices(A4, B4, N, M);
        double[][] C23 = multiplica_matrices(A4, B5, N, M);
        double[][] C24 = multiplica_matrices(A4, B6, N, M);

        //// Calculando matrices C25 ... C36
        double[][] C25 = multiplica_matrices(A5, B1, N, M);
        double[][] C26 = multiplica_matrices(A5, B2, N, M);
        double[][] C27 = multiplica_matrices(A5, B3, N, M);
        double[][] C28 = multiplica_matrices(A5, B4, N, M);
        double[][] C29 = multiplica_matrices(A5, B5, N, M);
        double[][] C30 = multiplica_matrices(A5, B6, N, M);
        double[][] C31 = multiplica_matrices(A6, B1, N, M);
        double[][] C32 = multiplica_matrices(A6, B2, N, M);
        double[][] C33 = multiplica_matrices(A6, B3, N, M);
        double[][] C34 = multiplica_matrices(A6, B4, N, M);
        double[][] C35 = multiplica_matrices(A6, B5, N, M);
        double[][] C36 = multiplica_matrices(A6, B6, N, M);

 */
        /// Juntando las matrices
        acomoda_matriz(C, CM.get(0), 0, 0, N);
        acomoda_matriz(C, CM.get(1), 0, N/6, N);
        acomoda_matriz(C, CM.get(2), 0, N/3, N);
        acomoda_matriz(C, CM.get(3), 0, N/2, N);
        acomoda_matriz(C, CM.get(4), 0, N*2/3, N);
        acomoda_matriz(C, CM.get(5), 0, N*5/6, N);

        acomoda_matriz(C, CM.get(6), N/6, 0, N);
        acomoda_matriz(C, CM.get(7), N/6, N/6, N);
        acomoda_matriz(C, CM.get(8), N/6, N/3, N);
        acomoda_matriz(C, CM.get(9), N/6, N/2, N);
        acomoda_matriz(C, CM.get(10), N/6, N*2/3, N);
        acomoda_matriz(C, CM.get(11), N/6, N*5/6, N);

        acomoda_matriz(C, CM.get(12), N/3, 0, N);
        acomoda_matriz(C, CM.get(13), N/3, N/6, N);
        acomoda_matriz(C, CM.get(14), N/3, N/3, N);
        acomoda_matriz(C, CM.get(15), N/3, N/2, N);
        acomoda_matriz(C, CM.get(16), N/3, N*2/3, N);
        acomoda_matriz(C, CM.get(17), N/3, N*5/6, N);

        acomoda_matriz(C, CM.get(18), N/2, 0, N);
        acomoda_matriz(C, CM.get(19), N/2, N/6, N);
        acomoda_matriz(C, CM.get(20), N/2, N/3, N);
        acomoda_matriz(C, CM.get(21), N/2, N/2, N);
        acomoda_matriz(C, CM.get(22), N/2, N*2/3, N);
        acomoda_matriz(C, CM.get(23), N/2, N*5/6, N);

        acomoda_matriz(C, CM.get(24), N*2/3, 0, N);
        acomoda_matriz(C, CM.get(25), N*2/3, N/6, N);
        acomoda_matriz(C, CM.get(26), N*2/3, N/3, N);
        acomoda_matriz(C, CM.get(27), N*2/3, N/2, N);
        acomoda_matriz(C, CM.get(28), N*2/3, N*2/3, N);
        acomoda_matriz(C, CM.get(29), N*2/3, N*5/6, N);

        acomoda_matriz(C, CM.get(30), N*5/6, 0, N);
        acomoda_matriz(C, CM.get(31), N*5/6, N/6, N);
        acomoda_matriz(C, CM.get(32), N*5/6, N/3, N);
        acomoda_matriz(C, CM.get(33), N*5/6, N/2, N);
        acomoda_matriz(C, CM.get(34), N*5/6, N*2/3, N);
        acomoda_matriz(C, CM.get(35), N*5/6, N*5/6, N);

        if(N == 6 && M == 5){

            System.out.println("Matriz C");
            imprimirMatriz(C, N, N);
        }
        /// Calculando el checksum
        calcularChecksum(C, N);


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
    static void calcularChecksum(double  matriz[][], int N){
        float checksum = 0;
        for (int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
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

    static void acomoda_matriz(double[][]C, double[][] A, int renglon, int columna, int N){
        for(int i = 0; i  < N / 6; i++){
            for(int j = 0; j < N / 6; j++){
                C[i+ renglon][j + columna] = A[i][j];
            }
        }
    }
}
