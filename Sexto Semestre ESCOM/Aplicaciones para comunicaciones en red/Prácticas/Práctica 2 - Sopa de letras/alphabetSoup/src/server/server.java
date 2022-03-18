
package server;

import static client.Client.sendDif;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import soup.Soup;

/**
 *
 * @author BrandMV
 */
public class server {

    private static int pto = 4444;
    private static InetAddress dst;
    private static int max = 65535;
    private static DatagramSocket s;
    private static Scanner scan;
    private static String[] words;
    private static String userName;
    private static String[][] soupToSend;
    private static String path = "C:\\Users\\PC\\Desktop\\6to Semestre ESCOM\\Aplicaciones para comunicaciones en red\\Prácticas\\Práctica 2 - Sopa de letras\\alphabetSoup\\src\\client\\";
    private static ObjectOutputStream oos;
    private static ByteArrayOutputStream baos;
    private static File records;
    private static String topic;
    private static String difficulty;
    
    public static void main(String[] args) {
        connectGame();
    }

    /**
     * @brief Method that makes the connection with the client and wait for connections
     * @param 
     * @return 
     */
    public static void connectGame() {
        try {
            s = new DatagramSocket(pto);
            s.setReuseAddress(true);
            System.out.println("Server Iniciado");
            //*Forever to recieve datagrams
            for (;;) {
                DatagramPacket p = new DatagramPacket(new byte[max], max);
                //*Recieving client username
                s.receive(p);
                userName = new String(p.getData(), 0, p.getLength());
                System.err.println(userName + " Conectado");
                //*Creating client connection
                s.connect(p.getSocketAddress());
                Integer opt = 1;
                
                while(opt == 1){
                    setDifficulty();
                    setConcept();
                    createSoup(words);
                    recvElapsedTime();
                    sendUserTimes();
                    p = new DatagramPacket(new byte[max], max);
                    s.receive(p);
                    DataInputStream dis = new DataInputStream(new ByteArrayInputStream(p.getData()));
                    opt = dis.readInt();
                }

                s.close();

            }
        } catch (Exception e) {
           
        }
    }

    /**
     * @brief Method that recieves the difficult set by the client
     * @param 
     * @return 
     */
    public static void setDifficulty(){
        try {
            DatagramPacket p = new DatagramPacket(new byte[max], max);
            s.receive(p);
            DataInputStream dis = new DataInputStream(new ByteArrayInputStream(p.getData()));
            int opt = dis.readInt();
              switch(opt){
            case 1:
                difficulty = "facil";
                System.out.println("Dificultad: " + difficulty);
                break;
            case 2:
                difficulty = "medio";
                System.out.println("Dificultad: " + difficulty);
                break;
            case 3:
                difficulty = "dificil";
                System.out.println("Dificultad: " + difficulty);
                break;
            default:
                difficulty = "facil";
                System.out.println("Dificultad: " + difficulty);
                break;
        }
        } catch (Exception e) {
            System.err.println("No se pudo recibir la dificultad");
        }
        
    }
    
    /**
     * @brief Method that set the concept choosen by the client
     * @param 
     * @return 
     */
    public static void setConcept() {
        try {
            DatagramPacket p = new DatagramPacket(new byte[max], max);
            s.receive(p);
            DataInputStream dis = new DataInputStream(new ByteArrayInputStream(p.getData()));
            int opt = dis.readInt();
            dst = p.getAddress();
            switch (opt) {
                case 1:
                    System.out.println("Tecnologia seleccionado");
                    getConceptWords("tec.txt");
                    topic = "tecnologia";
//                    createSoup(words);
                    
                    break;
                case 2:
                    System.out.println("Animales seleccionado");
                    getConceptWords("ani.txt");
                    topic = "animales";
                    break;
                case 3:
                    System.out.println("Matematicas seleccionado");
                    getConceptWords("mate.txt");
                    topic = "matematicas";
                    break;
                default:
                    break;
            }
        } catch (Exception e) {
        }
    }

    /**
     * @brief Method that get the words from a file according to the concept the client had choosen before
     * @param {String} filename the filename that contains the word
     * @throws IOException 
     */
    public static void getConceptWords(String filename) throws IOException {
        Integer i = 0;
    
        try{
              scan = new Scanner(new File(path+filename));
              words = new String[15];
              while(i < words.length){
                  //*Reading word from file
                  String line = scan.nextLine();
      //            System.out.println(i + " " + line);
                  //*Saving words
                  words[i] = line;
                              //*Sending words to client
                  baos = new ByteArrayOutputStream();
                  oos = new ObjectOutputStream(baos);
                  oos.writeObject(words[i]);
                  oos.flush();
                  byte[] buff = baos.toByteArray();
                  baos.flush();
                  DatagramPacket packet = new DatagramPacket(buff, buff.length);
                  s.send(packet);

      //            System.out.println(i + " " + words[i]);
                  i++;
              }

      //            System.out.println("Sending words");

              }catch(Exception e){
                  System.err.println("No se pudieron enviar palabras als ervidor");
              }
    }
    
    /**
     * @brief Method that creates the soup and send it to the user
     * @param {String[]} words The words that are gonna be included in the soup
     * @return 
     */
    public static void createSoup(String[] words){
        Soup so = new Soup(15, 15, words);
        so.setSoup();
        so.fillSoup();
 
        soupToSend = new String[15][15];
        soupToSend = so.getSoup();
        //*Sending the created soup to the client
        try {
            for (int i = 0 ; i<soupToSend.length;i++){
            
                for (int j = 0; j<soupToSend[0].length;j++){
                    if (j!=soupToSend[0].length){
                        baos = new ByteArrayOutputStream();
                        oos = new ObjectOutputStream(baos);
                        oos.writeObject(soupToSend[i][j]);
                        oos.flush();
                        byte[] buff = baos.toByteArray();
                        baos.flush();
                        DatagramPacket packet = new DatagramPacket(buff, buff.length);
                        s.send(packet);
                    }

                }
          
            } 
        } catch (Exception e) {
        }

    }
      
    /**
     * @brief Method that recieves the user elapsed time
     * @param 
     * @return 
     */
    public static void recvElapsedTime(){
         
        records = new File("C:\\Users\\PC\\Desktop\\6to Semestre ESCOM\\Aplicaciones para comunicaciones en red\\Prácticas\\Práctica 2 - Sopa de letras\\alphabetSoup\\src\\server\\records.txt");
        
        try {
            
            DatagramPacket p = new DatagramPacket(new byte[max], max);
            s.receive(p);
            DataInputStream dis = new DataInputStream(new ByteArrayInputStream(p.getData()));
            double elapsedTime = dis.readDouble();
            System.err.println("Jugador " + userName + " tardo " + elapsedTime);
                    
            //*Writing record in 
            FileWriter fw = new FileWriter(records, true);
            BufferedWriter bw = new BufferedWriter(fw);
            
            bw.write(userName + ": " + String.valueOf(elapsedTime) + " minutos - " + topic + " - " + difficulty);
            bw.newLine();
            
            bw.close();
            fw.close();
            
        } catch (Exception e) {
            System.err.println("No se pudo recibir el tiempo del usuario");
        } 
    }
    
    /**
     * @brief Method that send the other user times to the current player
     * @param 
     * @return
     */
    public static void sendUserTimes(){
        try {
            Integer i = 0;
            scan = new Scanner(new File("C:\\Users\\PC\\Desktop\\6to Semestre ESCOM\\Aplicaciones para comunicaciones en red\\Prácticas\\Práctica 2 - Sopa de letras\\alphabetSoup\\src\\server\\records.txt"));
            List<String> usersTimes = new ArrayList<String>();
            
            while(scan.hasNextLine()){
                //*Reading time from file
                String line = scan.nextLine();

                //*Saving times
                usersTimes.add(line);
                //*Sending user times to client
                
            } 
            //*Sending size
            baos = new ByteArrayOutputStream();
            oos = new ObjectOutputStream(baos);

            oos.writeInt(usersTimes.size());
            oos.flush();
            byte[] buff = baos.toByteArray();
            baos.flush();
            DatagramPacket packet = new DatagramPacket(buff, buff.length);
            s.send(packet);
            
            while(i < usersTimes.size()){
                baos = new ByteArrayOutputStream();
                oos = new ObjectOutputStream(baos);
              
                oos.writeObject(usersTimes.get(i));
                oos.flush();
                buff = baos.toByteArray();
                baos.flush();
                packet = new DatagramPacket(buff, buff.length);
                s.send(packet);

//                System.out.println(i + " " + usersTimes.get(i));
                i++;
            }
        } catch (Exception e) {
            System.err.println("No se pudo enviar los tiempos de cada usuario");
        }
        
    }

}
