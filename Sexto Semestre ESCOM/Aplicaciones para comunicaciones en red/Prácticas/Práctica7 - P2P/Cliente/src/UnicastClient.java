import constants.Constants;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.Socket;

import static javax.swing.JOptionPane.showMessageDialog;

/**
 * Stream client that ask for a file to the server
 */
public class UnicastClient extends Thread{
    private App app;
    private Socket cl;
    private final Files db;

    public UnicastClient(Files db, App app){
        this.app = app;
        this.db = db;
    }

    /**
     * Method that connect to the local server
     */
    public void serverConnection(){
        try {
            cl = new Socket(db.getFileInServer(), Constants.UNICAST_PORT);
            System.out.println(Constants.CLIENT_CONNECTED);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    /**
     * Method that download the specified file
     */
    public void receiveFile(){
        if(cl != null){
            try {
                DataOutputStream dos = new DataOutputStream(cl.getOutputStream());
                //*Sending file we wanna download
                dos.writeUTF(db.getFoundFile().getPath());
                dos.flush();
                /**Waiting for the response*/
                DataInputStream dis = new DataInputStream(cl.getInputStream());
                /**Receiving file*/
                String name = dis.readUTF();
                long tam = dis.readLong();
                DataOutputStream dosFile = new DataOutputStream(new FileOutputStream(String.format(Constants.FILES_PATH,name)));
                byte []b = new byte[Constants.FILE_BUFFER_SIZE];
                long received = 0;
                int percentage = 0;
                int n = 0;
                while(received < tam){
                    n = dis.read(b);
                    dosFile.write(b, 0, n);
                    dosFile.flush();
                    received += n;
                    percentage = (int)((received*100) / tam);
                    app.setProgressBar(percentage);
                }
                dos.close();
                dosFile.close();
                dis.close();
                cl.close();
                showMessageDialog(null, Constants.FILE_RECEIVED_SUCCESSFULLY);
                app.setProgressBar(0);
                app.reset();
                
            }catch (IOException e){
                e.printStackTrace();
            }
        }
    }

    public void run(){}
}
