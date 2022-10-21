import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;

public class Multiplica {
    static int N = 12;
    static float[][] A = new float[N][N];
    static float[][] B = new float[N][N];
    static float[][] C = new float[N][N];
    static float[][] Baux = new float[N][N];

    static float[][] A1 = new float[N / 4][N];
    static float[][] A2 = new float[N / 4][N];
    static float[][] A3 = new float[N / 4][N];
    static float[][] A4 = new float[N / 4][N];
    static float[][] B1 = new float[N / 4][N];
    static float[][] B2 = new float[N / 4][N];
    static float[][] B3 = new float[N / 4][N];
    static float[][] B4 = new float[N / 4][N];
    static float[][] C1 = new float[N/4][N/4];
    static float[][] C2 = new float[N/4][N/4];
    static float[][] C3 = new float[N/4][N/4];
    static float[][] C4 = new float[N/4][N/4];
    static float[][] C5 = new float[N/4][N/4];
    static float[][] C6 = new float[N/4][N/4];
    static float[][] C7 = new float[N/4][N/4];
    static float[][] C8 = new float[N/4][N/4];
    static float[][] C9 = new float[N/4][N/4];
    static float[][] C10 = new float[N/4][N/4];
    static float[][] C11 = new float[N/4][N/4];
    static float[][] C12 = new float[N/4][N/4];
    static float[][] C13 = new float[N/4][N/4];
    static float[][] C14 = new float[N/4][N/4];
    static float[][] C15 = new float[N/4][N/4];
    static float[][] C16 = new float[N/4][N/4];

    static class Worker extends Thread {
        float[][] Ax = new float[N / 4][N];
        float[][] BN = new float[N][N];
        float[][] CN1 = new float[N/4][N/4];
        float[][] CN2 = new float[N/4][N/4];
        float[][] CN3 = new float[N/4][N/4];
        float[][] CN4 = new float[N/4][N/4];

        int nodo, renglones, columnas, inicioRenglon;

        Worker(float[][] Ax, float[][] BN, int nodo, int inicioRenglon, int renglones, int columnas) {
            this.Ax = Ax;
            this.BN = BN;
            this.nodo = nodo;
            this.renglones = renglones;
            this.inicioRenglon = inicioRenglon;
            this.columnas = columnas;
        }

        public void run() {
            try {
                Socket conexion = null;
                for (; ; ) {
                    try {
                        conexion = new Socket("localhost", 60000 + nodo);
                        break;
                    } catch (Exception e) {
                        System.out.println("Reintentando conexion...");
                        Thread.sleep(100);
                    }
                }
                DataInputStream entrada = new DataInputStream(conexion.getInputStream());
                DataOutputStream salida = new DataOutputStream(conexion.getOutputStream());
                /// Mandando matrices
                // Ax
                enviarMatriz(salida, renglones, columnas, inicioRenglon, 0, A);

                // B1
                enviarMatriz(salida, N / 4, N, 0, 0, BN);

                // B2
                enviarMatriz(salida, N / 2, N, N / 4, 0, BN);

                // B3
                enviarMatriz(salida, N * 3 / 4, N, N / 2, 0, BN);

                // B4
                enviarMatriz(salida, N, N, N * 3 / 4, 0, BN);

                /// Recibiendo matrices Cx
                float[][] Cx1 = new float[N/4][N/4];
                Cx1 = recibirMatriz(entrada, N/4, N/4);
                this.CN1 = Cx1;

                float[][] Cx2 = new float[N/4][N/4];
                Cx2 = recibirMatriz(entrada, N/4, N/4);
                this.CN2 = Cx2;

                float[][] Cx3 = new float[N/4][N/4];
                Cx3 = recibirMatriz(entrada, N/4, N/4);
                this.CN3 = Cx3;

                float[][] Cx4 = new float[N/4][N/4];
                Cx4 = recibirMatriz(entrada, N/4, N/4);
                this.CN4 = Cx4;

                conexion.close();
            } catch (Exception e) {
                System.err.println(e.getMessage());
            }

        }
    }


    public static void main(String[] args) throws Exception {
        ServerSocket servidor = null;
        Socket conexion = null;
        DataOutputStream salida = null;
        DataInputStream entrada = null;

        if (args.length != 1) {
            System.out.println("Debe ingresar un nodo como argumento, ejemplo: java Multiplica 0");
            System.exit(0);
        }


        int nodo = Integer.valueOf(args[0]);
//        int nodo = 0;
        switch (nodo) {
            case 0:
                nodoCentral();
                break;
            case 1:
                float[][] Cx = new float[N/4][N/4];
                servidor = new ServerSocket(60000 + nodo);
                System.out.println("Nodo 1 iniciado");
                conexion = servidor.accept();
                salida = new DataOutputStream(conexion.getOutputStream());
                entrada = new DataInputStream(conexion.getInputStream());

                /// 1. Recibiendo A1
                A1 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz A1 recibida");
               // imprimirMatriz(A1, N / 4, N);

                /// 2. Recibiendo B1, B2, B3, B4
                // Recibiendo B1
                B1 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B1 recibida");
                //imprimirMatriz(B1, N / 4, N);

                // Recibiendo B2
                B2 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B2");
               // imprimirMatriz(B2, N / 4, N);

                // Recibiendo B3
                B3 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B3 recibida");
               // imprimirMatriz(B3, N / 4, N);

                // Recibiendo B4
                B4 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B4 recibida");
               // imprimirMatriz(B4, N / 4, N);
                /// Multiplicando matrices
                // Obteniendo C1
                Cx = multiplicarMatrices(A1, B1);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C2
                Cx = multiplicarMatrices(A1, B2);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C3
                Cx = multiplicarMatrices(A1, B3);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C4
                Cx = multiplicarMatrices(A1, B4);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);

                System.out.println("Matrices C1, C2, C3 y C4 enviadas");

                conexion.close();

                break;
            case 2:
                servidor = new ServerSocket(60000 + nodo);
                System.out.println("Nodo 2 iniciado");
                conexion = servidor.accept();
                salida = new DataOutputStream(conexion.getOutputStream());
                entrada = new DataInputStream(conexion.getInputStream());

                /// 1. Recibiendo A2
                A2 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz A2 recibida");
              //  imprimirMatriz(A2, N / 4, N);

                /// 2. Recibiendo B1, B2, B3, B4
                // Recibiendo B1
                B1 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B1 recibida");
               // imprimirMatriz(B1, N / 4, N);

                // Recibiendo B2
                B2 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B2");
              //  imprimirMatriz(B2, N / 4, N);

                // Recibiendo B3
                B3 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B3 recibida");
              //  imprimirMatriz(B3, N / 4, N);

                // Recibiendo B4
                B4 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B4 recibida");
               // imprimirMatriz(B4, N / 4, N);

                /// Multiplicando matrices
                // Obteniendo C5
                Cx = multiplicarMatrices(A2, B1);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C6
                Cx = multiplicarMatrices(A2, B2);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C7
                Cx = multiplicarMatrices(A2, B3);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C8
                Cx = multiplicarMatrices(A2, B4);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                System.out.println("Matrices C5, C6, C7, C8 enviadas");

                conexion.close();
                break;
            case 3:
                servidor = new ServerSocket(60000 + nodo);
                System.out.println("Nodo 3 iniciado");
                conexion = servidor.accept();
                salida = new DataOutputStream(conexion.getOutputStream());
                entrada = new DataInputStream(conexion.getInputStream());

                /// 1. Recibiendo A3
                A3 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz A3 recibida");
               // imprimirMatriz(A3, N / 4, N);

                /// 2. Recibiendo B1, B2, B3, B4
                // Recibiendo B1
                B1 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B1 recibida");
               // imprimirMatriz(B1, N / 4, N);

                // Recibiendo B2
                B2 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B2 recibida");
              //  imprimirMatriz(B2, N / 4, N);

                // Recibiendo B3
                B3 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B3 recibida");
              //  imprimirMatriz(B3, N / 4, N);

                // Recibiendo B4
                B4 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B4 recibida");
               // imprimirMatriz(B4, N / 4, N);

                /// Multiplicando matrices
                // Obteniendo C9
                Cx = multiplicarMatrices(A3, B1);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C10
                Cx = multiplicarMatrices(A3, B2);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C11
                Cx = multiplicarMatrices(A3, B3);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C12
                Cx = multiplicarMatrices(A3, B4);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                System.out.println("Matrices C9, C10, C11, C12 enviadas");


                conexion.close();
                break;
            case 4:
                servidor = new ServerSocket(60000 + nodo);
                System.out.println("Nodo 4 iniciado");
                conexion = servidor.accept();
                salida = new DataOutputStream(conexion.getOutputStream());
                entrada = new DataInputStream(conexion.getInputStream());

                /// 1. Recibiendo A2
                A4 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz A4 recibida");
               // imprimirMatriz(A4, N / 4, N);

                /// 2. Recibiendo B1, B2, B3, B4
                // Recibiendo B1
                B1 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B1 recibida");
             //   imprimirMatriz(B1, N / 4, N);

                // Recibiendo B2
                B2 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B2 recibida");
               // imprimirMatriz(B2, N / 4, N);

                // Recibiendo B3
                B3 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B3 recibida");
               // imprimirMatriz(B3, N / 4, N);

                // Recibiendo B4
                B4 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B4 recibida");
               // imprimirMatriz(B4, N / 4, N);

                /// Multiplicando matrices
                // Obteniendo C13
                Cx = multiplicarMatrices(A4, B1);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C14
                Cx = multiplicarMatrices(A4, B2);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C15
                Cx = multiplicarMatrices(A4, B3);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                // Obteniendo C16
                Cx = multiplicarMatrices(A4, B4);
                enviarMatriz(salida, N/4, N/4, 0, 0, Cx);
                System.out.println("Matrices C13, C14, C15, C16 enviadas");

                conexion.close();
                break;
            default:
                System.out.println(" Ingrese un nodo válido (0-4)");
                break;
        }
    }

    public static void nodoCentral() throws Exception {

        /// 1. Inicializando matrices
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = i + 3 * j;
                B[i][j] = 2 * i - j;
            }
        }
        Baux = B;

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
        //System.out.println("Matriz B transpuesta:");
        //imprimirMatriz(B, N, N);

        /// Creando hilos
        Worker N1 = new Worker(A, B, 1, 0, N / 4, N);
        Worker N2 = new Worker(A, B, 2, N/4, N/2, N);
        Worker N3 = new Worker(A, B, 3, N/2, N*3/4, N);
        Worker N4 = new Worker(A, B, 4, N*3/4, N, N);

        /// Corriendo hilos
        N1.start();
        N2.start();
        N3.start();
        N4.start();

        /// Esperando hilos
        N1.join();
        N2.join();
        N3.join();
        N4.join();

        /// Obteniendo valores de C1 - C4 para construir C
        C1 = N1.CN1;
        C2 = N1.CN2;
        C3 = N1.CN3;
        C4 = N1.CN4;

        /// Obteniendo valores de C5 - C8 para construir C
        C5 = N2.CN1;
        C6 = N2.CN2;
        C7 = N2.CN3;
        C8 = N2.CN4;

        /// Obteniendo valores de C9 - C12 para construir C
        C9 = N3.CN1;
        C10 = N3.CN2;
        C11 = N3.CN3;
        C12 = N3.CN4;

        /// Obteniendo valores de C13 - C16 para construir C
        C13 = N4.CN1;
        C14 = N4.CN2;
        C15 = N4.CN3;
        C16 = N4.CN4;
        /// Construyendo C
        // Renglon 1
        for(int i = 0; i < C1.length; i++){
            for(int j = 0; j < C1[0].length; j++){
                C[i][j] = C1[i][j];
            }
        }
        for(int i = 0; i < C2.length; i++){
            for(int j = 0; j < C2[0].length; j++){
                C[i][j + C2[0].length] = C2[i][j];
            }
        }
        for(int i = 0; i < C3.length; i++){
            for(int j = 0; j < C3[0].length; j++){
                C[i][j + C3[0].length*2] = C3[i][j];
            }
        }
        for(int i = 0; i < C4.length; i++){
            for(int j = 0; j < C4[0].length; j++){
                C[i][j + C4[0].length*3] = C4[i][j];
            }
        }
        //Renglon 2
        for(int i = 0; i < C5.length; i++){
            for(int j = 0; j < C5[0].length; j++){
                C[i+C5[0].length][j] = C5[i][j];
            }
        }
        for(int i = 0; i < C6.length; i++){
            for(int j = 0; j < C6[0].length; j++){
                C[i+C6[0].length][j+C6[0].length] = C6[i][j];
            }
        }
        for(int i = 0; i < C7.length; i++){
            for(int j = 0; j < C7[0].length; j++){
                C[i+C7[0].length][j+C7[0].length*2] = C7[i][j];
            }
        }
        for(int i = 0; i < C8.length; i++){
            for(int j = 0; j < C8[0].length; j++){
                C[i+C8[0].length][j+C8[0].length*3] = C8[i][j];
            }
        }
        /// Renglon 3
        for(int i = 0; i < C9.length; i++){
            for(int j = 0; j < C9[0].length; j++){
                C[i+C9[0].length*2][j] = C9[i][j];
            }
        }
        for(int i = 0; i < C10.length; i++){
            for(int j = 0; j < C10[0].length; j++){
                C[i+C10[0].length*2][j+C10[0].length] = C10[i][j];
            }
        }
        for(int i = 0; i < C11.length; i++){
            for(int j = 0; j < C11[0].length; j++){
                C[i+C11[0].length*2][j+C11[0].length*2] = C11[i][j];
            }
        }
        for(int i = 0; i < C12.length; i++){
            for(int j = 0; j < C12[0].length; j++){
                C[i+C12[0].length*2][j+C12[0].length*3] = C12[i][j];
            }
        }
        /// Renglon 4
        for(int i = 0; i < C13.length; i++){
            for(int j = 0; j < C13[0].length; j++){
                C[i+C13[0].length*3][j] = C13[i][j];
            }
        }
        for(int i = 0; i < C14.length; i++){
            for(int j = 0; j < C14[0].length; j++){
                C[i+C14[0].length*3][j+C14[0].length] = C14[i][j];
            }
        }
        for(int i = 0; i < C15.length; i++){
            for(int j = 0; j < C15[0].length; j++){
                C[i+C15[0].length*3][j+C15[0].length*2] = C15[i][j];
            }
        }
        for(int i = 0; i < C16.length; i++){
            for(int j = 0; j < C16[0].length; j++){
                C[i+C16[0].length*3][j+C16[0].length*3] = C16[i][j];
            }
        }

        if(N == 12){
            System.out.println("Matriz A");
            imprimirMatriz(A, N, N);
            System.out.println("Matriz B");
            imprimirMatriz(Baux, N, N);
            System.out.println("Matriz C");
            imprimirMatriz(C, N, N);
        }

        /// 16. Calculando y mostrando checksum de la matriz C
        calcularChecksum(C, N);
       // imprimirMatriz(C, N, N);



    }

    static void enviarMatriz(DataOutputStream salida, int renglones, int columnas, int inicioR, int inicioC, float[][] matriz) throws Exception {
        for (int i = inicioR; i < renglones; i++) {
            for (int j = inicioC; j < columnas; j++) {
                float x = matriz[i][j];
                //b.putFloat(x);
                salida.writeFloat(x);
                //System.out.println("Elementos A1: " + x);
            }
        }
    }

    static float[][] recibirMatriz(DataInputStream entrada, int renglones, int columnas) throws Exception {
        float[][] matriz = new float[renglones][columnas];
        for (int i = 0; i < renglones; i++) {
            for (int j = 0; j < columnas; j++) {
                matriz[i][j] = entrada.readFloat();
            }
        }
        return matriz;
    }
    static float[][] multiplicarMatrices(float[][] Ax, float[][] Bx){
        float[][] Cx = new float[N/4][N/4];

        for (int i = 0; i < N/4; i++){
            for (int j = 0; j < N/4; j++){
                for (int k = 0; k < N; k++){
                    Cx[i][j] += Ax[i][k] * Bx[j][k];
                }
            }
        }
        return Cx;
    }

    static void imprimirMatriz(float m[][], int renglones, int columnas) {
        for (int i = 0; i < renglones; i++) {
            for (int j = 0; j < columnas; j++) {
                System.out.printf("%.2f ", m[i][j]);
            }
            System.out.println("");
        }
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

    public static void read(DataInputStream f, byte[] b, int posicion, int longitud) throws Exception {
        while (longitud > 0) {
            int n = f.read(b, posicion, longitud);
            posicion += n;
            longitud -= n;
        }
    }

    public static void formarMatrizC(float[][] Cx, int renglon, int columna){
        for(int i = 0; i < Cx.length; i++){
            for(int j = 0; j < Cx[0].length; j++){
                C[i+renglon][j+columna] = Cx[i][j];
            }
        }
    }
}
