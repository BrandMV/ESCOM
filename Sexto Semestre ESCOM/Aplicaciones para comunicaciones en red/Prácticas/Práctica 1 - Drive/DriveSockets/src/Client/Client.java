/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Client;

import Server.Server;
import static Server.Server.ANSI_GREEN;
import static Server.Server.ANSI_RESET;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.ArrayList;
import java.util.zip.ZipEntry;
import java.util.zip.ZipOutputStream;
import javax.swing.JFileChooser;


/**
 *
 * @author BrandMV
 */
public class Client {
    private Integer pto;
    private String dir;
    String serverPath = "C:\\Users\\PC\\Desktop\\6to Semestre ESCOM\\Aplicaciones para comunicaciones en red\\Prácticas\\Práctica 1 - Drive\\DriveSockets\\ServerFiles";
    String clientPath = "C:\\Users\\PC\\Desktop\\6to Semestre ESCOM\\Aplicaciones para comunicaciones en red\\Prácticas\\Práctica 1 - Drive\\DriveSockets\\ClientFiles";
    Socket client;
    
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
//    Socket s, cop = null;
    
    public Client(Integer pto, String dir){
        this.pto = pto;
        this.dir = dir;
    }
    
    /*@brief Method that opens the client file chooser
     *@param (Boolean) op Indicates if we want to send or download a file
     *@return
    */
    public void chooser(Boolean op) throws FileNotFoundException, IOException{
        //*Creating client folder
        File f = new File("");
        String path = f.getAbsolutePath();
        String folder = "ClientFiles";
        String files_path = path + "\\" + folder + "\\";
        System.out.println("Client folder path: " + files_path);
        File f2 = new File(files_path);
        f2.mkdirs();
        f2.setWritable(true);

        //*If op is true means we want to send a file to the server
        if(op){
            System.out.println("Connection stablished");
            JFileChooser jf = new JFileChooser();
            if(!op) jf.setCurrentDirectory(new File(serverPath));
            jf.setMultiSelectionEnabled(true);
            jf.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);

            int r = jf.showOpenDialog(null);
            jf.setRequestFocusEnabled(true);

            if(r == JFileChooser.APPROVE_OPTION){
                File[] files = jf.getSelectedFiles();
                sendFiles(files, "", false);
            }
        }else{
            Socket cop = new Socket(dir, pto+1000);
            DataOutputStream dcop = new DataOutputStream(cop.getOutputStream());
            //*Sending op
            dcop.writeInt(0);
            dcop.flush();
            dcop.close();
            cop.close();

            //*Reading if download is cancelled
            cop = new Socket(dir, pto+1000);
            DataInputStream dis = new DataInputStream(cop.getInputStream());
            Integer isCancelled = dis.readInt();
            dis.close();
            cop.close();

            //*Verifying if download is cancelled or not
            if(isCancelled == 1){
              return;
            }else{
                for(;;){
                    client = new Socket(dir, pto+1000);
                    dis = new DataInputStream(client.getInputStream());
                    Integer fi = dis.readInt();
                    //*If data has been downloaded we exit
                    if(fi == 1){
                        break;
                    }

                    dis.close();
                    client.close();
                    
                    //*Reading file to download info
                    client  = new Socket(dir, pto); 
                    dis = new DataInputStream(client.getInputStream());
                    String name = dis.readUTF();
                    long size = dis.readLong();
                    boolean directory = dis.readBoolean();
                    downloadFiles(files_path, dis, size, name, directory); 
                }   

             }
        }
    }
    
    /*@brief Method that sends file to the server using sockets
     *@param {File []} currentFiles The files array that will be sent to the server
     *@param {String} directoryName The destiantion folder name in case we wanna send a folder
     *@param {Boolean} directory Wether if the file is a folder or not
     *@return
    */
    public void sendFiles(File [] currentFiles, String directoryName, boolean directory){
        try {
            //*Indicating the port and socket direction
            int pto = 8000;
            String dir = "127.0.0.1";
            
            //*We go trough the files to verify if they're folder or file 
            for(File fileToSend : currentFiles){
                if(fileToSend.isDirectory()){
                    directoryName += directory ? "/" : ""; 
                    sendFiles(fileToSend.listFiles(), directoryName+fileToSend.getName(), true);
                }else{
                    Socket cl = new Socket(dir, pto);
            
                    DataOutputStream dos = new DataOutputStream(cl.getOutputStream());
                    String currentName = directory ? directoryName + "/" + fileToSend.getName() : fileToSend.getName();
                    String currentPath = fileToSend.getAbsolutePath();
                    long currentSize = fileToSend.length();

                    System.out.println("Sending file " + currentName + " with size " + currentSize + " bytes");

                    DataInputStream dis = new DataInputStream(new FileInputStream(currentPath));

                  //*Sending op
                    Socket cop = new Socket(dir, pto+1000); //*pto 8000+1000
                    DataOutputStream dcop = new DataOutputStream(cop.getOutputStream());
                    dcop.writeInt(1);
                    dcop.flush();
                    dcop.close();
                    cop.close();
                    
                    //*Filo info
                    dos.writeUTF(currentName);
                    dos.flush();
                    dos.writeLong(currentSize);
                    dos.flush();
                    dos.writeBoolean(directory);
                    dos.flush();

                    //*Sending file proccess
                    long currentSent = 0;
                    Integer l = 0, currentPercentage = 0;

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

                    System.out.println(ANSI_PURPLE + currentName + " sent");
                    dos.close();
                    dis.close();
                    cl.close();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
        
    /*@brief Method that download files from the server folder
     *@param {String} dest The destination folder
     *@param {DataInputStream} dis The DataInputStream to read info
     *@param {long} size the file size
     *@param {String} name The file name
     *@param {Boolean} directory Wheter if the file is a folder or not
     *@return
    */
    public void downloadFiles(String dest, DataInputStream dis, long size, String name, Boolean directory){
           try {
               //*Verifying if the file is a directory
                File newFile = new File(dest+name);          
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

                //*Downloading file proccess
                System.out.println("Downloading " + name + " " + size);

                while(receivedData < size){
                    byte[] b = new byte[1500];
                    l = dis.read(b);
                    System.out.println("Read: " + l);
                    dos.write(b,0,l);
                    dos.flush();
                    receivedData = receivedData + l;
                    percentage = (int)((receivedData*100) / size);
                    System.out.println(ANSI_GREEN + "Downloading data; " + percentage + "%" + ANSI_RESET);
                }//*While end

                System.err.println("Data downloaded" + name);
                dis.close();      
                dos.close();
                client.close();
            } catch (Exception e) {
                    e.printStackTrace();
              }
    }
}
