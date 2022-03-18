
package client;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;
import soup.Soup;

/**
 *
 * @author BrandMV
 */
public class Client {
    
    //*Color Constants
    public static final String ANSI_RESET = "\u001B[0m";
    public static final String ANSI_BLACK = "\u001B[30m";
    public static final String ANSI_RED = "\u001B[31m";
    public static final String ANSI_GREEN = "\u001B[32m";
    public static final String ANSI_YELLOW = "\u001B[33m";
    public static final String ANSI_BLUE = "\u001B[34m";
    public static final String ANSI_PURPLE = "\u001B[35m";
    public static final String ANSI_CYAN = "\u001B[36m";
    public static final String ANSI_WHITE = "\u001B[37m";
    
    private static String serverAddress = "127.0.0.1";
    private static int pto = 4444;
    private static Scanner scan = new Scanner(System.in);
    private static InetAddress dst;
    private static DatagramSocket cl;
    private static Integer max = 65525;
    private static String[][] soup;
    private static String[] words;
//    private static Soup s;
    private static DatagramPacket p;
    private static Soup sO = new Soup();
    private static List<String> listWords;
    private static Integer difficulty;
    
    public static void main(String[] args) {
        System.out.println("**********  SOPA DE LETAS   **********");
        connectGame();
        Integer ans = 1;
        
        while(ans == 1){
            initGame();
            recvSoup();
            sO.showSoup(soup);
            searchWords();
            recvElapsedTimes();
            System.out.println("Jugar de nuevo? 1 - si / 0 - no");
            ans = scan.nextInt();  
            try {
              ByteArrayOutputStream baos = new ByteArrayOutputStream();
                DataOutputStream dos = new DataOutputStream(baos);
                dos.writeInt(ans);
                byte[] b = baos.toByteArray();
                p = new DatagramPacket(b, b.length, dst, pto);
                cl.send(p);  
            } catch (Exception e) {
                System.out.println("No se pudo conectar al servidor");
            }
        }
    }
    
    /**
     * @brief Method that connect the client with the server si the client start playinh
     * @param 
     * @return 
     */
    public static void connectGame(){
        String name;
        
        System.err.println("Introduzca su nombre para empezar a jugar");
        name = scan.nextLine();
        try {
            //*Datagram for client
            cl = new DatagramSocket();
            cl.setReuseAddress(true);
            byte[] b = name.getBytes(); //*Getting bytes of the client name
            dst = InetAddress.getByName(serverAddress);
            //*Creating packet
            DatagramPacket userName = new DatagramPacket(b, b.length, dst, pto);
            cl.send(userName);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    /**
     * @brief Method the game
     * @param
     * @return 
     */
    public static void initGame(){
        setDifficulty();
        try {
            System.out.println("Escribe el nùmero del concepto para generar sopa de letas");
            System.out.println("1 - Tecnología");
            System.out.println("2 - Animales");
            System.out.println("3 - Matemáticas");
            
            //*Sending concept option
            Integer opt = scan.nextInt();
            scan.nextLine();
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            DataOutputStream dos = new DataOutputStream(baos);
            dos.writeInt(opt);
            byte[] b = baos.toByteArray();
            p = new DatagramPacket(b, b.length, dst, pto);
            cl.send(p);
            
            b = new byte[max];
            p = new DatagramPacket(b, max, dst, pto);
            System.out.println("Reciveing words");
            
            listWords = new ArrayList<String>();
            //*Recieving words
            words = new String[15];
            for(int  i = 0; i < 15; i++){
                cl.receive(p);
                ByteArrayInputStream bais = new ByteArrayInputStream(p.getData());
                ObjectInputStream ois = new ObjectInputStream(bais);
                words[i] = (String) ois.readObject();
                listWords.add(words[i]);
                ois.close();
            }
           
            showWords(listWords);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    /**
     * @brief Method that sets the game difficulty easy, medium or hard 
     * @param 
     * @return 
     */
    public static void setDifficulty(){
        System.out.println("Selecciona la dificultad");
        System.out.println("1 - Fácil: Encontrar 5 palabras en la sopa");
        System.out.println("2 - Medio: Encontrar 10 palabras en la sopa");
        System.out.println("3 - Difícil: Encontrar 15 palabras en la sopa");
        Integer opt = scan.nextInt();
        scan.nextLine();
        switch(opt){
            case 1:
                difficulty = 5;
                sendDif(opt);
                break;
            case 2:
                difficulty = 10;
                sendDif(opt);
                break;
            case 3:
                difficulty = 15;
                sendDif(opt);
                break;
            default:
                difficulty = 5;
                sendDif(opt);
                break;
        }
    }
    
    /**
     * @brief Method that sends the difficult to the server
     * @param {Integer} difi the difficult option set by the client
     * @return 
     */
    public static void sendDif(Integer difi){
        try {
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            DataOutputStream dos = new DataOutputStream(baos);
            dos.writeInt(difi);
            byte[] b = baos.toByteArray();
            p = new DatagramPacket(b, b.length, dst, pto);
            cl.send(p);
        } catch (Exception e) {
            System.err.println("No se pudo mandar la dificultad");
        }
    }
    
    /**
     * @brief Method that show the rest of the words that the user can search
     * @param listWords 
     */
    public static void showWords(List<String> listWords){
        System.out.println(ANSI_PURPLE + "Palabras a encontrar en la sopa" + ANSI_RESET);
        for(String word : listWords)
            System.out.println(ANSI_PURPLE + listWords.indexOf(word)+ " - " + word + ANSI_RESET);
        
    }
    
    /**
     * @brief Method that recieves the soup created by the server
     * @param
     * @return
     */
    public static void recvSoup(){
        try {
           soup = new String[15][15];
           byte[] b = new byte[max];
            p = new DatagramPacket(b, max, dst, pto);
           for (int i = 0 ; i<soup.length;i++){
                for (int j = 0; j<soup[0].length;j++){
                    if (j!=soup[0].length){
                        cl.receive(p);
                        ByteArrayInputStream bais = new ByteArrayInputStream(p.getData());
                        ObjectInputStream ois = new ObjectInputStream(bais);
                        soup[i][j] = (String) ois.readObject();
                    }
                }
            } 
        } catch (Exception e) {
            System.err.println("No se pudo recibir la sopa del servidor");
        }
    }
    
    /**
     * @brief Method that search for the words the user wanna search
     * @param 
     * @return 
     */
    public static void searchWords(){
        System.out.println("");
        Integer correct = 0;
        Scanner coord = new Scanner(System.in);
        boolean found = false;
        long initTime;
        long endTime;
        
        List<String> wordsFound = new ArrayList<String>();
        //*Checkind the time the user began to solve the soup
        initTime = System.nanoTime();
        
        while(correct != difficulty){
            System.out.println("Ingrese el numero de la palabra a buscar");
            Integer indexWord = scan.nextInt();
            
            if(indexWord < listWords.size()){
//                String wordToSearch = words[indexWord];
                String wordToSearch = listWords.get(indexWord);
            
                //*Veryfying if word has been already found
                if(wordsFound.contains(wordToSearch)){
                    System.err.println("Palabra ya encontrada, trate con otra"); 
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException ex) {
                        Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
                    }
               }else{
                    System.out.println("Ingrese la coordenada (i,j) de inicio y fin de la palabra que quieres buscar en la sopa");
                    System.out.println(ANSI_BLUE + "Coordenada de inicio" + ANSI_RESET);
                    System.out.print("i: ");
                    Integer i1 = coord.nextInt();
                    coord.nextLine();
                    System.out.println("");
                    System.out.print("j: ");
                    Integer j1 = coord.nextInt();
                    coord.nextLine();
                    System.out.println(ANSI_BLUE + "Coordenada de fin" + ANSI_RESET);
                    System.out.print("i: ");
                    Integer i2 = coord.nextInt();
                    coord.nextLine();
                    System.out.println("");
                    System.out.print("j: ");
                    Integer j2 = coord.nextInt();
                    coord.nextLine();
                    System.out.println("");

                    //*Searching if word is horizontal
                    if(i1 == i2 && j2 > j1){
                        for(Integer l = 0, m = j1; m <= j2 && l < wordToSearch.length(); l++, m++){
        //                    System.out.println("Sopa " + soup[i1][m] + " palabra " + wordToSearch.charAt(l) );
                            if(soup[i1][m].equals(""+wordToSearch.charAt(l))){
                                found = true;
                                wordsFound.add(wordToSearch);
                                listWords.remove(wordToSearch);
                            } else {
                                System.err.println("Palabra no encontrada, trate con otra");
                                found = false;
                                break;
                            }
                        }
                        if(found)
                            correct++;
                    }
                    //*Searching if word is inverted horizontal
                    if(i1 == i2 && j1 > j2){
                        for(Integer l = 0, m = j1; m >= j2 && l < wordToSearch.length(); l++, m--){
        //                    System.out.println("Sopa " + soup[i1][m] + " palabra " + wordToSearch.charAt(l) );
                            if(soup[i1][m].equals(""+wordToSearch.charAt(l))){
                                wordsFound.add(wordToSearch);
                                listWords.remove(wordToSearch);
                                found = true;
                            } else {
                                System.err.println("Palabra no encontrada, pruebe de nuevo");
                                found = false;
                                break;
                            }
                        }
                        if(found)
                            correct++;
                    }

                    //*Searching if word is vertical
                    if(j1 == j2 && i2 > i1){
                        for(Integer l = 0, m = i1; m <= i2 && l < wordToSearch.length(); l++, m++){
        //                    System.out.println("Sopa " + soup[m][j1+ " palabra " + wordToSearch.charAt(l) );

                            if(soup[m][j1].equals(""+wordToSearch.charAt(l))){
                                wordsFound.add(wordToSearch);
                                listWords.remove(wordToSearch);
                                found = true;
                            } else {
                                System.err.println("Palabra no encontrada, pruebe de nuevo");
                                found = false;
                                break;
                            }
                        }

                        if(found)
                            correct++;
                    }

                    //*Searching if word is inverted vertical
                    if(j1 == j2 && i1 > i2){
                        for(Integer l = 0, m = i1; m >= i2 && l < wordToSearch.length(); l++, m--){
        //                    System.out.println("Sopa " + soup[i1][m] + " palabra " + wordToSearch.charAt(l) );
                            if(soup[m][j1].equals(""+wordToSearch.charAt(l))){
                                wordsFound.add(wordToSearch);
                                listWords.remove(wordToSearch);
                                found = true;
                            } else {
                                System.err.println("Palabra no encontrada, pruebe de nuevo");
                                found = false;
                                break;
                            }
                        }
                        if(found)
                            correct++;
                    }

                    //*Searching if word is right diagonal
                    if(j2 > j1 && i1 > i2){
                        for(Integer l = 0, m = i1, n = j1; m >= i2 && n <= j2 && l < wordToSearch.length(); l++, m--, n++){
        //                    System.out.println("Sopa " + soup[m][n] + " palabra " + wordToSearch.charAt(l) );
                            if(soup[m][n].equals(""+wordToSearch.charAt(l))){
                                found = true;
                                wordsFound.add(wordToSearch);
                                listWords.remove(wordToSearch);
                            } else {
                                System.err.println("Palabra no encontrada, pruebe de nuevo");
                                found = false;
                                break;
                            }
                        }
                        if(found)
                            correct++;
                    }

                    //*Searching if word is left diagonal downS
                    if(i2 > i1 && j1 > j2){
                        for(Integer l = 0, m = i1, n = j1; m <= i2 && n >= j2 && l < wordToSearch.length(); l++, m++, n--){
        //                    System.out.println("Sopa " + soup[m][n] + " palabra " + wordToSearch.charAt(l) );
                            if(soup[m][n].equals(""+wordToSearch.charAt(l))){
                                found = true;
                                wordsFound.add(wordToSearch);
                                listWords.remove(wordToSearch);
                            } else {
                                System.err.println("Palabra no encontrada, pruebe de nuevo");
                                found = false;
                                break;
                            }
                        }
                        if(found)
                            correct++;
                    }

                    //*Searching if word is left diagonal 
                    if(i1 > i2 && j1 > j2){
                        for(Integer l = 0, m = i1, n = j1; m >= i2 && n >= j2 && l < wordToSearch.length(); l++, m--, n--){
        //                    System.out.println("Sopa " + soup[m][n] + " palabra " + wordToSearch.charAt(l) );
                            if(soup[m][n].equals(""+wordToSearch.charAt(l))){
                                found = true;
                                wordsFound.add(wordToSearch);
                                listWords.remove(wordToSearch);
                            } else {
                                System.err.println("Palabra no encontrada, pruebe de nuevo");
                                found = false;
                                break;
                            }
                        }
                        if(found)
                            correct++;
                    }

                    //*Searching if word is right diagonal down 
                    if(i2 > i1 && j2 > j1){
                        for(Integer l = 0, m = i1, n = j1; m <= i2 && n <= j2 && l < wordToSearch.length(); l++, m++, n++){
        //                    System.out.println("Sopa " + soup[m][n] + " palabra " + wordToSearch.charAt(l) );
                            if(soup[m][n].equals(""+wordToSearch.charAt(l))){
                                found = true;
                                wordsFound.add(wordToSearch);
                                listWords.remove(wordToSearch);
                            } else {
                                System.err.println("Palabra no encontrada, pruebe de nuevo");
                                found = false;
                                break;
                            }
                        }
                        if(found)
                            correct++;
                    }

                    System.out.println("Palabras encontradas " + correct + " restantes " + (difficulty - correct));
                    showWords(listWords);
                    sO.showSoup(soup);
                } 
            }else{
                System.err.println("Palabra no valida, pruebe con otra"); 
                try {
                    Thread.sleep(300);
                } catch (InterruptedException ex) {
                    Logger.getLogger(Client.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
 
        }
        //*Checkinf the time the user finished solving the soup
        endTime = System.nanoTime();
        sendSolveTime(initTime, endTime);
    }
    
    /**
     * @brief Method that send the time to the client it take to the user to solve the soup
     * @param {long} ini the user initial time
     * @param {long} end the user final time  
     * @return 
     */
    public static void sendSolveTime(long ini, long end){
        long totalTime;
        
        //*Calculating total Time in nanosecs
        totalTime = end - ini;

        double elapsedTimeInSecond = (double) totalTime / 1_000_000_000;
        double elapsedTimeInMinute = (double) elapsedTimeInSecond / 60;

        System.err.println("Tu tiempo: " + elapsedTimeInMinute + " minutos");
        try {
            //*Sending time to server
            ByteArrayOutputStream baos = new ByteArrayOutputStream();
            DataOutputStream dos = new DataOutputStream(baos);
            dos.writeDouble(elapsedTimeInMinute);
            byte[] b = baos.toByteArray();
            p = new DatagramPacket(b, b.length, dst, pto);
            cl.send(p);
        } catch (Exception e) {
            System.err.println("No se puede enviar el tiempo");
        }
    }
    
    /**
     * @brief Method that recieves the other user times 
     * @param 
     * @return
     */
    public static void recvElapsedTimes(){
        try {
            byte[] b = new byte[max];
            p = new DatagramPacket(b, max, dst, pto);
//            System.out.println("Reciveing elapsed Time");
            
            //*Recieving times
            List<String> usersTimes = new ArrayList<String>();
            Integer listSize;
            cl.receive(p);
            ByteArrayInputStream bais = new ByteArrayInputStream(p.getData());
            ObjectInputStream ois = new ObjectInputStream(bais);
            listSize = ois.readInt();
            ois.close();
                
            for(Integer  i = 0; i < listSize; i++){
                cl.receive(p);
                bais = new ByteArrayInputStream(p.getData());
                ois = new ObjectInputStream(bais);
                usersTimes.add((String) ois.readObject());
                ois.close();
            }

            System.out.println(ANSI_PURPLE + "Tiempo de otros usuarios" + ANSI_RESET);
            for(String time : usersTimes)
                System.out.println(ANSI_PURPLE + time + ANSI_RESET);
//            for(int i = 0; i< usersTimes.size();i++)
//                System.out.println(ANSI_PURPLE + usersTimes.get(i) + ANSI_RESET);
           
        } catch (Exception e) {
            System.err.println("No se pudieron recibir los tiempos");
        }
    }
    
}
