/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Server;

import static Client.Client.ANSI_GREEN;
import static Client.Client.ANSI_RESET;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.net.ServerSocket;
import java.net.Socket;
import javax.swing.JFileChooser;

/**
 *
 * @author BrandMV
 */
public class Server {
    private Integer pto;
    private Socket client;
    Integer isDownloadedCompleted;
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
    ServerSocket s = null, sop = null;
    String files_path;
    int i = 0;
    
    public static void main(String[] args) {
        Server ser = new Server(8000);
        ser.connect();
    }
    
    public Server(Integer pto){
        this.pto = pto;
    }   
    
    /*
    *@brief Method that stablishes the server and wait for client connections
    *@param no params
    *@return nothing
    */
    public void connect(){
        try {
            Integer op;
   
            System.err.println("Server connected!");
            System.out.println("Server waiting for files..");
            
            //*Creting the server folder
            File f = new File("");
            String path = f.getAbsolutePath();
            String folder = "ServerFiles";
            files_path = path + "\\" + folder + "\\";
            System.out.println("Server folder path: " + files_path);
            File f2 = new File(files_path);
            f2.mkdirs();
            f2.setWritable(true);
            
            //*Opening first serverSocket
            s = new ServerSocket(pto);
            s.setReuseAddress(true);
          
            
            //*Opening a second serverSocket for connections
            sop = new ServerSocket(pto+1000);
            sop.setReuseAddress(true);
            
            //*The server awaits for a client conecction 
            for(;;){
                //*Recieving the option (send or receive files)
                client = sop.accept();
                //*Nagle on
//                client.setTcpNoDelay(true);
                DataInputStream dis = new DataInputStream(client.getInputStream());
                op = dis.readInt();
                dis.close();
                client.close();
                
//                System.out.println("Operacion" + op);
                
                System.out.println(ANSI_BLUE + "Client connected from " + client.getInetAddress()+":" + client.getPort() + ANSI_RESET );
                
                if(op == 1){
                    //*Accepting connection
                    Socket client;
                    client = s.accept();
                    //*Receiving the file to recieve info
                    dis = new DataInputStream(client.getInputStream());
                    String name = dis.readUTF();
                    long size = dis.readLong();
                    boolean directory = dis.readBoolean();
                    //*Function that receives every from the client
                    recieveFiles(files_path, dis, size, name, directory);
                }else{
                    chooser();
//                    System.out.println("Finished");
                    //*Indicating when data transfer is completed
                    client = sop.accept();
                    //*Nagle algorithm
                    client.setTcpNoDelay(true);
                    DataOutputStream dos = new DataOutputStream(client.getOutputStream());
                    dos.writeInt(1);
                    dos.close();
                    client.close();    
                } 
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    
    /*
    *@brief Method that receives files or direcotries from the client
    *@param {String} dest The file/directory destination
    *@param {DataInputStream} dis
    *@param {long} size file/directory size
    *@param {String} name The file/directory name
    */
    public void recieveFiles(String dest, DataInputStream dis, long size, String name, Boolean directory){
        try {
            for(;;){
                //*Creating a file with the destination and file name
                File newFile = new File(dest+name);
                //*We use recursion to recieve files whic are folders
                if(directory){
                    File directoryDir = newFile.getParentFile();
                    while(directoryDir.getPath().contains(dest)){
                        directoryDir.mkdirs();
                        directoryDir.setWritable(true);
                        directoryDir = directoryDir.getParentFile();
                    }
                    newFile.createNewFile();
                }
                DataOutputStream dos = new DataOutputStream(new FileOutputStream(newFile));
                long receivedData = 0;
                int l = 0, percentage = 0;
                System.err.println("Receiving " + name + " " + size);

                //*Recieving file
                while(receivedData < size){
                    byte[] b = new byte[1500];
                    l = dis.read(b);
                    System.out.println("Read: " + l);
                    dos.write(b,0,l);
                    dos.flush();
                    receivedData = receivedData + l;
                    percentage = (int)((receivedData*100) / size);
                    System.out.println(ANSI_GREEN + "\rReceiving data; " + percentage + "%" + ANSI_RESET);
                }//*While end

                System.out.println(ANSI_PURPLE +  name + " recieved" + ANSI_RESET);
                //*Closing coneections
                dos.close();
                dis.close();
                client.close();
                break;
         } 
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /*@brief Method that sends the spicified files to our client
     *@param {File[]} currentFiles Files to be sent to the client
     *@param {String} directoryName The folder name
     *@param {boolean} directory Wether if the file is a directory or not
     *@return 
    */
    public void sendFiles(File [] currentFiles, String directoryName, boolean directory){
        try {
            for(File fileToSend : currentFiles){
                if(fileToSend.isDirectory()){
                    directoryName += directory ? "/" : ""; 
                    sendFiles(fileToSend.listFiles(), directoryName+fileToSend.getName(), true);
                   
                }else{
                    String currentName = directory ? directoryName + "/" + fileToSend.getName() : fileToSend.getName();
                    String currentPath = fileToSend.getAbsolutePath();
                    long currentSize = fileToSend.length();

                    System.out.println("Sending file " + currentName + " with size " + currentSize + " bytes");

                    DataInputStream dis = new DataInputStream(new FileInputStream(currentPath));
                    
                    //*Sending if the data transfer is compelted (in this case isn't)
                    client = sop.accept();
                    DataOutputStream dos = new DataOutputStream(client.getOutputStream());
                    dos.writeInt(0);
                    dos.close();
                    client.close();
                    
                    //*File info
                    Socket client = s.accept();
                    dos = new DataOutputStream(client.getOutputStream());
                    dos.writeUTF(currentName);
                    dos.flush();
                    dos.writeLong(currentSize);
                    dos.flush();
                    dos.writeBoolean(directory);
                    dos.flush();

                    //*Sending file proccess
                    long currentSent = 0;
                    int l = 0, currentPercentage = 0;
                    System.out.println("Sending...");
                    while(currentSent  < currentSize){
                        byte[] b = new byte[1500];
                        l = dis.read(b);
                        System.out.println("Sent " + l);
                        dos.write(b,0,l);
                        dos.flush();
                        currentSent = currentSent + l;
                        currentPercentage = (int)((currentSent*100) / currentSize);
                        System.out.println(ANSI_GREEN + "\rSending data; " + currentPercentage + "%" + ANSI_RESET);

                    } //*While end

                    System.err.println(currentName + " sent");
                    dis.close();
                    dos.close();
                    client.close(); 
                }
            }
            
        } catch (Exception e) {
            e.printStackTrace();
        }
      
    }
    
    /*@brief Method that opens the file chooser to select files the cliente wanna download
     *@param 
     *@return
    */
    public void chooser() throws FileNotFoundException, IOException{
            
    //*Opengin file chooser
        JFileChooser jf = new JFileChooser();
        jf.setCurrentDirectory(new File(files_path));
        jf.setMultiSelectionEnabled(true);
        jf.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);

        int r = jf.showOpenDialog(null);
        jf.setRequestFocusEnabled(true);

        if(r == JFileChooser.APPROVE_OPTION){
            Socket cho = sop.accept();
            DataOutputStream chod = new DataOutputStream(cho.getOutputStream());
            File[] files = jf.getSelectedFiles();
            chod.writeInt(0);
            chod.flush();
            cho.close();
            sendFiles(files, "", false);
         } else if(r == JFileChooser.CANCEL_OPTION){
         Socket cho = sop.accept();
            DataOutputStream chod = new DataOutputStream(cho.getOutputStream());
            chod.writeInt(1);
            chod.flush();
            cho.close();
            System.out.println("Download cancelled");
         } 
    }
}
