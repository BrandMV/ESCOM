import javax.xml.crypto.Data;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;

public class Multiplica {
    static int N = 4;
    static float[][] A = new float[N][N];
    static float[][] B = new float[N][N];
    static float[][] C = new float[N][N];
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
                System.out.println("Matriz A1");
                imprimirMatriz(A1, N / 4, N);

                /// 2. Recibiendo B1, B2, B3, B4
                // Recibiendo B1
                B1 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B1");
                imprimirMatriz(B1, N / 4, N);

                // Recibiendo B2
                B2 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B2");
                imprimirMatriz(B2, N / 4, N);

                // Recibiendo B3
                B3 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B3");
                imprimirMatriz(B3, N / 4, N);

                // Recibiendo B4
                B4 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B4");
                imprimirMatriz(B4, N / 4, N);
                conexion.close();
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
                break;
            case 2:
                servidor = new ServerSocket(60000 + nodo);
                System.out.println("Nodo 2 iniciado");
                conexion = servidor.accept();
                salida = new DataOutputStream(conexion.getOutputStream());
                entrada = new DataInputStream(conexion.getInputStream());

                /// 1. Recibiendo A2
                A2 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz A2");
                imprimirMatriz(A2, N / 4, N);

                /// 2. Recibiendo B1, B2, B3, B4
                // Recibiendo B1
                B1 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B1");
                imprimirMatriz(B1, N / 4, N);

                // Recibiendo B2
                B2 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B2");
                imprimirMatriz(B2, N / 4, N);

                // Recibiendo B3
                B3 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B3");
                imprimirMatriz(B3, N / 4, N);

                // Recibiendo B4
                B4 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B4");
                imprimirMatriz(B4, N / 4, N);

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
                System.out.println("Matriz A3");
                imprimirMatriz(A3, N / 4, N);

                /// 2. Recibiendo B1, B2, B3, B4
                // Recibiendo B1
                B1 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B1");
                imprimirMatriz(B1, N / 4, N);

                // Recibiendo B2
                B2 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B2");
                imprimirMatriz(B2, N / 4, N);

                // Recibiendo B3
                B3 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B3");
                imprimirMatriz(B3, N / 4, N);

                // Recibiendo B4
                B4 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B4");
                imprimirMatriz(B4, N / 4, N);

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
                System.out.println("Matriz A4");
                imprimirMatriz(A4, N / 4, N);

                /// 2. Recibiendo B1, B2, B3, B4
                // Recibiendo B1
                B1 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B1");
                imprimirMatriz(B1, N / 4, N);

                // Recibiendo B2
                B2 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B2");
                imprimirMatriz(B2, N / 4, N);

                // Recibiendo B3
                B3 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B3");
                imprimirMatriz(B3, N / 4, N);

                // Recibiendo B4
                B4 = recibirMatriz(entrada, N / 4, N);
                System.out.println("Matriz B4");
                imprimirMatriz(B4, N / 4, N);

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
        System.out.println("Matriz A:");
        imprimirMatriz(A, N, N);
        System.out.println("Matriz B:");
        imprimirMatriz(B, N, N);

        /// 2. Transpuesta de B
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                float x = B[i][j];
                B[i][j] = B[j][i];
                B[j][i] = x;
            }
        }

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
                    C[i][j] += A[i][k] * B[j][k];
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

    public static void read(DataInputStream f, byte[] b, int posicion, int longitud) throws Exception {
        while (longitud > 0) {
            int n = f.read(b, posicion, longitud);
            posicion += n;
            longitud -= n;
        }
    }
}
